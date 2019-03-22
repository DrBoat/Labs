#include <iostream>
#include <vector>
 
using namespace std;
 
vector <int> heap;
 
bool isheap(int i)
{
    if (2 * i + 1 < heap.size())
    {
        if (heap[i] > heap[2 * i + 1])
        {
            return false;
        }
        else
        {
            if (!isheap(2 * i + 1)) return false;
        }
    }
    if (2 * i + 2 < heap.size())
    {
        if (heap[i] > heap[2 * i + 2])
        {
            return false;
        }
        else
        {
            if (!isheap(2 * i + 1)) return false;
        }
    }
    return true;
}
 
int main()
{
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int n;
    cin >> n;
    heap.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heap[i]; 
    }
    if (isheap(0))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}