#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int n, m;
char arr[51][51];
int visited[51][51];
int ret;
int Count;

void BFS(int x, int y)
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>>q;
	q.push({x, y});
	visited[x][y] = 1;

	while (q.empty() == false)
	{
		int currx = q.front().first;
		int curry = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + currx;
			int ny = dy[i] + curry;

			if(nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if(visited[nx][ny] == 0 && arr[nx][ny] == 'L')
				{
					visited[nx][ny] = visited[currx][curry] + 1;
					q.push({ nx,ny });

					ret = max(ret, visited[nx][ny]);
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if(arr[i][j] == 'L')
				BFS(i, j);

	cout << ret - 1<< endl;
}