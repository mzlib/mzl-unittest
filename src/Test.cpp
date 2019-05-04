#include "../include/Test.hpp"

mzl::unittest::Test::Test(std::string name, std::function<bool()> func) {
    this->name = name;
    this->func = func;
}

bool mzl::unittest::Test::run() {
    this->func();
}