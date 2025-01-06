#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v;
string s;

string DFS(int y, int x, int k)
{
	if (k == 1)
		return string(1, v[y][x]);
	string result{};
	char temp = v[y][x];

	for (int i = y; i < k+y; i++)
	{
		for (int j = x; j < k+x; j++)
		{
			if(temp != v[i][j])
			{
				result += '(';
				result += DFS(y, x, k / 2);
				result += DFS(y, x+k/2, k/2);
				result += DFS(y+k/2, x, k/2);
				result += DFS(y+k/2, x+k/2, k/2);
				result += ')';
				return result;
			}
		}
	}

	return string(1, v[y][x]);
}

int main()
{
	cin >> n;
	v.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			v[i][j] = s[j];
		}
	}

	cout << DFS(0, 0, n) << endl;

}