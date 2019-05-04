#include "include/TestSet.hpp"
#include "include/Assert.hpp"
#include <functional>
#include <vector>

namespace MZL_UT = mzl::unittest;

class TestSetA : public MZL_UT::TestSet {
public:
    TestSetA() {
        this->addTest("testTrue", [](){
            int x = 5 * 2;
            MZL_UT::Assert::assertEquals(x, 10);
        });
        this->addTest("testFalse", [](){
            int x = 5 + 2;
            MZL_UT::Assert::assertNotEquals(x, 10);
        });
    }
};

int main() {
    TestSetA test;

    test.run();

    return 0;
}