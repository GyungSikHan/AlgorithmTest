#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int m, n, k;
int Count;
int visited[101][101] = { 0 }; // 초기화
vector<int> v;

void FloodFill(int x1, int y1, int x2, int y2)
{
    for (int i = y1; i < y2; i++)
    {
        for (int j = x1; j < x2; j++)
        {
            visited[i][j] = true; // 방문 처리
        }
    }
}

void DFS(int y, int x)
{
    visited[y][x] = true;
    Count++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < m && nx >= 0 && nx < n)
        {
            if (!visited[ny][nx])
            {
                DFS(ny, nx);
            }
        }
    }
}

int main()
{
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        FloodFill(x1, y1, x2, y2);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                Count = 0; // Count 초기화
                DFS(i, j);
                v.push_back(Count);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl; // 영역 개수 출력
    for (int data : v)
        cout << data << " ";
    return 0;
}
