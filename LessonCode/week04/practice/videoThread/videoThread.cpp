#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::mutex print_mutex;
std::condition_variable cv;
int videoData = 0;

void safe_print(const std::string& msg)
{
    std::lock_guard<std::mutex> guard(print_mutex);
    std::cout << msg << std::endl;
}

void downloadVideo() 
{
    while (true) 
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [] { return videoData == 0; });
        std::cout << "Downloading..." << std::endl;
        // 模拟下载过程
        std::this_thread::sleep_for(std::chrono::seconds(1));

        while (videoData < 100)
        {
            std::cout << "videoDate: " << videoData+1 << std::endl;
            videoData++;
        }

        lck.unlock();
        cv.notify_all();
    }
}

void playVideo() 
{
    while (true) 
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [] { return videoData >= 50; });
        std::cout << "Playing..." << std::endl;
        
        videoData -= 50;
        std::cout << "Played. videoData: " << videoData << std::endl;
        lck.unlock();
        cv.notify_all();
    }
}

int main() 
{
    std::thread t1(downloadVideo);
    std::thread t2(playVideo);

    t1.join();
    t2.join();

    return 0;
}