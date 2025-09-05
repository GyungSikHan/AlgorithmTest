#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int arr[100001];
int cnt[100001];
queue<int> q;

int main()
{
	cin >> n >> k;

	q.push(n);
	arr[n] = 1;
	cnt[n] = 1;

	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();
		//cout << curr << endl;
		for (int next : {curr -1, curr+1, curr*2})
		{
			if (next < 0 || next > 100000)
				continue;
			if (arr[next] == 0)
			{
				arr[next] = arr[curr] + 1;
				cnt[next] += cnt[curr];
				q.push(next);
			}
			else if (arr[next] == arr[curr]+1)
				cnt[next] += cnt[curr];
		}
	}
	cout << arr[k]-1 << endl;
	cout << cnt[k] << endl;
}