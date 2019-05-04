#ifndef MZL_UNITTEST_TESTSET_HPP
#define MZL_UNITTEST_TESTSET_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <ctime>
#include <iomanip>
#include "Test.hpp"
<<<<<<< HEAD
=======
#include "AssertionException.hpp"
>>>>>>> asserts

namespace mzl::unittest {
    class TestSet {
    private:
        std::vector<Test> tests;
    public:
        void addTest(const std::string& testName, 
<<<<<<< HEAD
                     const std::function<bool()> &tests);
=======
                     const std::function<void()> &tests);
>>>>>>> asserts
        void run();
    };
}

#endif // MZL_UNITTEST_TESTSET_HPP
