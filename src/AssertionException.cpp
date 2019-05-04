#include "../include/AssertionException.hpp"

mzl::unittest::AssertionException::
AssertionException(std::string message) {
    this->message = message;
}

const char* mzl::unittest::AssertionException::
what () const throw () {
    return ("AssertionException: " + this->message).c_str();
}