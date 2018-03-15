#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n, m;
    fin >> n >> m;
    vector<list<int>> list_arr(m, list<int>());
    int A, B;
    for (int i = 0; i < m; i++) {
        fin >> A >> B;
        auto iter_A = find(list_arr[A - 1].begin(), list_arr[A - 1].end(), B - 1);
        auto iter_B = find(list_arr[B - 1].begin(), list_arr[B - 1].end(), A - 1);
        if (iter_A != list_arr[A - 1].end() && iter_B != list_arr[B - 1].end()) {
            fout << "YES";
            fout.close();
            return 0;
        } else {
            list_arr[A - 1].push_back(B - 1);
            list_arr[B - 1].push_back(A - 1);
        }
    }
    fout << "NO";
    fout.close();
    return 0;
}