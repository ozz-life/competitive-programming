#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>

const char OPEN_BRACKETS[] = {'(', '['};
const char CLOSE_BRACKETS[] = {')', ']'};
const char EMPTY = '-';

class BracketGenerator {
private:
    int n;
    std::string sequence;
    int m;
    int bracketNum;
    int openCount;
    std::deque<char> stack;

public:
    BracketGenerator(int n) : n(n), openCount(0) {
        sequence.resize(n * 2, EMPTY); // Размер удваивается, чтобы уместить обе скобки
        m = n;
        bracketNum = sizeof(OPEN_BRACKETS) / sizeof(OPEN_BRACKETS[0]);
    }

    void dfs(int pos, std::ostream &output) {
        if (pos == n * 2) {
            output << sequence << std::endl;
            return;
        }

        // Проверяем можем ли ставить открывающую скобку
        if (openCount < m) {
            for (int i = 0; i < bracketNum; i++) {
                sequence[pos] = OPEN_BRACKETS[i];
                stack.push_back(CLOSE_BRACKETS[i]);
                openCount++;
                dfs(pos + 1, output);
                sequence[pos] = EMPTY;
                openCount--;
                stack.pop_back();
            }
        }

        // Проверяем можем ли ставить закрывающую скобку, стек не должен быть пустым
        if (!stack.empty()) {
            char pop = stack.back();
            for (int i = 0; i < bracketNum; i++) {
                if (CLOSE_BRACKETS[i] == pop) {
                    sequence[pos] = CLOSE_BRACKETS[i];
                    dfs(pos + 1, output);
                    sequence[pos] = EMPTY;
                    stack.pop_back();
                }
            }
        }
    }

    void generateBrackets(std::ostream &output) {
        dfs(0, output);
    }
};

int main() {
    int n;
    std::cin >> n;

    if (n % 2 != 0) {
        return 0;
    }

    BracketGenerator generator(n);
    generator.generateBrackets(std::cout);

    return 0;
}
