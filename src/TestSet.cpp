#include "../include/TestSet.hpp"

void mzl::unittest::TestSet::
addTest(const std::string &testName, const std::function<void()> &func) {
    Test test(testName, func);
    this->tests.push_back(test);
}

bool mzl::unittest::TestSet::
run() const {
    unsigned int maxTestNameLength = 0;
    unsigned int passedTests = 0;
    double elapsedTime = 0.0;

    for (Test test : this->tests) {
        if (test.getName().length() > maxTestNameLength) {
            maxTestNameLength = test.getName().length();
        }
    }

    for (int i = 0; i < maxTestNameLength + 32; i++) {
        std::cout << "-";
    }
    std::cout << "\n";

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
                      << " ::     TEST PASSED in " << std::setprecision(4)
                      << std::fixed << elapsedTime1 << " s\n";
        } catch (AssertionException exception) {
            clock_t end = clock();
            double elapsedTime1 = (double)(end - start)/CLOCKS_PER_SEC;
            elapsedTime += elapsedTime1;
            
            for (int i = 0; i < maxTestNameLength + 32; i++) {
                std::cout << "<";
            }
            std::cout << "\n";

            std::cout << std::left << std::setw(maxTestNameLength)
                      << test.getName()
                      << " :: [!] TEST FAILED in " << std::setprecision(4)
                      << std::fixed << elapsedTime1 << " s\n";
            std::cout << exception.what() << std::endl;
            
            for (int i = 0; i < maxTestNameLength + 32; i++) {
                std::cout << ">";
            }
            std::cout << "\n";
        }
    }

    for (int i = 0; i < maxTestNameLength + 32; i++) {
        std::cout << "-";
    }
    std::cout << "\n";

    std::cout << passedTests << "/" << this->tests.size() << " test";
    if (passedTests != 1) {
        std::cout << "s";
    }
    std::cout << " passed in " << elapsedTime << " s\n";
    for (int i = 0; i < maxTestNameLength + 32; i++) {
        std::cout << "-";
    }
    std::cout << "\n";

    return passedTests == this->tests.size();
}