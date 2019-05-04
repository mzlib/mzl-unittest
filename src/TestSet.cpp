#include "../include/TestSet.hpp"

void mzl::unittest::TestSet::
<<<<<<< HEAD
addTest(const std::string &testName, const std::function<bool()> &func) {
    mzl::unittest::Test test(testName, func);
=======
addTest(const std::string &testName, const std::function<void()> &func) {
    Test test(testName, func);
>>>>>>> asserts
    this->tests.push_back(test);
}

void mzl::unittest::TestSet::
run() {
    unsigned int maxTestNameLength = 0;
    unsigned int passedTests = 0;
    double elapsedTime = 0.0;

<<<<<<< HEAD
    for (auto test : this->tests) {
=======
    for (Test test : this->tests) {
>>>>>>> asserts
        if (test.getName().length() > maxTestNameLength) {
            maxTestNameLength = test.getName().length();
        }
    }

<<<<<<< HEAD
    for (auto test : this->tests) {
        clock_t start = clock();
        const bool passed = test.run();
        clock_t end = clock();

        double elapsedTime1 = (double)(end - start)/CLOCKS_PER_SEC;

        passedTests += passed;

        if (passed) {
            std::cout << std::left << std::setw(maxTestNameLength) 
                      << test.getName()
                      << " ::     TEST PASSED in " << elapsedTime1 << " s\n";
        } else {
            std::cout << std::left << std::setw(maxTestNameLength)
                      << test.getName()
                      << " :: [!] TEST FAILED in " << elapsedTime1 << " s\n";
        }

        elapsedTime += elapsedTime1;
    }

    std::cout << "---------------------------\n";
=======
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

>>>>>>> asserts
    std::cout << passedTests << "/" << this->tests.size() << " test";
    if (passedTests != 1) {
        std::cout << "s";
    }
    std::cout << " passed in " << elapsedTime << " s\n";
    std::cout << "---------------------------\n";
}