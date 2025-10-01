#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
string boom;

int main()
{
	cin >> s;
	cin >> boom;

	string ret{};
	for (char c : s)
	{
		ret += c;
		if (ret.size() >= boom.size() && ret.substr(ret.size() - boom.size(), boom.size()) == boom)
			ret.erase(ret.size() - boom.size(), ret.size());
	}

	if (ret == "")
		cout << "FRULA";
	else
		cout << ret;
}