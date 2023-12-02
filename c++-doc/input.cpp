#SET Ввод напрямую

set<int> ans;
cin >> p;
while (p--)
{
    int m;
    cin >> m;
    ans.insert(m);
}
cin >> q;
while (q--)
{
    int m;
    cin >> m;
    ans.insert(m);
}

#SET Ввод через массив

int n;
cin >> n;
std::unordered_set<int> st;
int size1;
cin >> size1;
vector<int> arr1(size1);
for (auto &x : arr1)
    cin >> x;
int size2;
cin >> size2;
vector<int> arr2(size2);
for (auto &x : arr2)
    cin >> x;

for (const auto &n : arr1)
    st.insert(n);
for (const auto &n : arr2)
    st.insert(n);