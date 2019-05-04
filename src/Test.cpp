#include "../include/Test.hpp"

mzl::unittest::Test::Test(const std::string& name, std::function<void()> func) {
    this->name = name;
    this->func = func;
}

void mzl::unittest::Test::run() const {
    this->func();
}

std::string mzl::unittest::Test::getName() const {
    return this->name;
}