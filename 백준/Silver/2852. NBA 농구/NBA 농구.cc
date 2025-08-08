#include <iostream>
using namespace std;

int toSec(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

string toMMSS(int sec) {
    char buf[6];
    sprintf(buf, "%02d:%02d", sec / 60, sec % 60);
    return string(buf);
}

int main() {
    int N, score1 = 0, score2 = 0;
    int time1 = 0, time2 = 0;
    int leader = 0, leadStart = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int team;
        string time;
        cin >> team >> time;
        int curTime = toSec(time);

        if (team == 1) score1++;
        else score2++;

        int newLeader = 0;
        if (score1 > score2) newLeader = 1;
        else if (score2 > score1) newLeader = 2;

        if (leader != newLeader) {
            if (leader == 1) time1 += curTime - leadStart;
            else if (leader == 2) time2 += curTime - leadStart;

            leader = newLeader;
            leadStart = curTime;
        }
    }

    if (leader == 1) time1 += 2880 - leadStart;
    else if (leader == 2) time2 += 2880 - leadStart;

    cout << toMMSS(time1) << '\n' << toMMSS(time2) << '\n';
}
