#include <iostream>
#include <vector>

using namespace std;

const long long kMOD = 1e9;
long long d[10][101];

int main()
{
	long long n;
	cin >> n;
	for (long long i = 1; i < 10; i++)
	{
		if (i != 8) d[i][1] = 1;
	}
	for (long long i = 2; i <= n; i++)
	{
		d[0][i] = (d[4][i - 1] + d[6][i - 1]) % kMOD;
		d[1][i] = (d[6][i - 1] + d[8][i - 1]) % kMOD;
		d[2][i] = (d[7][i - 1] + d[7][i - 1]) % kMOD;
		d[3][i] = (d[4][i - 1] + d[8][i - 1]) % kMOD;
		d[4][i] = (d[0][i - 1] + d[3][i - 1] + d[9][i - 1]) % kMOD;
		d[6][i] = (d[0][i - 1] + d[1][i - 1] + d[7][i - 1]) % kMOD;
		d[7][i] = (d[2][i - 1] + d[6][i - 1]) % kMOD;
		d[8][i] = (d[1][i - 1] + d[3][i - 1]) % kMOD;
		d[9][i] = (d[2][i - 1] + d[4][i - 1]) % kMOD;
	}
	cout << (d[0][n] + d[1][n] + d[2][n] + d[3][n] + d[4][n] + d[5][n] + d[6][n] + d[7][n] + d[8][n] + d[9][n]) % kMOD;
}