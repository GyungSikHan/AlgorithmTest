#include<bits/stdc++.h>
using namespace std;

const int MAX = 4000000;
bool che[MAX+1];
int n;

vector<int> era(int mx_n)
{
    vector<int> v;
    for(int i = 2; i <= mx_n; i++)
    {
        if(che[i] == 1)
            continue;
        for(int j = 2*i; j <= mx_n; j+=i)
        {
            che[j] = 1;
        }
    }

    for(int i = 2; i <= mx_n; i++)
    {
        if(che[i] == 0)
            v.push_back(i);
    }   

    return v;
}

int main()
{
    cin>>n;
    vector<int> a = era(n);
    // for(auto iter : a)
    //     cout<<iter<<endl;
    int cnt{};
    for(int i = 0; i < a.size(); i++)
    {
        int temp = n;
        for(int j = i; j < a.size(); j++)
        {
            temp -= a[j];
            if(temp == 0)
                cnt++;
            else if(temp < 0)
                break;
        }
    }
    cout<<cnt;
}