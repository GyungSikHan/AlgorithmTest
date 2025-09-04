//https://www.acmicpc.net/problem/12851 v
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;

int visited[100001];
int cnt[100001];
int Count;


int main()
{
	cin >> n >> k;
	if (n == k)
	{
		cout << 0 << endl;
		cout << 1 << endl;
		return 0;
	}

	queue<int> q;
	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;
	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();

		if (curr == k)
			break;

		for (int next : {curr+1,curr-1, curr*2})
		{
			if (next < 0 || next > 100000)
				continue;
			if (visited[next] == 0)
			{
				q.push(next);
				visited[next] = visited[curr] + 1;
				cnt[next]+= cnt[curr];
			}
			else if (visited[next] == visited[curr] + 1)
				cnt[next]+= cnt[curr];
		}
	}

	cout << visited[k]-1 << endl;
	cout << cnt[k] << endl;
}