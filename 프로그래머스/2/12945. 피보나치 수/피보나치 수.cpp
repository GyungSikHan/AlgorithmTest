#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
	vector<int> v;

	v.push_back(0);
	v.push_back(1);

	if (n < 3)
        return answer;
    for (int i = 2; i <= n; i++)
		v.push_back((v[i-2] + v[i-1]) % 1234567);
	answer = v[n];
	return answer;
}