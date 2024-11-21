#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

struct Node
{
    int value;
    Node *next;

    Node(int v, Node *n)
    {
        value = v;
        next = n;
    }
};

class LinkedList
{
    Node *head, *tail;
    int elementCount;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        elementCount = 0;
    }

    ~LinkedList()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    Node *get_node(int index)
    {
        Node *n = head;
        for (int i = 0; i < index; ++i)
        {
            n = n->next;
        }
        return n;
    }

    // O(n) - В списке невозможно быстро получать элемент по индексу
    int &operator[](int index)
    {
        return get_node(index)->value;
    }

    int size() const
    {
        return elementCount;
    }

    bool empty() const
    {
        return elementCount == 0;
    }

    void push_front(int value)
    {
        head = new Node(value, head);
        elementCount++;
        if (tail == nullptr)
        {
            tail = head;
        }
    }

    // O(1)
    void pop_front()
    {
        Node *nextHead = head->next;
        delete head;
        head = nextHead;
        elementCount--;
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    void print() const
    {
        for (Node *n = head; n; n = n->next)
        {
            cout << n->value << " ";
        }
        cout << "\n";
    }

    // Вставка и удаление фактическа за O(n), но если мы хотим всегда вставлять в одно и тоже место, то можно сделать эффективнее
    void insert_after(Node *elem, int value)
    {
        elem->next = new Node(value, elem->next);
        elementCount++;
        if (tail == elem) {
            tail = tail -> next;
        }
    }

    void erase_after(Node *elem)
    {
        Node *nextElem = elem->next;
        elem->next = nextElem->next;
        delete nextElem;
        elementCount--;
        if (tail == nextElem) {
            tail = elem;
        }
    }

    void push_back(int value)
    {
        if (empty())
        {
            push_front(value);
        }
        insert_after(tail, value);
    }
};

void print(LinkedList &l)
{
    for (int i = 0; i < l.size(); ++i)
    {
        cout << l[i] << " ";
    }
    cout << "\n";
}

int main()
{

    LinkedList l;
    l.push_front(12);
    l.push_front(34);
    l.push_front(56);
    l.print();
    l.insert_after(l.get_node(1), 100);
    l.print();
    l.erase_after(l.get_node(1));
    l.print();

    return 0;
}