#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n, m;
    fin >> n >> m;
    int A, B;
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        fin >> A >> B;
        res[A - 1][B - 1] = 1;
    }
    for (auto vec : res) {
        for (auto i : vec) {
            fout << i << " ";
        }
        fout << "\n";
    }
    fout.close();
    return 0;
}