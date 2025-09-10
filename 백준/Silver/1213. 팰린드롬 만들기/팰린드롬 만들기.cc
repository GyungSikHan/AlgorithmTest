#include <iostream>

using namespace std;

string s, ret;
int arr[200];
char temp;
int flag{};
int main()
{
	cin >> s;
	for (char a : s)
		arr[a]++;

	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (arr[i] != 0)
		{
			if(arr[i] % 2 == 1)
			{
				temp = (char)(i);
				flag++;
				arr[i]--;
			}
			if(flag >= 2)
				break;
			for (int j = 0; j < arr[i]; j+=2)
			{
				ret = (char)(i) + ret;
				ret += (char)(i);
			}
		}
	}

	if (temp != 0)
		ret.insert(ret.begin() + ret.size() / 2, temp);

	if (flag >= 2)
		cout << "I'm Sorry Hansoo" << endl;
	else
		cout << ret << endl;
}