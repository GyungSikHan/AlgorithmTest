#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int temp{};

    auto iter = find(seoul.begin(), seoul.end(), "Kim");
    int i{};
    if(iter != seoul.end())
		i = distance(seoul.begin(), iter);
   

   answer += to_string(i);
    answer += "에 있다";
    return answer;
}
