#ifndef MZL_UNITTEST_TEST_HPP
#define MZL_UNITTEST_TEST_HPP

#include <functional>
#include <string>

namespace mzl::unittest {
    class Test {
    private:
        std::string name;
        std::function<bool()> func;
    public:
        Test(std::string name, std::function<bool()> func);

        bool run();
    };
}

#endif // MZL_UNITTEST_TEST_HPP