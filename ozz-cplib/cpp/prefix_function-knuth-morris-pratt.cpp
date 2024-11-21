#include <bits/stdc++.h>
using namespace std;

void print_vector(const std::vector<size_t> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

// https://habr.com/en/articles/307220/
vector<size_t> prefix_function(string s)
{
    size_t n = s.length();
    vector<size_t> pi(n);
    for (size_t i = 1; i < n; ++i)
    {
        size_t j = pi[i - 1];
        while ((j > 0) && (s[i] != s[j]))
            j = pi[j - 1];

        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str;
    cin >> str;

    vector<size_t> result = prefix_function(str);
    print_vector(result);

    return 0;
}