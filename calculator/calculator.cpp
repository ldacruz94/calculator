

#include <iostream>
#include <string>

static bool continueCalculating() {
    std::cout << "Would you like to perform another operation (y/n)? ";
    char answer;

    std::cin >> answer;

    answer = std::tolower(answer);

    if (std::tolower(answer) != 'y' && std::tolower(answer) != 'n') {
        throw std::runtime_error("Invalid response. Only respond with 'y' or 'n'.");
    }
    else if (std::tolower(answer) == 'y') {
        return true;
    }
    else if (std::tolower(answer) == 'n') {
        return false;
    } 
}


int main()
{
    bool prompt = true;

    while (prompt) {
        std::cout << "Enter your first number: ";
        long numberOne;
        std::cin >> numberOne;

        std::cout << "Enter your second number: ";
        long numberTwo;
        std::cin >> numberTwo;

        std::cout << "Enter one of the following operators (+, -, *, /): ";
        char operation;
        std::cin >> operation;

        long result;

        std::cout << "You've entered: " << numberOne << operation << numberTwo << std::endl;

        if (operation == '+') {
            result = numberOne + numberTwo;
        }
        else if (operation == '-') {
            result = numberOne - numberTwo;
        }
        else if (operation == '*') {
            result = numberOne * numberTwo;
        }
        else if (operation == '/') {
            result = numberOne / numberTwo;
        }
        else {
            continue;
        }

        std::cout << "Result: " << result << std::endl;

        try {
            prompt = continueCalculating();
        }
        catch (const std::exception& ex) {
            std::cout << "There was an error with the response you gave.";
            prompt = continueCalculating();
        }
    }
}



