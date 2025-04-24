#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// bool solution(vector<string> phone_book) {
//     bool answer = true;
    
//     sort(phone_book.begin(), phone_book.end());
    
//     for (int i = 0; i < phone_book.size()-1; i++)
//     {
//         if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()) )
//             return false;                
//     }

//     return answer;
// }

unordered_map<string, int> map;
bool isPrefix(string phone)
{
    string prefix{};

    for (const char c : phone)
    {   
        prefix+=c;

        if(map.find(prefix) != map.end() && prefix != phone)
            return true;
    }
    return false;
}

bool solution(vector<string> phone_book) 
{
    for (const string s : phone_book)
    {
        if(map.empty() == true)
            map.insert({s,1});
        else
            map[s]++;
    }

    for (const string s : phone_book)
    {
        if(isPrefix(s) == true)
            return false;
    }
    
    return true;
}
