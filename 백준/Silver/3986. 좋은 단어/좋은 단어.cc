#include <iostream>
#include <stack>

using namespace std;

int n{};
string s;
int Count;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		stack<char> st{};

		for (int j = 0; j < s.size(); j++)
		{
			if (st.empty() == true || st.top() != s[j])
				st.push(s[j]);
			else if(st.top() == s[j])
				st.pop();
		}

		if (st.empty() == true)
			Count++;
	}

	cout << Count << endl;
}