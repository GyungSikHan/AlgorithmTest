#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int>wt,wc,bt,bc;
long long dp[104][100004];
int m;

int go(int idx, int times, int sum)
{
	if (times > k)
		return 0;
	long long & ret = dp[idx][times];
	if (idx == n)
	{
		if (sum > m)
		{
			m = sum;
			return 1;
		}
		return 0;
	}

	if (ret)
		return 1;

	go(idx + 1, times + wt[idx], sum + wc[idx]);
	go(idx+1, times+bt[idx], sum+bc[idx]);

	return ret;
}

int main()
{
	cin >> n >> k;
	
	for (int i=0;i<n;i++)
	{
		int w{}, c{}, b{}, c2{};
		cin >> w >> c >> b >> c2;
		wt.push_back(w);
		wc.push_back(c);
		bt.push_back(b);
		bc.push_back(c2);
	}

	go(0, 0, 0);
	cout << m;
}