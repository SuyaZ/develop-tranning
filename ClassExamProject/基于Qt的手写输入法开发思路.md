# 基于Qt的手写输入法开发思路

**前言**：

我的项目从UI到功能设计都是敲代码敲出来的，那为什么不用设计师去设计界面呢？

主要是因为我开始写的时间比较早吧，第一次Qt课结束的时候，我就开始自学Qt里面的基础知识了。我找的那本参考书，里面的例子都是代码敲出来的，关于UI设计的部分还没来得及学，但是我想也快期末考试了，边学边写边找资料吧，免得最后事情都堆在一起，然后就开始敲代码去构建UI界面了。

所以，可能代码和思路都比较幼稚，我也不知道专业的UI会怎么去设计，我只是有一个大概的思路，然后一边做一边思考，整个过程下来，我还是学到了很多也收获了很多的。

关于设计师的使用，之后也会专门去系统学一学的。

#  整个项目框架

总体分为两个部分：
1. UI界面的构建
2. 识别算法

最开始，我拿到这个项目是非常懵圈的，识别算法应该已经属于深度学习的范畴了，我要在这么短的时间里面构建出一个模型出来，而且还不能保证识别率，我毫无头绪。后来我就去上网到处搜罗资料，对于文字识别的基本上就两个方向：
1. 基于openCV的深度识别模型，需要自己训练
2. 使用windows Tablet PC SDK 提供的接口

第一个显然超出了我的能力范围，我就去找第二个的资料，但是很可惜，除了官方文档，几乎找不到什么通俗易懂的资料。而且既然要使用 windows 的接口，那就说明我的代码只能在windows上面跑，万一老师用的Mac怎么办？

就在我感觉走投无路的时候，老师在群里说了可以使用win的API，这让我突然一下就不纠结了。这个时候，我正好看了有一篇七八年前的帖子，讲了他自己是怎么调用接口的，好歹也有参考价值，就开始硬着头皮写了。

# 代码框架解析

以下是我的代码的整体框架：
![](https://oss-liuchengtu.hudunsoft.com/userimg/be/bea64d102fbf4b50c9b0f38ee6484879.png)

## 主窗口的设计

主窗口的设计也碰到了一些弯弯绕绕的事情。我的思路就是先准备好需要用的所有组件啊，容器啊，布局呀之类的控件，然后再通过布局管理器在主窗口上进行布局。
最开始所有的事情全部是在构造函数里面执行的，该写的不该写的全部在构造函数里面。头文件里面就一个空的声明，连成员变量都不在头文件里面，直接在构造函数的时候加入到布局里面。
后来想要继续实现功能的时候就遇到大麻烦了，在除了构造函数之外的成员函数想要直接用主窗口的控件的时候，直接用不了，得用findchild或者findChildren在布局或者容器里面一个一个找，太麻烦了，而且我不止要找一次，这样会严重影响程序的执行效率。
怎么解决呢，当然是把所有控件都在头文件里面作为成员变量直接定义，但是我暂时不分配空间，只是分配空指针。然后又重构了主窗口的代码。这样一来，控件就不仅仅只是在布局中存在了，直接通过成员变量的指针，就能够直接访问了。
但是new出来的空间如果析构的时候没有正确处理会导致内存泄漏，那么究竟应该怎么安排析构函数呢。我看的参考书上面这样说：
![](https://oss-liuchengtu.hudunsoft.com/userimg/7b/7b2676e841aecff7a081f3493e48bc2d.jpg)
也就是说布局中的控件自动成为布局的容器的子对象，这个对象树是自动构建的。那么按照对象树的特性，析构父对象的时候，会自动析构子对象，所以析构函数里面只需要delete一个中心容器就可以了，还有子窗口的指针也需要额外判断。所以析构函数的代码结构为：
```cpp
HandWirttingInput::~HandWirttingInput()
{
    if (chaListWindow != nullptr) //符号表子窗口已经正确创建
    {
        delete chaListWindow;
    }
    //......其余子窗口的判断同上

    delete centralWidget;
 //删除主窗口的中心部件
}
```

首先需要对主窗口构建一个合理的布局，我实现的布局如下：
![](https://oss-liuchengtu.hudunsoft.com/userimg/ae/ae88ae02bf9a16808996b96a67f003e3.png)
按照这个布局，首先需要创建一个容器（QWidget）指定为中心部件，如果不设置中心部件的话，即使在这个容器里面实现了布局，运行出来还是什么都没有。我就遇到了这个问题。
那么，需要的控件就一目了然了。
```cpp
private:
    //CharacterList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
    MapCharList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
    MapNumList* numListWindow = nullptr;
    MapEngList* engListWindow = nullptr;
    Setting* setting = nullptr;


    //准备页面布局的所欲需要用到的控件指针，本来是在构造函数里面处理的，但是总觉得这样不好直接访问，使用findchild()并不是一个很高效率的方法
    //所以先定义所有需要布局的，布局控制、容器、以及控件指针
    QWidget* centralWidget = nullptr; //中心部件的容器
    QGridLayout* centralplay = nullptr; //中心布局

    //顶部的文本编辑器 控件
    QTextEdit* textEdit = nullptr;

    //-------------- 左 ——————————————————
    QWidget* leftContainer = nullptr;
    QVBoxLayout* leftplay = nullptr;

    QPushButton* contrlBtn = nullptr;
    QPushButton* singleRecBtn = nullptr;
    QPushButton* multipRecBtn = nullptr;
    QPushButton* eraseBtn = nullptr;
    QPushButton* rewriteBtn = nullptr;

    //-------------- 中 ——————————————————
    QWidget* midContainer = nullptr;
    QVBoxLayout* midplay = nullptr;
    QLabel* writeZone = nullptr;

    //-------------- 右 ——————————————————
    //在MainWindow里面创建QWidget容器管理布局
    QWidget* rightContainer = nullptr;

    //网格布局
    QGridLayout* rightplay = nullptr;

    // 添加组件
    QPushButton* btn1 = nullptr; //识别之前默认候选栏都是空值
    QPushButton* btn2 = nullptr;
    QPushButton* btn3 = nullptr;
    QPushButton* btn4 = nullptr;
    QPushButton* btn5 = nullptr;

    QPushButton* charBtn = nullptr;
    QPushButton* numBtn = nullptr;
    QPushButton* EnBtn = nullptr;
    QPushButton* CnBtn = nullptr;
```

关于控件之间的布局和关系，就是构造函数里面要做的事了，如下图所示：
![](https://oss-liuchengtu.hudunsoft.com/userimg/da/dad71ddd86b0f9cf6eaab6d90da67735.png)

## 符号列表窗口设计

由于右下角这三个按钮的事件处理和实现思路基本一致，所以只拿第一个特殊符号列表为例子进行思路的阐述。
![](https://oss-liuchengtu.hudunsoft.com/userimg/46/46d94bc0b1f7cc32ff831ff754dd3539.png)

我希望按下这个按钮，会弹出一个窗口，这个窗口里面有很多个字符按钮，当我按下某一个按钮之后，这个弹窗会自动隐藏并将文本信息直接写入到主窗口的`TextEdit`当中。

于是，我需要设计一个单独的弹窗，封装在一个类`MapCharList`当中，这个类继承自QWidget。为什么不是Qdialog，其实我当时也是纠结了一会，感觉都可以的。
很明显这个类的中心容器就是它自己，不需要额外指定中心容器，然后我希望符号按钮是整齐排列的，所以必定是网格布局：
![](https://oss-liuchengtu.hudunsoft.com/userimg/a8/a8d08e89f58da551c0e4927e71c015ff.png)

再定义一个网格布局`charplay`。

这个时候就碰到了一个很典型的问题了，如上图，一共有`9*5`个功能相似的按钮，我是一个一个老老实实手动 new 几十个按钮然后再一个个添加到布局，然后再创建几十个信号和对应的槽函数呢，还是另外去寻找更为巧妙的方法去处理这样批量且重复的事件呢？

很显然我更愿意是后者，因为前者实在是太笨了，现在我只有几十个按钮可以手动添加，那如果有几千个几万个，还是得寻找新的方法去管理。

这个管理的方法，就是==使用QSignalMapper去批处理这样重复的组件==。

我去查看官方文档的时候，我发现它给的例子，对应上了我需要的代码逻辑。

需要预先设定好每一个按钮的文本信息，它会和按钮一起映射到Map当中，只要Map里面有一个按钮被点击了，Map就会自动发出信号，这个信号携带一个类型为`QString`的参数，这个参数的值就是被点击的按钮的文本。

对于每一个按钮，设定好Text属性之后，就要将每个按钮的 `clicked()` 信号连接到 `QSignalMapper` 的 `map()` 槽函数，这一步是必须的，如果不这么做，按钮点击的时候，Map及那个不会发出任何信号。
连接好之后才是添加按钮映射。
最后根据需要，再布局当中直接添加这个按钮的组件。
```cpp
//首先使用buttonTexts存储每一个按钮的文本信息
QStringList buttonTexts;
buttonTexts << "，" << "。" << "、" << "；" << "：" << "？" << "！" << "·" << "···"
			<< "——" << "~" << "‘’" << "“”" << "/" << "\\" << "_" << "··" << "--"
			<< "," << "." << "''" << "\"\"" << "?" << "!" << "`" << "+" << "-"
			<< "@" << "#" << "$" << "￥" << "^" << "&&" << "*" << "()" << "[]"
			<< "{}" << "<>" << "|" << "%" << ";" << "℃" << "⟪⟫" << "→" << "←";

//在当前QWidget里面添加网格布局管理器
charplay = new QGridLayout(this); //父布局是this

//创建Map 
signalMapper = new QSignalMapper(this);

for (int i = 0; i < buttonTexts.size(); i++)
{
	QPushButton* btn = new QPushButton(buttonTexts[i]);
	connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));  //将每个按钮的 clicked() 信号连接到 QSignalMapper 的 map() 槽函数
	signalMapper->setMapping(btn, buttonTexts[i]);
	charplay->addWidget(btn, i / 9, i % 9, 1, 1);
}
```
这个方法真的非常巧妙了，让代码的逻辑更加优美简洁，并且让信号处理变得更加简单清晰。

现在，假设点击了某个按钮，Map发出了信号，这个信号交由谁去处理？主窗口能直接接收到这个信号吗？我觉得主窗口要直接操作Map信号的话，有点不太好，所以中间加了一道信号转发的链接。下面的代码当中，`this` 就是这个字符列表子窗口。
```cpp
//信号连接信号， 信号转发
connect(signalMapper, SIGNAL(mapped(const QString &)), this, SIGNAL(doclicked(const QString &)));
```
其中子窗口类定义里面有信号：
```cpp
signals:
	void doclicked(const QString& text);  //Map()发出信号之后，会转发信号到doclicked信号，携带一个按钮文本作为参数
```
现在，主窗口再处理`doclicked` 信号就可以了。

这个时候又出现了一个问题，就是信号与槽的链接时机。我在主窗口里面是分配了一个指针用来指向子窗口，但是最开始是空指针，是没有被实例化的：
```cpp
MapCharList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
```
什么时候被实例化呢，只有在我第一次点击`charBtn`的时候会被实例化，主窗口构造函数里面做了如下链接：
```cpp
QObject::connect(charBtn, &QPushButton::clicked, this, &HandWirttingInput::open_closeCharacterList);
```
而`open_closeCharacterList)`的定义结构如下：
```cpp
//处理字符按钮
void HandWirttingInput::open_closeCharacterList() //单击打开窗口，再次点击关闭窗口
{
    if (chaListWindow == nullptr)
    {
        chaListWindow = new MapCharList(this); //设置子窗口的父对象是this

        chaListWindow->show();
        //........添加其他处理逻辑
    }
    else
    {
        if (chaListWindow->isVisible()) 
        {
            chaListWindow->hide();  // 隐藏窗口
            //........添加其他处理逻辑
        }
        else 
        {
            chaListWindow->show();  // 显示窗口
            //........添加其他处理逻辑
        }
    }


}
```
只有按钮第一次被点击的时候会被实例化，在之后窗口会根据需要隐藏起来，如果某次运行不点击按钮，是永远都不会被实例化的。

那么现在就有两种选择，一种是在实例化完之后立马链接主窗口和子窗口的信号与槽，一种是在子窗口的构造函数里面。两种方法其实都可以，我选择后者。
`this`是子窗口对象。
```cpp
//子窗口和父窗口链接 
QObject::connect(this, SIGNAL(doclicked(const QString & )), this->parent(), SLOT(inputCharButton(QString)));
```
主窗口的槽函数结构如下，不使用append主要是因为他会自动换行，不符合输入习惯：
```cpp
//接收来自字符串窗口的信号，并处理
void HandWirttingInput::inputCharButton(const QString& btntext)
{
    //textEdit->append(btntext);  //每次选择一个字符之后，界面就会自动隐藏 append()会自动换行
    textEdit->insertPlainText(btntext);
    chaListWindow->hide();
    //.....添加其他逻辑
}
```
至此，符号表的设计逻辑就非常清晰了。
数字表和字母表是一样的思路，不做赘述。


## 识别器设计

解决这一个模块的时候真的找了很多参考资料，然后我发现用`c#`去调用win API的例子还是蛮多的，但是出现了很多概念，比如说什么是COM，什么叫做COM实例化，为什么需要COM。因为我在阅读微软的官方文档的时候，出现了这些概念，查了很多资料也没有一个让我很明白的解释，但是我的大概理解就是：使用一个接口的时候，首先需要实例化这个接口，但是这个接口要能够支持被各种语言调用，这个时候就需要COM。

API在哪里，怎么调用？我是一个超级小白，我最开始确实搞不明白这个东西，我以为win的API是需要自己下载SDK然后安装的，或者自己在网上找库。后来苦苦寻找，找到了这个组件的SDK下载的官网，诶，浏览器拦截了不让下载。关了病毒检测继续下，安装的时候报错版本不兼容，装不了。就在我以为要完蛋的时候，我注意到了官方文档中的那一句 “XX方法，标头`#include <msinkaut.h>`”，此时我的脑子里有一个大胆的想法，我去那个古老的SDK网站上瞄了一眼，发现他是支持win XP的，但是我的系统是win 11，已经更新迭代很多次了。我又想起上次大作业做字符串检索的时候，里面用到的"内存映射文件技术"就是包含了一个win的头文件，然后直接调用的接口，那是不是说明其实高版本的win系统已经集成了很多原来需要另外下载的SDK呢？为了验证这一想法，我直接在头文件里面加上了`#include <msinkaut.h>`，没有报错，编译通过，那么直接开始用里面的接口和方法就好了，就是操作系统自带的。真的，弯弯绕绕这么多，没想到这么简单，同时也感叹win操作系统真是强大。

好了，准备工作就绪，现在步入正题！
（参考了很多资料，会在最后放上对我帮助非常大的博客或者仓库链接，感谢互联网大佬们）

整体的识别器设计思路，大概就是：
1. 主窗口在构造出实例的时候，就要携带一个成员`inputs`，这个成员就是识别器类`HansInput`的实例.
2. 初始化`inputs`的时候，需要传入一个`HWND`的句柄，说的通俗一点，就是某个窗口或者控件的`winId`。很显然，只有指定了识别器的识别区域，它才知道要在哪里去收集、显示、识别墨迹。
3. 识别器识别函数的调用时机，为了更好的用户体验，我设计识别区域的组件响应鼠标左键的释放事件，每次写完一笔，就会调用识别器的识别方法，用户看来就做到了实时更新。
4. 结果的存储和显示，每次识别的结果，可能是单个的字符，也可能是多个的字符，所以自定义一个结构体用来存放每一次的识别结果。这个数据结构也是放在了主窗口里面，和识别器结合，共同管理结果。

既然要管理识别结果，就需要一个数据结构保存结果，所以就定义了以下结构体：
```cpp
struct InputRes
{
	char res[128]; //用于保存每一次识别的结果
};

typedef std::vector<InputRes> InPutResS; //保存候选项
```

遇到hi对于识别器，就有看了如下类定义：
```cpp
class HansInput : public QWidget
{
	Q_OBJECT

public:
	explicit HansInput(QWidget *parent = nullptr);  
	~HansInput();

	//定义接口指针 p_前缀表示指针 构造函数时去初始化
	IInkCollector* p_IInkCollector = nullptr; //墨迹收集和管理
	IInkDisp* p_IInkDisp = nullptr;  //墨迹显示
	IInkRecognizerContext* p_IInkRecognizerContext = nullptr;  //墨迹识别

	void inputInit(HWND hwnd);  //初始化接口等，需要传入一个ui组件的指针，来指定墨水收集和识别的区域
	void RecogData(InPutResS& Res); //墨迹识别
	void releaseUp();  //释放与墨迹输入相关的接口资源，清理COM
	void clear(); //清除所有笔划

	void clearNew(); //清除最新的一笔，回退一笔


signals:
	//发出信号，表示已经正确删除笔划集合并且更新了UI界面，希望main窗口能够再次调用一次识别函数，将结果反馈给用户
	void deleteLast();



private:
	Ui::HansInputClass ui;
};
```
成员变量和成员函数的职责在上面代码的注释里面都清晰地写出来了，关于信号与槽的链接后面会细讲。

主窗口里面先要将识别器初始化，这个是在构造函数里面完成的：
```cpp
//______________________ 识别器初始化 _________________________
WId hshow = writeZone->winId();
inputs.inputInit((HWND)hshow);
```
需要将控件的句柄作为参数传递到识别器初始化的函数里面。

`HRESULT` 是一个在 Windows 编程中广泛使用的类型，它表示函数调用的成功或失败状态。
```cpp
HRESULT hr;  //表示函数调用成功或者失败的状态
```
之后会大量使用这个变量来检查代码。

还需要初始化COM，对于为什么要执行下面这个代码，我也不清楚底层原理，我只知道，没有这句代码，后面就可能跑不通。
```cpp
hr = CoInitialize(nullptr);  //初始化COM接口  LPVOID == void*
if (FAILED(hr))
{
	qDebug() << "Failed to CoInitialize()";
	return;
}
```
贴上AI的解释和大佬们的解释，因为我自己解释不清楚。
![](https://oss-liuchengtu.hudunsoft.com/userimg/55/5597308770252e22b5f6536f6b0ee699.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/4c/4c17ed696839a71f579bdf9ecca61d1d.png)

接口这个东西要实例化才能用，所以还需要请求 COM 框架创建一个 IInkRecognizerContext 接口的实例，并返回该接口的指针。前四个参数是输入型参数`[in]`，最后是`[out]`，这个指针是识别器里面的成员变量，执行完这句之后，这个指针就指向了接口实例了，之后的操作中就可以正常调用接口中的方法：
```cpp
//使用默认识别器创建一个识别上下文
//这个上下文会被所有识别对象使用
//请求 COM 框架创建一个 IInkRecognizerContext 接口的实例，并返回该接口的指针
hr = CoCreateInstance(
	CLSID_InkRecognizerContext,     //唯一标识一个 COM 组件的类
	NULL,                           //指向 IUnknown 接口的指针  不需要聚合
	CLSCTX_INPROC_SERVER,           //对象将在进程内服务器中创建
	IID_IInkRecognizerContext,      //唯一标识一个 COM 接口
	(void**)&p_IInkRecognizerContext //返回创建好的实例的指针
);
if (FAILED(hr))
{
	qDebug() << "Failed to CoCreateInstance(CLSID_InkRecognizerContext)";
	return;
}
```
创建墨迹收集接口的实例的时候也是这样：
```cpp
//创建一个墨迹收集的对象
hr = CoCreateInstance(
	CLSID_InkCollector,
	NULL,
	CLSCTX_INPROC_SERVER,
	IID_IInkCollector,
	(void**) &p_IInkCollector
);

if (FAILED(hr))
{
	qDebug() << "Failed to CoCreateInstance(CLSID_InkCollector)";
	return;
}
```
完成接口实例化之后，接下来要做三件事情：
1. 获取墨迹对象的指针，保存在成员变量`p_IInkDisp`中。
2. 将书写区域的句柄关联到墨迹收集器中。
3. 打开墨迹输入开关。

具体代码如下：
```cpp
//获取墨迹对象指针
hr = p_IInkCollector->get_Ink(&p_IInkDisp);
if (FAILED(hr))
{
	qDebug() << "Failed to get_Ink(&p_IInkDisp)";
	return;
}

//将墨迹对象关联一个组件 hwnd
hr = p_IInkCollector->put_hWnd((long)hwnd);
if (FAILED(hr))
{
	qDebug() << "Failed to put_hWnd((long)hwnd)";
	return;
}

//打开墨迹输入开关
hr = p_IInkCollector->put_Enabled(VARIANT_TRUE);
if (FAILED(hr))
{
	qDebug() << "Failed to put_Enabled(VARIANT_TRUE)";
	return;
}
```
准备工作终于完成之后，接下来是识别器实现墨迹识别的核心：

墨迹笔划怎么去访问？ 如下，自定义一个指针去管理笔划集合：
```cpp
//获取指向墨迹收集器的指针，这个收集器是整个墨迹的快照
IInkStrokes* p_IInkStrokes = nullptr;
HRESULT hr = p_IInkDisp->get_Strokes(&p_IInkStrokes);  //可以通过p_IInkStrokes访问和操作墨迹笔划集合。
```
墨迹收集的工作需要这个笔划集合作为参数：
```cpp
hr = p_IInkRecognizerContext->putref_Strokes(p_IInkStrokes);  //设置识别上下文中将要进行识别的墨迹笔划集合
```
接下来就是最核心的墨迹识别代码了：
```cpp
//识别
IInkRecognitionResult* p_IInkRecoResult = nullptr;
InkRecognitionStatus RecognitionStatus = IRS_NoError;  //COM 接口，代表墨迹识别的状态

hr = p_IInkRecognizerContext->Recognize(&RecognitionStatus, &p_IInkRecoResult);  //识别器会返回结果 在形参列表里面引用返回
```
在候选项里面截取需要的部分加入到墨迹识别结果集当中：
```cpp
IInkRecognitionAlternates* p_IInkRecognitionAlternates;    //-s

hr = p_IInkRecoResult->AlternatesFromSelection(
				0,                                 //选择的起始索引  这里 0 表示从第一个候选词开始检索          in
				-1,                                //选择的结束索引  -1 通常用于指示直到列表末尾的最后一个候选词  in
				5,                                 //要检索的候选词的最大数量  即返回具有 5个候选词的结果        in
				&p_IInkRecognitionAlternates       //指向候选词集合                                         out
);
```
将获取的结果转成UTF8的编码格式存储在Res当中。
```cpp
//获取所有识别结果
IInkRecognitionAlternate* p_IInkRecognitionAlternate = nullptr;  

for (LONG iTem = 0; (iTem < lCount) && (iTem < 5); iTem++)
{
				if (SUCCEEDED(p_IInkRecognitionAlternates->Item(iTem, &p_IInkRecognitionAlternate)))
				{
					BSTR bstr = nullptr;

					if (SUCCEEDED(p_IInkRecognitionAlternate->get_String(&bstr)))
					{
						InputRes temp = { 0 };
						QString str = QString::fromWCharArray(bstr);

						qDebug() << str.toUtf8().data();

						strcpy_s(temp.res, str.toUtf8().data());
						Res.push_back(temp);
					}

					p_IInkRecognitionAlternate->Release();
				}
}
```
结果保存之后，一定要释放这个过程中 中间实例化的一些接口。
```cpp
p_IInkRecognitionAlternate->Release();
p_IInkStrokes->Release(); 
```
还要重置识别器的内容，为下次识别做准备：
```cpp
//重置识别器的内容
p_IInkRecognizerContext->putref_Strokes(nullptr);
```
每次识别完了之后，`p_IInkDisp `都是保存了数据的，如果不及时清空，会影响到下一次识别的结果。所以成员函数定义如下：
```cpp
void HansInput::clear() //清除所有笔划
{
	p_IInkDisp->DeleteStrokes(nullptr);
	qDebug() << "Delete Strokes";
}
```
接下来要完成第三步，也就是识别调用时机。想要在鼠标每次释放的时候，手写区域都会响应这个鼠标释放的事件，然后完成指定的操作。这个场景当中，不仅指定了控件，而且指定了事件。某个控件只响应某个事件，这不就是事件过滤器的使用场景吗。

所以，思路就是：
1. 主窗口重写一个事件过滤器，指定手写区域的控件响应鼠标释放事件。
2. 事件过滤器如果发现组件和事件都能匹配上，就发出一个自定义的信号，如下：
```cpp
signals:
    void MouseRelease();  //每一笔写完之后，通过事件过滤器发出信号
```
这个信号链接一个槽函数：
```cpp
//WriteZone响应鼠标释放事件
QObject::connect(this, &HandWirttingInput::MouseRelease, this, &HandWirttingInput::mouseReleaseEvent);
```
槽函数`mouseReleaseEvent`的定义如下，这样就做到了实时识别，并且会将每一次识别的结果都更新到候选按钮的显示文本当中：
```cpp
//每一个笔划的结束都会调用识别功能
void HandWirttingInput::mouseReleaseEvent()   //void MouseRlease()信号发出之后，会调用这个槽函数，然后在里面调用识别功能
{
    qDebug() << "mouseReleaseEvent connect.";

    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes);

    qDebug() << tempRes.size();

    btn1->setText(QString::fromUtf8(QByteArray(tempRes[0].res)));
    btn2->setText(QString::fromUtf8(QByteArray(tempRes[1].res)));
    btn3->setText(QString::fromUtf8(QByteArray(tempRes[2].res)));
    btn4->setText(QString::fromUtf8(QByteArray(tempRes[3].res)));
    btn5->setText(QString::fromUtf8(QByteArray(tempRes[4].res)));

}
```
我希望每个候选按钮点击的时候，都会将文本发送到TextEdit当中，也要进行槽函数的链接：
```cpp
//候选字按钮被按下
QObject::connect(btn1, &QPushButton::clicked, this, &HandWirttingInput::btn1Clicked);
```
槽函数定义如下：
```cpp
//按下候选词的按钮，输入文字到textEdit
void HandWirttingInput::btn1Clicked()
{
    qDebug() << "btn1Clicked";

    textEdit->insertPlainText(btn1->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
    
}
```
这个里面都对重写按钮的click()处理，所以我需要实现准备一个重写按钮被按下后的槽函数实现：
```cpp
//按下重写按钮
void HandWirttingInput::btnClearClicked()
{
    qDebug() << "btnClearClicked";

    textEdit->setFocus();
    inputs.clear();  //只是删除笔触，之后在析构的时候才会删除所有资源

    writeZone->clear();

    btn1->setText("");
    btn2->setText("");
    btn3->setText("");
    btn4->setText("");
    btn5->setText("");

    tempRes.clear();

}
```

至此，一个简单的墨迹识别器就设计完成了。


## “退一笔”功能设计

有了前面的设计经历，这个其实就是要对笔划集合做维护，在识别器里面定义一个方法，能够删除某个时刻笔划集合里面的最后一笔，但是需要注意一些细节。

第一步，获取笔划集合：
```cpp
//获取墨迹笔划集合
IInkStrokes* p_IInkStrokes = nullptr;
HRESULT hr = p_IInkDisp->get_Strokes(&p_IInkStrokes);  //out
```
第二步，获取笔划数量：
```cpp
//获取笔划数量
long count = 0;
p_IInkStrokes->get_Count(&count);
```
获取数量之后一定要特判一下，笔划的数量为0的时候就直接返回，不然再删除就会越界。
```cpp
hr = p_IInkDisp->DeleteStroke(p_lastStroke);   //删除最后一笔
```
到这里就完事了吗，不，能够执行到这一步说明确实删除了笔划，但是用户感受不到，因为UI界面没有更新，墨迹依然停留。所以，还有记得更行UI界面：
```cpp
//删除笔划集合之后，要保证能够更新到UI
LONG_PTR curHWND = 0;
hr = p_IInkCollector->get_hWnd(&curHWND);

if (SUCCEEDED(hr))
{
				HWND hwnd = reinterpret_cast<HWND>(curHWND);
				hr = InvalidateRect(hwnd, NULL, TRUE);
   //刷新手写区域

				if (FAILED(hr))
				{
					qDebug() << "InvalidateRect(hwnd, NULL, TRUE)";
					return;
				}

}
```
结束了吗？还没有，因为候选框的状态还没有更新，删除了一笔之后也要进行重新识别的，所以再加上：
```cpp
//重新识别信号
emit deleteLast();
```
这个信号发出，执行主窗口的槽函数：
```cpp
//更新识别
QObject::connect(&inputs, &HansInput::deleteLast, this, &HandWirttingInput::deltUpdate);
```
deltUpdate的定义如下：
```cpp
//HansInput发过来的信号，
void HandWirttingInput::deltUpdate()
{
    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes);

    qDebug() << tempRes.size();

    //删除最后一笔时，由于删除之后自动识别，此时画布上面什么也没有，那么结果数组temRes里面是没有任何元素的，于是访问元素下标时不合法的
    //下面的if做一个特判
    if (tempRes.size() >= 5)
    {
        btn1->setText(QString::fromUtf8(QByteArray(tempRes[0].res)));
        btn2->setText(QString::fromUtf8(QByteArray(tempRes[1].res)));
        btn3->setText(QString::fromUtf8(QByteArray(tempRes[2].res)));
        btn4->setText(QString::fromUtf8(QByteArray(tempRes[3].res)));
        btn5->setText(QString::fromUtf8(QByteArray(tempRes[4].res)));
    }
    else   //画布为空的时候
    {
        btn1->setText("");
        btn2->setText("");
        btn3->setText("");
        btn4->setText("");
        btn5->setText("");
    }

    qDebug() << "After Delete, the results has been UPDATE.";
}
```
一定要特别注意删除最后一笔的时候，画布为空，识别结果的数组自然也没有元素，所以再去用下标访问就会造成越界行为，所以要对返回的识别结果的数组长度做特判。

## 设置窗口

更改墨迹颜色，墨迹粗细以及候选字的样式，布局使用网格布局。
![](https://oss-liuchengtu.hudunsoft.com/userimg/be/bede4c473044ca6ccc71b9e577761f95.png)

需要管理墨迹，毫无疑问是需要API的，可以通过下面的代码，来获取墨迹的样式，然后修改。下面的代码的作用是将墨迹颜色改为红色：
```cpp
IInkDrawingAttributes* p;
HRESULT hr;
hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
```
修改墨迹宽度，只需要及那个下面代码的括号里面的参数修改一下，就可以了，其中30表示30px：
```cpp
p->put_Width(30);
```
修改按钮字号的时候，只需要：
```cpp
QFont font("宋体", 10);
btn1->setFont(font);
```
接下来就是信号与操的连接了，每一个按钮都对应立刻一个点击信号，这个信号发送到主窗口中，然后执行对应的槽函数：
```cpp
//修改颜色
QObject::connect(setting, &Setting::btnblackclicked, this, &HandWirttingInput::setBlack);
//......修改其他颜色

//修改宽度
QObject::connect(setting, &Setting::btn1clicked, this, &HandWirttingInput::setWidth1);
//......修改其他宽度

//修改字号
QObject::connect(setting, &Setting::btn10clicked, this, &HandWirttingInput::setSize1);
//......修改其他字号

//恢复默认设置
QObject::connect(setting, &Setting::reSetBtnclicked, this, &HandWirttingInput::reSet);
```

信号与槽的链接需要注意时机，只有在设置窗口被实例化之后的链接才是有效的。处理操作和前面的符号表窗口一样。


## 细节处理

细节处理主要是点击按钮的时侯，颜色会发生变化，更好的与用户进行交互，具体演示请看测试文档。

## 重叠识别和联想词

这个目前还没事件落实，要准备期末考试了，就一边准备期末考试一边找资料然后构思一下这两个扩功能怎么做吧。




# 参考资料

1.
[QT集成Windows手写输入法_win触控输入法集成到程序-CSDN博客](https://blog.csdn.net/oBoLuoChuiXue12/article/details/109632780?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-5-109632780-blog-103733342.235)

2.
[张利利/Windows手写输入法](https://gitee.com/ll.zhangll/windows_handwriting)

3.
[IInkRecognizerContext：：BackgroundRecognize (msinkaut.h) - Win32 apps | Microsoft Learn](https://learn.microsoft.com/zh-cn/windows/win32/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize)

4.
[Qt开发 | Qt界面布局 | 水平布局 | 竖直布局 | 栅格布局 | 分裂器布局 | setLayout使用 | 添加右键菜单 | 布局切换与布局删除重构_qt horizontallayout-CSDN博客](https://blog.csdn.net/zwcslj/article/details/139956054?ops_request_misc=%257B%2522request%255Fid%2522%253A%252229c9657c079dda521e67dcb2220a3369%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=29c9657c079dda521e67dcb2220a3369&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-139956054-null-null.142^v100^pc_search_result_base6&utm_term=Qt%E6%89%8B%E5%86%99%E4%BB%A3%E7%A0%81%E6%B7%BB%E5%8A%A0%E5%B8%83%E5%B1%80&spm=1018.2226.3001.4187)

5.
《Qt官方文档》

6.
《Qt5.10 GUI完全参考手册》2018-8-18(第一版) 黄勇著


# 更新记录

11.28 第一次提交 有联想词和重叠识别两个扩展功能尚未落实。






















