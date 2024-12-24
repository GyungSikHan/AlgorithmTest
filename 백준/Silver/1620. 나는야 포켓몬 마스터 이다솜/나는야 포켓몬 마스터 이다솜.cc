#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> pokemons(n + 1);
    map<string, int> pokemon_map;

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        pokemons[i] = name;
        pokemon_map[name] = i;
    }

    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;

        if (isdigit(query[0])) {
            int index = stoi(query);
            cout << pokemons[index] << '\n';
        } else {
            cout << pokemon_map[query] << '\n';
        }
    }

    return 0;
}