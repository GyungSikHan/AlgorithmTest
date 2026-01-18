#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> se;

    string temp{};
    int idx = 0, idx2 = 0;  
    int cnt{};
    for(auto iter : words)
    { 
        if(se.find(iter) != se.end() || (temp != "" && iter.front() != temp.back()))
        { 
            return {idx % n +1, idx2 / n  + 1};
        } 
        temp = iter;
        se.insert(iter); 
        idx++;idx2++;
    } 
    return {0, 0}; 
}