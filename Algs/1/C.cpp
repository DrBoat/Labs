#include <iostream>
#include <vector>
#include <string>
#include <ctime>
 
using namespace std;
 
vector <int> a;
 
void qsort(int left, int right)
{
    srand(time(0));
    int key = a[(rand() % (right - left + 1)) + left];
    int i = left, j = right;
    while (i <= j) 
    {
        while (a[i] < key) i++;
        while (a[j] > key) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j) qsort(left , j);
    if (i < right) qsort(i , right);
}
 
 
 
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qsort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}