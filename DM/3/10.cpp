#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
 
using namespace std;

void sums_partition(int n_start, int n_cur, const vector<int> &sums)
{
    if(!n_cur)
    {
        for(vector<int> ::const_iterator  summands_it = sums.begin(); summands_it != sums.end(); ++summands_it)
        {
            cout << *summands_it << (summands_it != sums.end() - 1 ? "+" : "\n");
        } 
    }    
    for(int cur_slag = sums.empty() ? 1 : sums.back(); n_cur - cur_slag >= 0; ++cur_slag)    
    {
        vector<int> sums_new(sums);
        sums_new.push_back(cur_slag);
        sums_partition(n_start, n_cur - cur_slag, sums_new);
    }
}

int main()
{
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    int  n = 0;
    cin >> n;
    vector<int> sums;    
    sums_partition(n, n, sums); 
}