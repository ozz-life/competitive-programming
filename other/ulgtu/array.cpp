#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Array
{
private:
    int *p; // pointer указатель
    int elementCount;
    int capacity;

    // реаллокация
    void reserve(int newCapacity)
    {
        int *newP = new int[newCapacity];
        for (int i = 0; i < elementCount; ++i)
        {
            newP[i] = p[i];
        };
        delete[] p;
        p = newP;
        capacity = newCapacity;
    }

public:
    Array(int size = 0, int value = 0)
    {
        p = new int[capacity];
        elementCount = size;
        capacity = size;

        for (int i = 0; i < size; ++i)
        {
            p[i] = value;
        }
    };

    ~Array()
    {
        delete[] p;
    };

    int &operator[](int index)
    {
        return p[index];

        // return *(p + index);

        // int *address = p;
        // address += index;
        // return *address;

        // char *address = (char *)p;
        // address += index * sizeof(int);
        // int *cell = (int *)address;
        // return *cell;
    }

    int &operator[](int index) const
    {
        return p[index];
    }

    int size() const
    {
        return elementCount;
    }

    bool empty() const
    {
        return elementCount == 0;
    }

    void push_back(int value)
    {
        // реаллокация
        if (elementCount == capacity)
        {
            reserve(max(1, capacity * 2));
        }
        p[elementCount] = value;
        elementCount++;
    }

    void pop_back()
    {
        elementCount--;
        if (capacity > 10 && elementCount * 4 < capacity)
        {
            reserve(capacity / 2);
        }
    }

    // O(n) - быстро вставлять невозможно
    void insert(int index, int value)
    {
        if (elementCount == capacity)
        {
            reserve(max(1, capacity * 2));
        }
        elementCount++;
        for (int i = elementCount; i > index; i--)
        {
            p[i] = p[i - 1];
        }
        p[index] = value;
    }

    // O(n) быстро удалять тоже невозможно
    void erase(int index) {
        elementCount--;
        for(int i = index; i < elementCount; i++) {
            p[i] = p[i + 1];
        }
    }
};

void print(const Array &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // Array a(10);
    // a[4] = 123;
    // print(a);

    // Array b(10, 5);
    // print(b);

    // Array c;
    // print(c);
    // for (int i = 0; i < 20; ++i) {
    //     c.push_back(i);
    //     print(c);
    // }

    // Array a;
    // std::vector<int> v;
    // auto t1 = std::chrono::steady_clock::now();
    // for (int i = 0; 1; i++)
    // {
    //     a.push_back(i);

    //     auto t2 = std::chrono::steady_clock::now();
    //     if (std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() > 0)
    //     {
    //         break;
    //     };
    // }

    Array a(5);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(3);
    a.pop_back();

    print(a);
    a.insert(2,34);
    print(a);
    a.erase(1);
    print(a);
    cout << a.size();

    return 0;
}