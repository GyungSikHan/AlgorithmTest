#include <iostream>
#include <vector>

using namespace std;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
int n;
int arr[101][101];
bool visited[101][101];
int Maxdata;
int Maxcount;

void DFS(int data, int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny >= 0 && ny < n && nx >= 0 && nx <n)
		{
			if(visited[ny][nx] == false && arr[ny][nx] > data)
			{
				DFS(data, ny, nx);
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp{};
			cin >> temp;
			arr[i][j] = temp;
			Maxdata = max(Maxdata, temp);
		}
	}
	int temp{};
	for (int k = 0; k <= Maxdata; k++)
	{
		Maxcount = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101,0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == false && arr[i][j] > k)
				{
					Maxcount++;
					DFS(k, i, j);
				}
			}
		}
		temp = max(Maxcount, temp);
	}

	cout << temp << endl;
}