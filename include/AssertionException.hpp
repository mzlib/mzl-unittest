#ifndef MZL_UNITTEST_ASSERTIONEXCEPTION_HPP
#define MZL_UNITTEST_ASSERTIONEXCEPTION_HPP

#include <exception>
#include <string>

namespace mzl::unittest {
    class AssertionException : public std::exception {
    private:
        std::string message;
    public:
        AssertionException(std::string message);

        const char* what () const throw ();
    };
}

#endif // MZL_UNITTEST_ASSERTIONEXCEPTION_HPP