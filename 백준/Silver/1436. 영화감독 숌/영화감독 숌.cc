#include <iostream>
#include <string>

using namespace std;

int MoveName(int n)
{
	int a{};
	int dead = 666;
	string name{};

	while (true)
	{
		name = to_string(dead);
		for (int i = 0; i < (int)name.length()-2; i++)
		{
			if (name[i] == '6' && name[i + 1] == '6' && name[i + 2] == '6')
			{
				a++;
				if (a == n)
				{
					return dead;
				}
				break;

			}
		}
		dead++;
	}


}

int main()
{
	int n{};

	cin >> n;
	cout << MoveName(n) << endl;
}