#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
const double eps = 1e-7;
 
class mine
{
public:
    double t;
    int s;
    int n;
    mine(double tt, int ss, int nn)
    {
        t = tt; s = ss; n = nn;
    }
};
 
bool cmp(mine a, mine b)
{
    return(a.t < b.t);
}
 
vector <mine> v;
int n, u, l, t, mmax, tmax;
 
mine
    lp = mine(0, 0, 0),
    pp = mine(0, 0, 0);
 
double EASY_EASY_REAL_TALK_MAN_THINK_ABOUT_IT (double left, double right)
{
    double mid = (left + right) / 2;
    if ((right - mid) < eps)
    {
        return(mid);
    }
    vector <mine> a = v;
    double ll = 1e30;
    for (int i = 0; i < v.size(); ++i)
    {
        a.push_back(mine(v[i].t + mid + eps, v[i].s, 2));
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (a[i].n == 1)
        {
            lp = mine(0, 0, 0); pp = mine(0, 0, 0);
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j].n != a[i].n)
                {
                    lp = a[j];
                    break;
                }
            }
            for (int j = i + 1; j < a.size(); j++)
            {
                if (a[j].n != a[i].n)
                {
                    pp = a[j];
                    break;
                }
            }
            if ((lp.n) && (pp.n))
            {
                ll = min(ll, a[i].s - ((a[i].t - lp.t) * pp.s + (pp.t - a[i].t) * lp.s) / (pp.t - lp.t));
            }
        }
        else
        {
            lp = mine(0, 0, 0);
            pp = mine(0, 0, 0);
            for (int j = i - 1; j >= 0; j--)
                if (a[j].n != a[i].n)
                {
                    lp = a[j];
                    break;
                }
            for (int j = i + 1; j < a.size(); j++)
                if (a[j].n != a[i].n)
                {
                    pp = a[j];
                    break;
                }
                if ((lp.n) && (pp.n))
                {
                    ll = min(ll, ((a[i].t - lp.t) * pp.s + (pp.t - a[i].t) * lp.s) / (pp.t - lp.t) - a[i].s);
                }
        }
    }
    a.clear();
    return (ll > l) ? (EASY_EASY_REAL_TALK_MAN_THINK_ABOUT_IT(left, mid)) : (EASY_EASY_REAL_TALK_MAN_THINK_ABOUT_IT(mid, right));
}
 
int main()
{
    freopen("trains.in", "r", stdin);
    freopen("trains.out", "w", stdout);
    cin >> l >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> u;
        tmax += t;
        mmax += t * u;
        v.push_back(mine(tmax - t, mmax - t * u, 1));
    }
    v.push_back(mine(tmax, mmax, 1));
    cout << fixed;
    cout.precision(3);
    cout << EASY_EASY_REAL_TALK_MAN_THINK_ABOUT_IT(0, tmax + eps) << endl;
    return 0;
}