#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;
queue<pair<int, int>> q;
vector<vector<int>> v;
vector<vector<int>> visited;

void DFS(int y, int x)
{
	q.push({y, x});
	visited[y][x] = 1;

	while (q.empty() == false)
	{
		int curry = q.front().first;
		int currx = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = curry + dy[i];
			int nx = currx + dx[i];
			if(ny >=0 && ny < n && nx >= 0 && nx < m)
			{
				if(visited[ny][nx] == false && v[ny][nx] == 1)
				{
					visited[ny][nx] = visited[curry][currx] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	v.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &v[i][j]);


	DFS(0,0);
	cout << visited[n-1][m-1] << endl;
}
