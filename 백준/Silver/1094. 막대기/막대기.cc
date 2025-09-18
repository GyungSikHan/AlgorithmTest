#include <iostream>
#include <vector>

using namespace std;

int x, stick = 64, cnt;

int main()
{
	cin >> x;

	if (x == 64)
	{
		cout << 1;
		return 0;
	}

	vector<int> v;
	v.push_back(stick);
	while (true)
	{
		int half = v.back();
		if (x == half)
			break;

		v.pop_back();
		half /= 2;
		int sum = half;
		for (int i : v)
			sum += i;

		if (sum >= x)
		{
			v.push_back(half);
			if (sum == x)
				break;
		}
		else
		{
			v.push_back(half);
			v.push_back(half);
		}
	}

	cout << v.size();
}