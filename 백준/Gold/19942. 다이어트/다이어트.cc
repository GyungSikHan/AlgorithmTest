#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 987654321;
int n;
int mp,mf,ms,mv;
vector<vector<int>> v;
int ret = INF;
vector<int> node;

void Solution(int x, int sum, vector<int> temp, vector<int> t)
{
	if (temp[0]>= mp && temp[1] >= mf && temp[2]>=ms&&temp[3] >= mv)
	{
		if (ret > sum)
		{
			ret = sum;
			node = t;
		}
		return;
	}

	for (int i = x+1; i <= n; i++)
	{
		temp[0] += v[i][0];
		temp[1] += v[i][1];
		temp[2] += v[i][2];
		temp[3] += v[i][3];
		t.push_back(i);
		Solution(i, sum + v[i][4], temp,t);
		t.pop_back();
		temp[0] -= v[i][0];
		temp[1] -= v[i][1];
		temp[2] -= v[i][2];
		temp[3] -= v[i][3];
	}
}

int main()
{
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	v.assign(n+1,vector<int>(5,0));
	for (int i = 1; i <= n; i++)
		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];
	
	for (int i = 1; i <= n; i++)
	{
		vector<int> t;
		vector<int> temp;
		t.push_back(i);
		temp.push_back(v[i][0]);
		temp.push_back(v[i][1]);
		temp.push_back(v[i][2]);
		temp.push_back(v[i][3]);
		Solution(i, v[i][4],temp,t);
	}
    
    if(ret == INF)
        cout<<-1;
    else
    {
        cout << ret << "\n";
	    for (int i : node)
		    cout << i << " ";    
    }
	
}