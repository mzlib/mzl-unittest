#include "../include/TestSet.hpp"

void mzl::unittest::TestSet::
addTest(const std::string &testName, const std::function<bool()> &func) {
    mzl::unittest::Test test(testName, func);
    this->tests.push_back(test);
}

void mzl::unittest::TestSet::
run() {
    unsigned int passedTests = 0;
    double elapsedTime = 0.0;

    for (auto test : this->tests) {
        clock_t start = clock();
        const bool passed = test.run();
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