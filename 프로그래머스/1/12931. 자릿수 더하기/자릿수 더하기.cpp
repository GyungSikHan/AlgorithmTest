#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int temp = 10;
    
    while(n != 0)
    {
        cout <<  n%temp << endl;
        answer += n%temp;
        n/=10;
    }
    


    return answer;
}