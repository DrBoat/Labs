#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
  
using namespace std;
 
vector <int> items;
  
void printPermutations ()
{
    vector<int> v;
    for (int i=0; i < items.size(); i++)
    {
        v.push_back(items[i]); 
    }
  
    while (next_permutation(v.begin(), v.end())) 
    { 
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}
  
  
int main() 
{ 
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        items.push_back(i + 1);
        cout << i + 1 << ' ';
    }
    cout << endl;
    printPermutations();
    return 0;
}