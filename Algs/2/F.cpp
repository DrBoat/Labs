#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct army
{
    int l;
    int r;
};

vector<army> formation;


void insert_left (int i, int j)
{
    int ls = formation[j].l;
    formation[i].l = formation[j].l;
    formation[j].l = i;
    formation[i].r = j;
    formation[ls].r = i;
    
}

void insert_right (int i, int j)
{
    int rs = formation[j].r;
    formation[i].r = formation[j].r;
    formation[j].r = i;
    formation[i].l = j;
    formation[rs].l = i;
}

void leave_soldier (int i)
{
    int ls = formation[i].l;
    int rs = formation[i].r;
    formation[ls].r = rs;
    formation[rs].l = ls;
    formation[i].l = 0;
    formation[i].r = 0;
}

void lnr_name (int i)
{
    int ls = formation[i].l;
    int rs = formation[i].r;
    cout << ls << ' ' << rs << '\n';
}

int main()
{
    freopen("formation.in", "r", stdin);
    freopen("formation.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    formation.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        string command;
        cin >> command;
        if (command == "left")
        {
            int a, b;
            cin >> a >> b;
            insert_left(a, b);
        }
        else if (command == "right")
        {
            int a, b;
            cin >> a >> b;
            insert_right(a, b);
        }
        else if (command == "leave")
        {
            int a;
            cin >> a;
            leave_soldier(a);
        }
        else if (command == "name")
        {
            int a;
            cin >> a;
            lnr_name(a);
        }
    }
    return 0;
}
