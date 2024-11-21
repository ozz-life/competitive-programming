#include <iostream>
#include <string>
#include <stack>

char getOpeningBracket(char closingBracket)
{
    if (closingBracket == ')')
    {
        return '(';
    }
    else if (closingBracket == ']')
    {
        return '[';
    }
    else
    {
        return '{';
    }
}

int main()
{
    std::string sequence;
    std::cin >> sequence;
    std::stack<char> openedBrackets;

    for (char currentBracket : sequence)
    {
        if (currentBracket == '(' || currentBracket == '[' || currentBracket == '{')
        {
            openedBrackets.push(currentBracket);
        }
        else if (!openedBrackets.empty() && openedBrackets.top() == getOpeningBracket(currentBracket))
        {
            openedBrackets.pop();
        }
        else
        {
            std::cout << "no";
            return 0;
        }
    }

    if (!openedBrackets.empty())
    {
        std::cout << "no";
    }
    else
    {
        std::cout << "yes";
    }

    return 0;
}
