// Не работает
 // Доделать 
 // ближайшие меньшие
 // меньшие или равные
 // большие или равные
 // Так и слева такие же
 // Стек с поддержкой минимума и максимума
 // Во всех поддерживаем стек ожидающих ответа

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a (size);
    for (int i =0; i < size; ++i) {
        cin >> a[i];
    }

    vector<int> answer(size);
    stack<int> waiting;

    for (int i = 0; i < size; ++i) {
        while(!waiting.empty() && a[i] > a[waiting.top()]) {
            answer[waiting.top()] = i;
            waiting.pop();
        }
    }

    // Если остались элементы, значит ближайшего справа нет, запишем что-нибудь
    while (!waiting.empty()) {
        answer[waiting.top()] = size;
        waiting.pop();
    }


    for (int i = 0; i < size; ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}