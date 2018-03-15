#include <fstream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("components.in");
    fout.open("components.out");
    int n, m;
    fin >> n >> m;
    vector<list<int>> vec(n);
    for (int i = 0; i < m; i++) {
        int b, e;
        fin >> b >> e;
        vec[b - 1].push_back(e - 1);
        vec[e - 1].push_back(b - 1);
    }
    vector<int> v_component(n);
    vector<list<int>> comp(n, list<int>());
    queue<int> q;
    vector<bool> used(n, false);
    int cur_component = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            q.push(i);
            v_component[i] = ++cur_component;
            used[i] = true;
            while (!q.empty()) {
                auto child = vec[q.front()];
                q.pop();
                for (auto it : child) {
                    if (!used[it]) {
                        v_component[it] = cur_component;
                        used[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    fout << cur_component << "\n";
    for (int i = 0; i < n; i++) {
            fout << v_component[i] << " ";
    }
    fout.close();
    return 0;
}