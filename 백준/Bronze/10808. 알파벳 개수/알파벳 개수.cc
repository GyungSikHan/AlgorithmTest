#include <iostream>
#include <string>

using namespace std;

string s;
int arr[26];

int main()
{
	cin >> s;

	for (int i = 0; i < s.size(); i++)
		arr[s[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
}
