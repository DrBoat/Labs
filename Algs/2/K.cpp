#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque <int> fst, scnd;

void check_deque()
{
    while (!fst.empty() && fst.size() > scnd.size())
    {
        int tmp = fst.back();
        scnd.push_front(tmp);
        fst.pop_back();
    }
    while (!scnd.empty() && fst.size() < scnd.size() - 1)
    {
        int tmp = scnd.front();
        fst.push_back(tmp);
        scnd.pop_front();
    }
}

void add_sword(int el)
{
    scnd.push_back(el);
    check_deque();
}

void take_sword()
{
    if (!scnd.empty())
    {
        scnd.pop_back();
    }
    check_deque();
}

void mum()
{
    swap(fst, scnd);
    check_deque();
}

int main()
{
    freopen("kenobi.in", "r", stdin);
    freopen("kenobi.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string command;
        cin >> command;
        if (command == "add")
        {
            int a;
            cin >> a;
            add_sword(a);
        }
        else if (command == "take")
        {
            take_sword();
        }
        else if (command == "mum!")
        {
            mum();
        }
        else cout << command;
    }
    cout << fst.size() + scnd.size() << '\n';
    while (!fst.empty())
    {
        cout << fst.front() << ' ';
        fst.pop_front();
    }
    while (!scnd.empty())
    {
        cout << scnd.front() << ' ';
        scnd.pop_front();
    }
    return 0;
}
