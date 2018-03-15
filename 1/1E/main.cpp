#include <fstream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("pathbge1.in");
    fout.open("pathbge1.out");
    int n, m;
    fin >> n >> m;
    vector<list<int>> vec(n);
    for (int i = 0; i < m; i++) {
        int b, e;
        fin >> b >> e;
        vec[b - 1].push_back(e - 1);
        vec[e - 1].push_back(b - 1);
    }
    vector<int> dist(n);
    queue<int> q;
    vector<bool> used(n, false);
    q.push(0);
    used[0] = true;
    dist[0] = 0;
    int parent = 0;
    while (!q.empty()) {
        auto child = vec[q.front()];
        parent = q.front();
        q.pop();
        for (auto it : child) {
            if (!used[it]) {
                dist[it] = dist[parent] + 1;
                used[it] = true;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        fout << dist[i] << " ";
    }
    fout.close();
    return 0;
}