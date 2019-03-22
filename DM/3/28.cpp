#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("nextmultiperm.in","r",stdin);
    freopen("nextmultiperm.out","w",stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (next_permutation(a.begin(),a.end()))
    {
        for (int i = 0; i < n ; i++)
        {
            cout << a[i] << ' ';
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << 0 << ' ';
        }
    }
}
