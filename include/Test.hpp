#ifndef MZL_UNITTEST_TEST_HPP
#define MZL_UNITTEST_TEST_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <ctime>

namespace mzl::unittest {
    class Test {
    private:
        std::vector<std::function<bool()>> tests;
    public:
        void addTests(const std::vector<std::function<bool()>> &tests);
        void run();
    };
}

#endif // MZL_UNITTEST_TEST_HPP
