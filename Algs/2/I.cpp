#include <iostream>
#include <vector>

using namespace std;

struct hemoglobin
{
    int sum;
    int hg;
};

vector<hemoglobin> db;

void add_patient (int h)
{
    hemoglobin tmp;
    tmp.hg = h;
    if (!db.empty())
    {
        tmp.sum = db[db.size() - 1].sum + h;
    }
    else
    {
        tmp.sum = h;
    }
    db.push_back(tmp);
}

void sum_k(int k)
{
    if (k == db.size())
    {
        cout << db[db.size() - 1].sum << '\n';
    }
    else
    {
        cout << db[db.size() - 1].sum - db[db.size() - k - 1].sum << '\n';
    }
}

int main()
{
    freopen("hemoglobin.in", "r", stdin);
    freopen("hemoglobin.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int h;
            cin >> h;
            add_patient(h);
        }
        else if (c == '?')
        {
            int k;
            cin >> k;
            sum_k(k);
        }
        else if (c == '-')
        {
            cout << db[db.size() - 1].hg << '\n';
            db.pop_back();
        }
    }
}
