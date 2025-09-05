//https://www.acmicpc.net/problem/14497 v

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };
int n, m;
int cx, cy, x2, y2;

vector<vector<char>> v;
vector<vector<int>> visited;

int main()
{
	cin >> n >> m;
	cin >> cx >> cy >> x2 >> y2;

	if (cx == x2 && cy == y2)
	{
		cout << 1 << endl;
		return 0;
	}

	v.assign(n + 1, vector<char>(m + 1, -1));
	visited.assign(n + 1, vector<int>(m + 1, 0));
	string s{};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> v[i][j];
		}
	}
	queue<pair<int, int>> q;
	visited[cx][cy] = 1;
	q.push({ cx,cy });
	int cnt{};

	while (v[x2][y2] == '#')
	{
		cnt++;
		queue<pair<int, int>>temp;
		while (q.empty() == false)
		{
			int currx = q.front().first;
			int curry = q.front().second;
			q.pop();

			if (currx == x2 && curry == y2)
				break;

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + currx;
				int ny = dy[i] + curry;

				if (nx < 1 || nx >n || ny <1 || ny>m)
					continue;
				if (visited[nx][ny] != 0)
					continue;
				visited[nx][ny] = cnt;
				if (v[nx][ny] != '0')
				{
					v[nx][ny] = '0';
					temp.push({ nx,ny });
				}
				else
					q.push({ nx,ny });
			}
		}

		q = temp;
	}

	cout << visited[x2][y2];
}