#include<iostream>
#include <queue>

using namespace std;
#define MAX 400000
int n, k;
int visited[MAX];
priority_queue <pair<int, int>, vector <pair< int, int >> , greater<pair<int, int>> > pq;

int main()
{
	cin >> n >> k;
	pq.push({0,n});

	while (pq.empty() == false)
	{
		int time = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		visited[now] = 1;

		if(now == k)
		{
			cout << time << endl;
			break;
		}

		if (now - 1 >= 0 && visited[now - 1] == 0)
			pq.push({ time+1,now-1 });
		if (now + 1 <= 100000 && visited[now + 1] == 0)
			pq.push({ time + 1,now + 1 });
		if (now * 2 <= 100000 && visited[now * 2] == 0)
			pq.push({ time, now*2 });

	}
	
}