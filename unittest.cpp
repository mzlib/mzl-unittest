#include "include/Test.hpp"
#include <functional>
#include <vector>

int main() {
    std::function<bool()> testA = [](){ for(int i = 0; i < 10000000; i++); return true; };
    std::function<bool()> testB = [](){ for(int i = 0; i < 15435434; i++);return false; };
    std::function<bool()> testC = [](){ for(int i = 0; i < 23243223; i++);return true; };

    mzl::unittest::Test test;
    test.addTests(std::vector<std::function<bool()>> ({
        testA, testB, testC
    }));

    test.run();

    return 0;
}