#include "include/TestSet.hpp"
#include <functional>
#include <vector>

class TestSetA : public mzl::unittest::TestSet {
public:
    TestSetA() {
        this->addTest("testFalse", [](){
            return false;
        });
        this->addTest("testTrue", [](){
            return true;
        });
    }
};

int main() {
    TestSetA test;

    test.run();

    return 0;
}