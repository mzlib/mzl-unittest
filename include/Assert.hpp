#ifndef MZL_UNITTEST_ASSERT_HPP
#define MZL_UNITTEST_ASSERT_HPP

#include "AssertionException.hpp"

namespace mzl::unittest {
    class Assert {
    public:
        template<class T>
        static void assertEquals(T value, T expected) {
            if (value != expected) {
                std::stringstream ss;
                ss << "assertEquals(" << value << ", " << expected << ")";

                throw AssertionException(ss.str());
            }
        }

        template<class T>
        static void assertNotEquals(T value, T expected) {
            if (value == expected) {
                std::stringstream ss;
                ss << "assertNotEquals(" << value << ", " << expected << ")";

                throw AssertionException(ss.str());
            }
        }
    };
}

#endif // MZL_UNITTEST_ASSERT_HPP