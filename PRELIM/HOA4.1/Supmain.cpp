// Alvarez, Joshua Caleb P.
#include <iostream>
#include <string>
#include "symbolStack.h"

bool isOpeningBracket(char symbol)
{
    return symbol == '(' || symbol == '{' || symbol == '[';
}

bool isClosingBracket(char symbol)
{
    return symbol == ')' || symbol == '}' || symbol == ']';
}

bool bracketsMatch(char openBracket, char closeBracket)
{
    return (openBracket == '(' && closeBracket == ')') ||
           (openBracket == '{' && closeBracket == '}') ||
           (openBracket == '[' && closeBracket == ']');
}

bool checkBalancedExpression(const std::string& expression)
{
    // Clear the stack
    while (!isEmpty<char>())
    {
        pop<char>();
    }

    // Read every character
    for (char symbol : expression)
    {
        if (isOpeningBracket(symbol))
        {
            push<char>(symbol);
        }
        else if (isClosingBracket(symbol))
        {
            if (isEmpty<char>())
            {
                return false;
            }

            char topSymbol = pop<char>();

            if (!bracketsMatch(topSymbol, symbol))
            {
                return false;
            }
        }
    }

    return isEmpty<char>();
}

int main()
{
    std::string expression;

    std::cout << "==============================\n";
    std::cout << " Balanced Symbols Checker\n";
    std::cout << "==============================\n\n";

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (checkBalancedExpression(expression))
    {
        std::cout << "\nVALID Expression\n";
    }
    else
    {
        std::cout << "\nINVALID Expression\n";
    }

    return 0;
}