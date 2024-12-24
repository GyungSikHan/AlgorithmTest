#include <iostream>
#include <string>

using namespace std;

int n{};
int arr[26];
string Result;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> Result;

		arr[Result[0] - 'a']++;
	}

	Result = "";

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] >= 5)
			Result += (char)(i + 'a');
	}

	if (Result == "")
		cout << "PREDAJA" << endl;
	else
		cout << Result << endl;
}