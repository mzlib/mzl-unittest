#include "../include/Test.hpp"

<<<<<<< HEAD
mzl::unittest::Test::Test(std::string name, std::function<bool()> func) {
=======
mzl::unittest::Test::Test(const std::string& name, std::function<void()> func) {
>>>>>>> asserts
    this->name = name;
    this->func = func;
}

<<<<<<< HEAD
bool mzl::unittest::Test::run() {
=======
void mzl::unittest::Test::run() {
>>>>>>> asserts
    this->func();
}

std::string mzl::unittest::Test::getName() const {
    return this->name;
}