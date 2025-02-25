#include <string>
#include <vector>
#include<cmath>
using namespace std;

int solution(string s) {
     int answer = 0;
    char c{};
    int index = (s.size()-1);
    for(int i = 0; i< s.size();i++)
    {
        if(s[i]== '+'|| (s[i] == '-')) 
            c = s[i];
        else
            answer += (s[i]-'0')*pow(10,index);
        index--;
    }
    if(c == '-')
        answer *= -1;
    return answer;
}