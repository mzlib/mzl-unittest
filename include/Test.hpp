#ifndef MZL_UNITTEST_TEST_HPP
#define MZL_UNITTEST_TEST_HPP

#include <functional>
#include <string>
#include <sstream>
#include <functional>
#include <string>
#include "AssertionException.hpp"

namespace mzl::unittest {
    class Test {
    private:
        std::string name;
        std::function<void()> func;
    public:
        Test(const std::string& name, std::function<void()> func);

        void run() const;

        std::string getName() const;
    };
}

#endif // MZL_UNITTEST_TEST_HPP