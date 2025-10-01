#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;
string boom;
stack<char> st;

int main()
{
	cin >> s;
	cin >> boom;
	for (char c : s)
	{
		st.push(c);
		if (st.size() >= boom.size() && st.top() == boom[boom.size() - 1])
		{
			string temp{};
			for (int i = 0; i < boom.size(); i++)
			{
				temp += st.top();
				st.pop();
			}
			reverse(temp.begin(),temp.end());
			if (temp != boom)
				for (char iter : temp)
					st.push(iter);
		}
	}

	if (st.empty() == true)
		cout << "FRULA";
	else
	{
		string temp{};
		while (st.empty() == false)
		{
			temp += st.top();
			st.pop();
		}
		reverse(temp.begin(), temp.end());
		cout << temp;
	}
}