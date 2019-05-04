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
        this->addTest("testAssertFloatEquals", [](){
            MZL_UT::Assert::assertEquals(5.523123f + 0.000001f, 5.523124f, 0.01f);
        });
        this->addTest("testAssertFloatNotEquals", [](){
            MZL_UT::Assert::assertNotEquals(5.523123f + 0.000001f, 5.523124f, 0.0f);
        });
        this->addTest("testAssertDoubleEquals", [](){
            MZL_UT::Assert::assertEquals(5.523123f + 0.000001, 5.523124, 0.01);
        });
        this->addTest("testAssertDoubleNotEquals", [](){
            MZL_UT::Assert::assertNotEquals(5.523123123 + 0.000000001, 5.523123124, 0.0);
        });
    }
};

int main() {
    TestSetA test;

    test.run();

    return 0;
}