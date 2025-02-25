#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int compare(int a, int b)
{
    return a > b;
}
long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    int index = 10;
    int count{};    
    while (n != 0)
    {
        v.push_back(n%index);
        n/=index;
        count++;
    }
    sort(v.begin(), v.end(),compare);
    for(int i : v)
    {
        answer += i*pow(index,count-1);
        count--;
    }
         
    
    
    return answer;
}