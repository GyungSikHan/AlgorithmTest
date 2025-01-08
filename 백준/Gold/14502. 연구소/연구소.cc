#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, M, result;
int map[8][8];
int visit[8][8];
vector<pair<int, int>>v;

//바이러스 퍼트리는 dfs
int dfs(int x, int y)
{
	visit[x][y] = 2;
	if (x - 1 >= 0 && visit[x - 1][y] == 0 && map[x - 1][y] == 0)
		dfs(x - 1, y);
	if (x + 1 < N && visit[x + 1][y] == 0 && map[x + 1][y] == 0)
		dfs(x + 1, y);
	if (y - 1 >= 0 && visit[x][y - 1] == 0 && map[x][y - 1] == 0)
		dfs(x, y - 1);
	if (y + 1 < M && visit[x][y + 1] == 0 && map[x][y + 1] == 0)
		dfs(x, y + 1);

	return 0;
}

//벽 3개 고르기
int select(int cnt)
{
	if (cnt == 3) 
	{
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < (int)v.size(); i++)
		{
			dfs(v[i].first, v[i].second);
		}
		cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visit[i][j] == 0 && map[i][j] == 0)
				{
					cnt++;
				}
			}
		}

		result = max(result, cnt);
	}
	else 
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = 1;
					select(cnt + 1);
					map[i][j] = 0;
				}
			}
		}
	}


	return 0;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			cin >> map[i][j];
			if (map[i][j] == 2) 
				v.push_back(make_pair(i,j));
		}
	}
	select(0);
	cout << result;
	return 0;
}