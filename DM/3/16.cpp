#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

int N, K;
vector <int> choose;

long long C(int n, int k)
{
    if ((n == k) || (k == 0))
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }
    return C(n - 1, k) + C(n - 1, k - 1);
}

int choose2num()
{
    int numOfChoose = 0;
    for (int i = 1; i <= K; i++)                                       
    {
        for  (int j = choose[i - 1] + 1; j <= choose[i] - 1; j++)
        {
            numOfChoose += C((N - j), (K - i));
        }
    }
    return numOfChoose;
}



int main()
{
    freopen("choose2num.in", "r", stdin);
    freopen("choose2num.out", "w", stdout);
    cin >> N >> K;
    choose.resize(K + 1);
    choose[0] = 0;
    for (int i = 1; i <= K; i++)
    {
        cin >> choose[i];
    }
    cout << choose2num();
    return 0;
}