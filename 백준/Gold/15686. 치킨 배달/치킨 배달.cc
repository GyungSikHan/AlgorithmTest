#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<vector<int>> chickenList;

void Combi(int start, vector<int> v)
{
	if(v.size() == m)
	{
		chickenList.push_back(v);
		return;
	}

	for (int i = start+1; i < chicken.size(); i++)
	{
		v.push_back(i);
		Combi(i, v);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	map.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back({ i,j });
			else if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	int result = 987654321;
	vector<int> v;
	Combi(-1, v);

	for (vector<int> list : chickenList)
	{
		int ret{};
		for (pair<int, int> h : home)
		{
			int m = 987654321;
			for (int c : list)
			{
				int dist = abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second);
				m = min(m, dist);
			}
			ret += m;
		}
		result = min(result, ret);
	}

	cout << result << endl;
}