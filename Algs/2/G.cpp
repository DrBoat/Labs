#include <iostream>
#include <deque>

using namespace std;

deque <int> fst, scnd;

void check_deque()
{
    if (scnd.size() > fst.size())
    {
        int tmp = scnd.front();
        fst.push_back(tmp);
        scnd.pop_front();
    }
}

void in_end(int el)
{
    scnd.push_back(el);
    check_deque();
}

void in_center(int el)
{
    scnd.push_front(el);
    check_deque();
}

void leave_q()
{
    int tmp = fst.front();
    cout << tmp <<'\n';
    fst.pop_front();
    check_deque();
}

int main()
{
    freopen("hospital.in", "r", stdin);
    freopen("hospital.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        char command;
        cin >> command;
        if (command == '+')
        {
            int a;
            cin >> a;
            in_end(a);
        }
        else if (command == '*')
        {
            int a;
            cin >> a;
            in_center(a);
        }
        else if (command == '-')
        {
            leave_q();
        }
        else cout << command;
    }
    return 0;
}
