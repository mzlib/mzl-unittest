#ifndef MZL_UNITTEST_TEST_HPP
#define MZL_UNITTEST_TEST_HPP

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
        template<class T>
        static void assert(T value, T expected) {
            if (value != expected) {
                std::stringstream ss;
                ss << "assert(" << value << ", " << expected << ")";

                throw AssertionException(ss.str());
            }
        }

        Test(const std::string& name, std::function<void()> func);

        void run();

        std::string getName() const;
    };
}

#endif // MZL_UNITTEST_TEST_HPP