#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;

bool Check(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
	while (true)
	{
		cin >> s;
		if (s == "end")
			break;
		int same{}, same2{};
		bool bResult{}, bTemp{};
		char temp{};

		for (int i = 0; i < s.size(); i++)
		{
			if(Check(s[i]) == true)
			{
				same++;
				same2 = 0;
				bTemp = true;
			}
			else
			{
				same2++;
				same = 0;
			}
			if (same == 3 || same2 == 3)
				bResult = true;
			if (i >= 1 && temp == s[i] && (s[i] != 'e' && s[i] != 'o'))
				bResult = true;

			temp = s[i];
		}

		if (bTemp == false)
			bResult = true;
		if (bResult == false)
			cout << "<" << s << ">" << " is acceptable." << endl;
		else
			cout << "<" << s << ">" << " is not acceptable." << endl;
	}
}