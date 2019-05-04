#ifndef MZL_UNITTEST_TESTSET_HPP
#define MZL_UNITTEST_TESTSET_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <ctime>
#include <iomanip>
#include "Test.hpp"
#include "AssertionException.hpp"

namespace mzl::unittest {
    class TestSet {
    private:
        std::vector<Test> tests;
    public:
        void addTest(const std::string& testName, 
                     const std::function<void()> &tests);
        void run();
    };
}

#endif // MZL_UNITTEST_TESTSET_HPP
