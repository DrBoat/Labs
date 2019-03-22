#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("huffman.in", "r", stdin);
	freopen("huffman.out", "w", stdout);
	long long n;
	cin >> n;
	vector<long long> p(n);
	for (long long i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	long long ans = 0;
	while(p.size() != 1)
	{
		sort(p.begin(), p.end());
		reverse(p.begin(), p.end());
		long long sum = p[p.size() - 1] + p[p.size() - 2];
		p[p.size() - 2] = sum;
		p.resize(p.size() - 1);
		ans += sum;
	}
	cout << ans << '\n';
}