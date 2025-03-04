#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int index{};
    for(int i = phone_number.size()-1; i>= 0; i--)
    {
        if(index < 4)
            index++;
        else
            phone_number[i] = '*';
    }
    return phone_number;
}