#include <iostream>
#include <string>
#include <exception> // for std::exception
#include <stdexcept> // for std::runtime_error


// classes are destructed even if throw happens inside constructor

class MemberOfHasIssues {
public:
    MemberOfHasIssues() {
        std::cerr << "MemberOfHasIssues constructor" << std::endl;
    }
    ~MemberOfHasIssues() {
        std::cerr << "MemberHasIssues destructor" << std::endl;
    }
};

class HasIssues {
private:
    MemberOfHasIssues m_member{ };
public:
    HasIssues() {
        std::cout << "about to throw" << std::endl;
        throw "mo money mo problems";
    }

    ~HasIssues() {
        std::cerr << "will not get called but can cleanup in member classes if needed b/c destructor gets called there" << std::endl;
    }
};

void reThrowExample() {
    try {
        throw std::runtime_error{ "should re-throw" };
    } catch (const std::exception& exception) {
        std::cerr << "re-throw caught and now re-throwing: " << exception.what() << std::endl;
        // if want to re-throw the same error you caught so it can be passed to parent, just use throw
        throw;
    }
}

void runNoExceptExample() noexcept {
    throw "will not get caught in main method and will have uncaught exception b/c put noexcept on function";
};

int main()
{
    try
    {
        // Statements that may throw exceptions you want to handle go here
        // throw -1; // here's a trivial example
        // throw "hi";
        // HasIssues issues{};

        // it is very common to use the standard runtime_error to throw errors
        // throw std::runtime_error{ "bad stuff man" };

        // reThrowExample();

        // runNoExceptExample();

    }
    catch (int x)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double" << '\n';
    }
    catch (const std::string&) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string" << '\n';
    }
    // will probably use this the most as it will get a good description of the error
    // also all exceptions the standard internal library throws will be of this type so it will catch all those
    catch (const std::exception& exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }
    // this must come last
    catch (...)
    {
        std::cerr << "This should catch anything" << std::endl;
    }


    std::cout << "Continuing on our merry way\n";

    return 0;
}