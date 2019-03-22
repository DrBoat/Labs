#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
  
  
using namespace std;
  
vector <string> a;
int n, m, k;
  
char digit (string x, int i)
{
    return x[m - i - 1];
}
  
void radix_sort(int iter)
{
    vector <string> b (n);
    vector <int> c(256);
    for (int i = 0; i < iter; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            c[j] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            char d = digit(a[j], i);
            c[d]++;
        }
        int count = 0;
        for (int j = 0; j < 256; j++)
        {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; j++)
        {
            char d = digit(a[j], i);
            b[c[d]] = a[j];
            c[d]++;
        }
        a = b;
    }
}
  
int main()
{
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    radix_sort(k);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\n';
    }
    return 0;
}