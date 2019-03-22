#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

vector <int> arr;
vector <vector<int>> ans;

void get_ans(int num, vector<int> s)
{
    if (num == arr.size())
    {
        ans.push_back(s);
        return;
    }
    get_ans(num + 1, s);
    s.push_back(arr[num]);
    get_ans(num + 1, s);
}

int main()
{
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i + 1);
    }
    vector <int> tmp;
    get_ans(0, tmp);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}