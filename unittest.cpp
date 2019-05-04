#include "include/TestSet.hpp"
#include <functional>
#include <vector>

class TestSetA : public mzl::unittest::TestSet {
public:
    TestSetA() {
<<<<<<< HEAD
        this->addTest("testFalse", [](){
            return false;
        });
        this->addTest("testTrue", [](){
            return true;
=======
        this->addTest("testTrue", [](){
            mzl::unittest::Test::assert(2 * 5, 10);
        });
        this->addTest("testFalse", [](){
            mzl::unittest::Test::assert(2 + 5, 10);
>>>>>>> asserts
        });
    }
};

int main() {
    TestSetA test;

    test.run();

    return 0;
}