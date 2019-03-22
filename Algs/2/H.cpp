#include <iostream>
#include <queue>

using namespace std;

struct hmtime
{
    int h;
    int m;
};

queue<hmtime> q;
queue<int> ind;

hmtime answ[105];

hmtime plus20m (hmtime ans)
{
    ans.m += 20;
    if (ans.m >= 60)
    {
        ans.m -= 60;
        ans.h++;
    }
    return ans;
}

bool t_less_t (hmtime f, hmtime s)
{
    if (f.h < s.h)
    {
        return true;
    }
    else if (f.h == s.h && f.m <= s.m)
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("saloon.in", "r", stdin);
    freopen("saloon.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        hmtime cur_hmtime;
        cin >> cur_hmtime.h >> cur_hmtime.m;
        int fuck_it;
        cin >> fuck_it;
        while (!q.empty())
        {
            if (t_less_t(q.front(), cur_hmtime))
            {
                answ[ind.front()] = q.front();
                q.pop();
                ind.pop();
            }
            else
            {
                break;
            }
        }
        if (q.size() <= fuck_it)
        {
            if (!q.empty() && t_less_t(cur_hmtime, q.back()))
            {
                cur_hmtime = q.back();
            }
            cur_hmtime = plus20m(cur_hmtime);
            q.push(cur_hmtime);
            ind.push(i);
        }
        else
        {
            answ[i] = cur_hmtime;
        }
    }
    while (!q.empty())
    {
        answ[ind.front()] = q.front();
        q.pop();
        ind.pop();
    }
    for (int i = 0; i < n; ++i)
    {
        cout << answ[i].h << ' ' << answ[i].m << '\n';
    }
}
