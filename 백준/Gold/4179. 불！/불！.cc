#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int r, c;
vector<string> map;
vector<vector<int>> Jvisited, Fvisited;
queue<pair<int, int>> J, F;

int main() {
    cin >> r >> c;
    map.resize(r);
    Jvisited.assign(r, vector<int>(c, INF));
    Fvisited.assign(r, vector<int>(c, INF));

    for (int i = 0; i < r; i++) {
        cin >> map[i];
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'J') {
                J.push({i, j});
                Jvisited[i][j] = 0; // 시작 지점 방문 처리
            } else if (map[i][j] == 'F') {
                F.push({i, j});
                Fvisited[i][j] = 0; // 불의 시작 지점 방문 처리
            }
        }
    }

    // Fire BFS
    while (!F.empty()) {
        int currx = F.front().first;
        int curry = F.front().second;
        F.pop();

        for (int i = 0; i < 4; i++) {
            int nx = currx + dx[i], ny = curry + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (map[nx][ny] == '#' || Fvisited[nx][ny] != INF) continue;

            Fvisited[nx][ny] = Fvisited[currx][curry] + 1;
            F.push({nx, ny});
        }
    }

    // Jihun BFS
    int ret = INF;
    while (!J.empty()) {
        int currx = J.front().first;
        int curry = J.front().second;
        J.pop();

        for (int i = 0; i < 4; i++) {
            int nx = currx + dx[i], ny = curry + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) { // 탈출 성공
                ret = Jvisited[currx][curry] + 1;
                cout << ret << endl;
                return 0;
            }
            if (map[nx][ny] == '#' || Jvisited[nx][ny] != INF) continue;
            if (Fvisited[nx][ny] <= Jvisited[currx][curry] + 1) continue;

            Jvisited[nx][ny] = Jvisited[currx][curry] + 1;
            J.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
