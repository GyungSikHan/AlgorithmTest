#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size()-1; i++)
    {
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()) )
            return false;                
    }

    return answer;
}