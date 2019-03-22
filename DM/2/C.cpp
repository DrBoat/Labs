#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string dictionary = "";

int char_index_in_dictionary (char c)
{
	int i = 0;
	while (dictionary[i] != c)
	{
		i++;
	}
	return i;
}

void char_to_left(char c)
{
	int ch_ind = char_index_in_dictionary(c);
	cout << (ch_ind + 1) << ' ';
	for (int i = ch_ind; i > 0; i--)
	{
		swap(dictionary[i], dictionary[i - 1]);
	}
}

int main()
{
	freopen("mtf.in", "r", stdin);
	freopen("mtf.out", "w", stdout);
	for (char c = 'a'; c <= 'z'; c++)
	{
		dictionary += c;
	}
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		char_to_left(s[i]);
	}
}