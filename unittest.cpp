#include "include/TestSet.hpp"
#include <functional>
#include <vector>

class TestSetA : public mzl::unittest::TestSet {
public:
    TestSetA() {
        this->addTest("testTrue", [](){
            mzl::unittest::Test::assert(5 * 2, 10);
        });
        this->addTest("testFalse", [](){
            mzl::unittest::Test::assert(5 + 2, 10);
        });
    }
};

int main() {
    TestSetA test;

    test.run();

    return 0;
}