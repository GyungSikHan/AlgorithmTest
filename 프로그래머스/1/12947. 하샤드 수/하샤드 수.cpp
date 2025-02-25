#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int temp{};
    int temp2 = x;
    while(temp2 != 0)
    {
        temp+=temp2%10;
        temp2/= 10;
    }
    
    answer = x%temp == 0;
    
    return answer;
}