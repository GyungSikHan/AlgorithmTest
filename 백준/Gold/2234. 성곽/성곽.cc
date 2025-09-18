#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[51][51];
int visited[51][51];
int visited2[51][51];
int pa[51];
int cnt, h = -1, sum;

void Print()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(int x, int y, int num)
{
	h++;
	visited[x][y] = num;
	for (int i = 0; i < 4; i++)
	{
		if ((arr[x][y] & 1<<i) == 0)
		{
			if (1<< i == 1 && visited[x][y-1] == 0)
				DFS(x,y-1,num);
			else if (1<<i == 2 && visited[x-1][y] == 0)
				DFS(x-1,y, num);
			else if (1<<i==4 && visited[x][y + 1] == 0)
				DFS(x,y+1, num);
			else if (1<<i == 8 && visited[x+1][y] == 0)
				DFS(x+1,y, num);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int num = 1;
	int temp{};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				h = 0;
				DFS(i,j,num);
				pa[num] = h;
				temp = max(temp,h);
				num += 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i+1 < m)
			{
				int a = visited[i][j];
				int b = visited[i + 1][j];
				if (a != b)
					sum = max(sum, pa[a] + pa[b]);
			}
			if (j + 1 < n)
			{
				int a = visited[i][j];
				int b = visited[i][j+1];
				if (a != b)
					sum = max(sum, pa[a] + pa[b]);
			}
		}
	}
	cout << num-1 << "\n";
	cout << temp << "\n";
	cout << sum;
}