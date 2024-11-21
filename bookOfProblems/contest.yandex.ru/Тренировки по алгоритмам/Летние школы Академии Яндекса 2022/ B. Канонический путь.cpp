// Для решения задачи можно использовать стек. Для этого сначала нужно разделить строку на токены, используя разделитель "/". Затем для каждого токена провести следующие действия:

//     Если токен пустой, то пропустить его.

//     Если токен равен ".", то пропустить его.

//     Если токен равен "..", то удалить последний элемент из стека (если он есть).

//     В остальных случаях добавить токен в стек.

// После обработки всех токенов сформировать из стека новую строку, объединив его элементы с помощью разделителя "/". При этом учитывать требования к каноническому пути (начинаться с одного "/", не заканчиваться "/", не содержать "." и "..").

// Пример реализации на C++:

// c++

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string path;
    getline(cin, path);

    vector<string> tokens;
    string token;
    for (char c : path) {
        if (c == '/') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token.push_back(c);
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }

    stack<string> stack;
    for (const string& token : tokens) {
        if (token == ".") {
            continue;
        } else if (token == "..") {
            if (!stack.empty()) {
                stack.pop();
            }
        } else {
            stack.push(token);
        }
    }

    if (stack.empty()) {
        cout << "/";
    } else {
        vector<string> elements;
        while (!stack.empty()) {
            elements.push_back(stack.top());
            stack.pop();
        }
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            cout << "/" << *it;
        }
    }

    cout << endl;
    return 0;
}