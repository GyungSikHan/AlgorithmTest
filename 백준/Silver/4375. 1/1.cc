#include <iostream>

using namespace std;

long long n;


int main()
{
	while (scanf("%d", &n) != EOF)
	{
		long long count = 1, cnt = 1;
		while (cnt % n != 0)
		{
			cnt = cnt * 10 + 1;
			cnt %= n;
			count++;
		}
		cout << count << endl;
	}
}