#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;
map<string, int> m1;
map<int, string> m2;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		m1.insert({ s,i });
		m2.insert({ i,s });
	}

	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (atoi(s.c_str()) == 0)
			cout << m1[s] << "\n";
		else
			cout << m2[atoi(s.c_str())] << "\n";
	}
}
