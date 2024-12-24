#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;
int arr[101];
int n, m;
int sum;
int main()
{
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++)
	{
		cin >> n >> m;

		for (int j = n; j < m; j++)
		{
			arr[j]++;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == 1)
			sum += a;
		else if (arr[i] == 2)
			sum += b*2;
		else if (arr[i] == 3)
			sum += c*3;
	}

	cout << sum << endl;
}