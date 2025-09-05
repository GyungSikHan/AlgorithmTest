//https://www.acmicpc.net/problem/12869 v

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct A { int a, b, c; };
int hp[61][61][61];
int attack[6][3]
{
	{9,3,1},{9,1,3},
	{3,9,1}, {3,1,9},
	{1,9,3}, {1,3,9}
};
int n, scv[3];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> scv[i];

	queue<A> q;
	q.push({ scv[0],scv[1],scv[2] });

	while (q.empty() == false)
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		for (int i = 0; i < 6; i++)
		{
			int na = max(a - attack[i][0],0);
			int nb = max(b - attack[i][1],0);
			int nc = max(c - attack[i][2],0);

			if (hp[na][nb][nc] != 0)
				continue;

			hp[na][nb][nc] = hp[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}

	cout << hp[0][0][0] << endl;
}