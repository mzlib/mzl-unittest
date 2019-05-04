#include "../include/Test.hpp"

void mzl::unittest::Test::
addTests(const std::vector<std::function<bool()>> &tests) {
    this->tests = tests;
}

void mzl::unittest::Test::
run() {
    unsigned int passedTests = 0;
    double elapsedTime = 0.0;
    for (auto test : this->tests) {
        clock_t start = clock();
        const bool passed = test();
        clock_t end = clock();

        double elapsedTime1 = (double)(end - start)/CLOCKS_PER_SEC;

        passedTests += passed;

        if (passed) {
            std::cout << "    TEST PASSED in " << elapsedTime1 << " s\n";
        } else {
            std::cout << "[!] TEST FAILED in " << elapsedTime1 << " s\n";
        }

        elapsedTime += elapsedTime1;
    }

    std::cout << "---------------------------\n";
    std::cout << passedTests << "/" << this->tests.size() << " test";
    if (passedTests != 1) {
        std::cout << "s";
    }
    std::cout << " passed in " << elapsedTime << " s\n";
    std::cout << "---------------------------\n";
}