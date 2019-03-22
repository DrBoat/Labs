#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

int main()
{
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);
    int n, c, prov = 0;
    cin >> n ;
    bool pr = false;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        a[i] = c;
        b[i] = c;
    }
    int left = -1;
    int right = -1;
    for (int j = n - 1; j > 0 ; j--)
    {
        if (a[j] < a[j - 1])
        {
            left = j - 1;
            pr = true;
            break;
        }
    }
    if (pr)
    {
        for (int j = n - 1; j > left ; j--)
        {
            if (a[j] < a[left] && a[j] > prov)
            {
                prov = a[j];
                right = j;
            }
        }
        swap(a[left], a[right]) ;
        for (int l = left + 1; l * 2 < n + left + 1  ; l++)
        {
            swap(a[l], a[n + left  - l]);
        }
        for (int l = 0; l < n ; l++)
        {
            cout << a[l] << " ";
        }
        cout << endl;

    }
    else
    {
        for (int l = 0; l < n ; l++)
        {
            cout << 0 << " ";
        }
        cout << endl;
    }
    pr = false;
    left = -1;
    right = -1;
    for (int j = n - 1; j > 0 ; j--)
    {
        if (b[j] > b[j - 1] )
        {
            left = j - 1;
            pr = true;
            break;
        }
    }
    if (pr)
    {
        for (int j = n - 1; j >= 0 ; j--)
        {
            if (b[j] > b[left])
            {
                right = j;
                break;
            }
        }
        swap(b[left], b[right]);
        sort(b.begin() + left + 1, b.end());
        for (int l = 0; l < n ; l++)
        {
            cout << b[l] << " ";
        }
        cout << endl;

    }
    else
    {
        for ( int l = 0; l < n ; l++)
        {
            cout << 0 << " ";
        }
        cout << endl;
    }
}
