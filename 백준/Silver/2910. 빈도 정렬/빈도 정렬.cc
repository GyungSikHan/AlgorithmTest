#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, temp;
map<int, int> m, m2;
vector<pair<int, int>> v;

bool com(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return m2[a.second] < m2[b.second];
	return a.first > b.first;
}

int main()
{
	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		m[temp]++;
		if (m2[temp] == 0)
			m2[temp] = i + 1;
	}
	for (pair<int, int> iter : m)
		v.push_back({ iter.second,iter.first });
	
	sort(v.begin(), v.end(), com);

	for (pair<int, int> iter : v)
		for (int i = 0; i < iter.first; i++)
			cout << iter.second << " ";
}