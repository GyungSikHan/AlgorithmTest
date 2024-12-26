#include <iostream>
#include <cmath>

using namespace std;

long long a, b, c;
long long solve;

long long Solve(long long data, long long data2)
{
	if (data2 == 1)
		return data % c;
	long long temp = Solve(data, data2 / 2);
	temp = (temp * temp) % c;
	if (data2 % 2 == 1)
		temp = (temp * data) % c;
	return temp;
}

int main()
{
	cin >> a >> b >> c;
	cout << Solve(a, b) << endl;
}