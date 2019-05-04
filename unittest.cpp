#include "include/TestSet.hpp"
#include "include/Assert.hpp"
#include <functional>
#include <vector>

namespace MZL_UT = mzl::unittest;

class TestSetA : public MZL_UT::TestSet {
public:
    TestSetA() {
        this->addTest("testTrue", [](){
            MZL_UT::Assert::assertEquals(5 * 2, 10);
        });
        this->addTest("testFalse", [](){
            MZL_UT::Assert::assertNotEquals(5 + 2, 10);
        });
    }
};

int main() {
    TestSetA test;

    test.run();

    return 0;
}