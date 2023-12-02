#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += pow(-1, i + 1) / i;
    }
    cout << setprecision(6) << fixed << sum << endl;
    return 0;
}