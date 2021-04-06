#include <iostream>
#include <chrono>

int main(int argc, char** argv)
{
    int time0 = std::chrono::system_clock::now().time_since_epoch().count();

    std::cout << time0 << std::endl;

    return 0;
}