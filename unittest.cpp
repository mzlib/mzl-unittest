#include "include/TestSet.hpp"
#include "include/Assert.hpp"
#include <functional>
#include <vector>

namespace MZL_UT = mzl::unittest;

class TestSetA : public MZL_UT::TestSet {
public:
    TestSetA() {
        this->addTest("testAssertEquals", [](){
            int x = 5 * 2;
            MZL_UT::Assert::assertEquals(x, 10);
        });
        this->addTest("testAssertNotEquals", [](){
            int x = 5 + 2;
            MZL_UT::Assert::assertNotEquals(x, 10);
        });
        this->addTest("testAssertTrue", [](){
            bool b = true;
            MZL_UT::Assert::assertTrue(b);
        });
        this->addTest("testAssertFalse", [](){
            bool b = false;
            MZL_UT::Assert::assertFalse(b);
        });
    }
};

int main() {
    TestSetA test;

    test.run();

    return 0;
}