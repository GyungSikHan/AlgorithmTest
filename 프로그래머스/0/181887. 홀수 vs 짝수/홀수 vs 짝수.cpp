#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int sum1{};
    int sum2{};
    for(int i = 0; i < num_list.size(); i++)
    {
        if(i%2 ==0)
            sum1+=num_list[i];
        else
            sum2 += num_list[i];
    }
    
    answer = max(sum1, sum2);
    
    return answer;
}