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

        static void assertEquals(float value, float expected, float e) {
            if ((value < expected - e) || (value > expected + e)) {
                std::stringstream ss;
                ss << "assertEquals(" << value << ", " << expected << "," 
                   << e << ")";

                throw AssertionException(ss.str());
            }
        }

        static void assertNotEquals(float value, float expected, float e) {
            if ((value >= expected - e) && (value <= expected + e)) {
                std::stringstream ss;
                ss << "assertNotEquals(" << value << ", " << expected << "," 
                   << e << ")";

                throw AssertionException(ss.str());
            }
        }

        static void assertEquals(double value, double expected, double e) {
            if ((value < expected - e) || (value > expected + e)) {
                std::stringstream ss;
                ss << "assertEquals(" << value << ", " << expected << "," 
                   << e << ")";

                throw AssertionException(ss.str());
            }
        }

        static void assertNotEquals(double value, double expected, double e) {
            if ((value >= expected - e) && (value <= expected + e)) {
                std::stringstream ss;
                ss << "assertNotEquals(" << value << ", " << expected << "," 
                   << e << ")";

                throw AssertionException(ss.str());
            }
        }

        static void assertTrue(bool value) {
            if (value != true) {
                std::stringstream ss;
                ss << "assertTrue(" << value << ")";

                throw AssertionException(ss.str());
            }
        }

        static void assertFalse(bool value) {
            if (value != false) {
                std::stringstream ss;
                ss << "assertFalse(" << value << ")";

                throw AssertionException(ss.str());
            }
        }
    };
}

#endif // MZL_UNITTEST_ASSERT_HPP