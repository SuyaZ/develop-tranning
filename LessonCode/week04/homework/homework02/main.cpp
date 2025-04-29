#include"AcAutomation.h"
#include"threadpool3.cpp"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include <chrono>
#include<windows.h>

//cerr相比于cout更加及时


//任务打包函数
//返回值是 <keyword, keyword在某个文件块中的相对行号>   --不要忘记转换成绝对行号
std::unordered_map<std::string, std::vector<long long>>
TaskPack(const char* const ptr, const size_t bufferSize, const AcAutomation& acTop)
{
    AcAutomation ac(acTop); //浅拷贝
    
    //调用AC自动机 并直接返回结果
    return ac.AcSearch(ptr, bufferSize);
}






int main()
{
	//首先准备keyword文件，先初始化AC自动机中的Tire树
    std::ifstream filekeyword("./keyword.txt");
    if (!filekeyword)
    {
        std::cerr << "ERROR Opening the file." << std::endl;
        std::cerr << "Stream state: " << std::hex << filekeyword.rdstate() << std::endl;
        return 1;
    }
    std::vector<std::string> keys;
    std::string line;
    while (std::getline(filekeyword, line))
    {
        keys.push_back(line);
    }

    filekeyword.close();

    //获取关键字之后就可以创建AC自动机了，避免自动机中的Tire树重复构建
    //之后所有的AC自动机都将浅拷贝这一份数据
    AcAutomation acTop;
    acTop.AcInit(keys);

    //创建一个具有*个线程的线程池
    ThreadPool pool(2);
    pool.init();

    //每一个线程的返回值都存储在vector当中
    //隐式的记录里面的每一个任务的index, 计算绝对路径可以使用
    std::vector< std::future< std::unordered_map<std::string, std::vector<long long>> > > results;

    //首先初始化文件路径，直接写会导致路径不匹配
    //LPCWSTR widePath = L"testin_min.txt"; //字符匹配不兼容的话就使用宽字符串
    //LPCWSTR widePath = L"testbug.txt";
    //LPCWSTR widePath = L"testXML.txt"; 
    LPCWSTR widePath = L"input.xml"; 

    //将要读取的文件进行内存映射
    HANDLE hFile = CreateFile(
        widePath,                  // 文件路径
        GENERIC_READ,              // 只读权限
        FILE_SHARE_READ,           // 允许其他进程读取
        NULL,                      // 默认安全属性
        OPEN_EXISTING,             // 打开现有文件
        FILE_ATTRIBUTE_NORMAL,     // 正常文件属性
        NULL                       // 没有模板文件
    );

    if (hFile == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Can not open the file {testiin2.txt}." << std::endl;
        return 1;
    }

    // 获取文件大小 fileSize.QuadPart
    LARGE_INTEGER fileSize;
    GetFileSizeEx(hFile, &fileSize);

    // 创建文件映射
    HANDLE hMapFile = CreateFileMapping(
        hFile,
        NULL,
        PAGE_READONLY,
        0,
        0,
        NULL
    );

    //创建文件映射不成功
    if (hMapFile == NULL)
    {
        std::cerr << "Can not Create Mapping." << std::endl;
        CloseHandle(hFile);
        return 1;
    }

    // 映射文件 得到指向文件开头的指针lpBase
    LPVOID lpBase = MapViewOfFile(
        hMapFile,
        FILE_MAP_READ,
        0,
        0,
        0 // 映射偏移量，为0表示整个文件
    );

    if (lpBase == NULL)
    {
        std::cerr << "Can not Mapping the file {testin3.txt}." << std::endl;
        CloseHandle(hMapFile);
        CloseHandle(hFile);
        return 1;
    }

    // 现在，lpBase指向了映射的内存区域，可以像操作内存一样操作文件内容
    char* ptr = static_cast<char*>(lpBase);

    const size_t bufferSize = 1024 * 1024 * 64; //每次处理的数据大小
    int n = 0; //控制指针的偏移量，ptr + n * 



    // 开始计时
    auto start = std::chrono::high_resolution_clock::now();


    //打包任务
    //每次传递的参数只是一个指针和文件块的大小，还有公共的acTop
    while (true)
    {
        if ((n + 1) * bufferSize > fileSize.QuadPart) //文件末尾的块的大小不足bufferSize
        {
            results.push_back(pool.submit(TaskPack, (ptr + n * bufferSize),         //读取文件操作的起始指针
                                                    (fileSize.QuadPart - n * bufferSize),   //文件块的大小
                                                     acTop));

            break;  //提交完最后一个任务

        }
        else
        {
            results.push_back(pool.submit(TaskPack, (ptr + n * bufferSize),         //读取文件操作的起始指针
                                                     bufferSize,   //文件块的大小
                                                     acTop));
        }
        n++;
    }



    //动态的检查和处理已经完成的任务
    int completed = 0; //记录已经完成的数量

    const int THREADNUMBER = results.size();
    //建立一个总表，获取所有线程返回的结果
    std::vector< std::unordered_map<std::string, std::vector<long long>> > ans(THREADNUMBER);

    for (int i = 0; i < results.size(); i++)
    {
        ans[i] = results[i].get();//存储第i个任务返回的结果
    }


    //处理返回的结果
    // 用于存储每个关键字的总个数
    std::unordered_map<std::string, int> keywordCounts;
    for (const auto& key : keys) 
    {
        keywordCounts[key] = 0;
    }

    // 遍历ans中的每个unordered_map
    for (const auto& map : ans) 
    {
        // 遍历所有可能的关键字
        for (const auto& kv : keywordCounts) 
        {
            const std::string& keyword = kv.first;
            // 检查当前关键字是否在map中，如果在则累加
            if (map.find(keyword) != map.end()) 
            {
                keywordCounts[keyword] += map.at(keyword).size();
            }
        }
    }


    //边界处理
    for (int i = 1; i < results.size(); i++)
    {
        const char* sp = ptr + bufferSize * i;
        const char c = (*sp); //边界处，后一个文件块的第一个字符
        
        //模式串没有换行符，匹配的时候要忽略主串的换行符
        for (const auto& key : keys)
        {
            size_t pos = 0;
            int cntline = 0;

            while (pos >= 0 && pos < key.size())
            {
                bool lflag = true, rflag = true; //每一次开始新的匹配的时候都默认为true
                int mainl = 1, mainr = 1; //主串偏移量
                int modl = 1, modr = 1; //模式串偏移量

                cntline = 0;

                pos = key.find(c, pos + 1); //返回字符 c 在字符串 key 中pos之后出现的索引位置
                //pos这个位置不能是模式串的首位，否则不符合跨界的条件，所以从下标1开始查找

                if (pos == std::string::npos) //没有在模式串中找到这个字符
                {
                    break; //该模式串无论如何也不会在边界处出现，继续查找下一个模式串
                }

                while (pos - modl >= 0)
                {

                    if (*(sp - mainl) == '\n')
                    {
                        mainl++;
                        continue;
                    }

                    if (key[pos - modl] != *(sp - mainl))
                    {
                        lflag = false;
                        break;
                    }

                    if (pos - modl == 0) break;

                    modl++, mainl++;
                }

                if (lflag == false) continue;

                while (pos + modr < key.size())
                {
                    if (*(sp + mainr) == '\n')
                    {
                        mainr++;
                        cntline++;
                        continue;
                    }

                    if (key[pos + modr] != *(sp + mainr))
                    {
                        rflag = false;
                        break;
                    }

                    if (pos + modr == key.size()) break;

                    modr++, mainr++;
                }

                if (rflag == false) continue;

                if (lflag && rflag) //边界处找到一个匹配
                {
                    //添加数据
                    keywordCounts[key]++;  //数量加1

                    //存储相对位置
                    ans[i].at(key).push_back(cntline);

                }

                //如果没有找到，就继续查找，直到越界，什么也不做

            }

        }

    }

    // 结束计时
    auto end = std::chrono::high_resolution_clock::now();

    // 计算持续时间
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // 输出结果
    std::cout << "Costs: " << duration.count() << " ms" << std::endl;


    // 输出每个关键字的总个数
    for (const auto& kv : keywordCounts) 
    {
        std::cout << "Keyword: " << kv.first << " ,         Total count: " << kv.second << std::endl;
    }


    char op;
    //询问用户是否输出行号到文件output.txt
    std::cout << "\nDo you want to save the line numbers to the file 'output2.txt'? [Y/N]" << std::endl;
    std::cin >> op;
    switch (op)
    {
    case 'N': std::cout << "Thank you!" << std::endl; break;
    case 'Y':
    {
        //相对行号转换成绝对行号并输出
        size_t Updatelines = 1; //第一块存储的时候也是0开始的，所以整体都要加上1
        std::unordered_map<std::string, std::vector<size_t>> lineNumber;

        for (const auto& map : ans)
        {
            for (const auto& key : map)
            {
                //更新
                if (key.first != "__MAX__LINES__")
                {
                    for (auto& v : key.second)
                    {
                        lineNumber[key.first].push_back(v + Updatelines);
                    }
                }
            }
            auto it = map.find("__MAX__LINES__");
            if (it != map.end()) 
            {
                Updatelines += it->second.at(0);
            }

        }

        // 创建一个ofstream对象，用于写入文件
        // 以追加模式打开文件
        std::ofstream outFile("output2.txt", std::ios::app);

        // 检查文件是否成功打开
        if (!outFile.is_open()) 
        {
            std::cerr << "Failed to open output.txt for writing." << std::endl;
            return 1;
        }

        std::cout << "Please wait for a second......" << std::endl;


        // 遍历unordered_map并写入文件
        for (const auto& pair : lineNumber) 
        {
            const std::string& key = pair.first;
            const std::vector<size_t>& values = pair.second;

            // 写入键（行号标识）
            outFile <<"keyword: " << key << std::endl;

            // 遍历并写入每个行号
            for (long long num : values) 
            {
                outFile <<"line " << num << "\n";
            }
            outFile << std::endl; // 每个键后面的行号写入完毕后换行
        }

        // 关闭文件
        outFile.close();

        std::cout << "The file has been WRITTEN DOWN!" << std::endl;


        break;
    }
    default: std::cout << "INPUT ERROR!" << std::endl; break;
    }


    // 解除映射
    UnmapViewOfFile(lpBase);
    CloseHandle(hMapFile);
    CloseHandle(hFile);


    pool.shutdown();


	return 0;
}