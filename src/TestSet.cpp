#include "../include/TestSet.hpp"

void mzl::unittest::TestSet::
addTest(const std::string &testName, const std::function<void()> &func) {
    Test test(testName, func);
    this->tests.push_back(test);
}

void mzl::unittest::TestSet::
run() {
    unsigned int maxTestNameLength = 0;
    unsigned int passedTests = 0;
    double elapsedTime = 0.0;

    for (Test test : this->tests) {
        if (test.getName().length() > maxTestNameLength) {
            maxTestNameLength = test.getName().length();
        }
    }

    std::cout << "---------------------------\n";
    for (auto test : this->tests) {
        clock_t start = clock();

        try {
            test.run();
            clock_t end = clock();
            double elapsedTime1 = (double)(end - start)/CLOCKS_PER_SEC;
            elapsedTime += elapsedTime1;
            passedTests++;
            std::cout << std::left << std::setw(maxTestNameLength) 
                      << test.getName()
                      << " ::     TEST PASSED in " << elapsedTime1 << " s\n";
            std::cout << "---------------------------\n";
        } catch (AssertionException exception) {
            clock_t end = clock();
            double elapsedTime1 = (double)(end - start)/CLOCKS_PER_SEC;
            elapsedTime += elapsedTime1;
            std::cout << std::left << std::setw(maxTestNameLength)
                      << test.getName()
                      << " :: [!] TEST FAILED in " << elapsedTime1 << " s\n";
            std::cout << exception.what() << std::endl;
            std::cout << "---------------------------\n";
        }
    }

    std::cout << passedTests << "/" << this->tests.size() << " test";
    if (passedTests != 1) {
        std::cout << "s";
    }
    std::cout << " passed in " << elapsedTime << " s\n";
    std::cout << "---------------------------\n";
}