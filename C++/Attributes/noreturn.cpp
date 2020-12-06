#include <iostream>
#include <vector>

[[noreturn]] auto ownAssertFailureHandler(std::string message) -> int /*void*/
{
    std::cerr << message << std::endl;
    if (message == "test")
    {
        std::cout << "!!test" << std::endl;
        throw std::move(message);   
    }
    std::cout << "if message is not test print " << std::endl;
    std::terminate();
}

std::vector<int> createSequence(int end)
{
    if (end > 0)
    {
        std::vector<int> sequence;
        sequence.reserve(end + 1);
        for (int i = 0; i <= end; ++i)
            sequence.push_back(i);
        return sequence;
    }
    ownAssertFailureHandler("test");
    std::cout <<"if message == test : not print" << std::endl;
    ownAssertFailureHandler("Negative number passed to createSequence()");
    // return std::vector<int>{}; //< Not needed because of [[noreturn]]
}

int main(){
    createSequence(-1);
    createSequence(1);
    std::cout << "main end is not print" << std::endl;
}