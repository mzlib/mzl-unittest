#ifndef MZL_UNITTEST_TESTSET_HPP
#define MZL_UNITTEST_TESTSET_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <ctime>
#include "Test.hpp"

namespace mzl::unittest {
    class TestSet {
    private:
        std::vector<Test> tests;
    public:
        void addTest(const std::string& testName, 
                     const std::function<bool()> &tests);
        void run();
    };
}

#endif // MZL_UNITTEST_TESTSET_HPP
