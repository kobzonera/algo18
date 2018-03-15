#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    vector< vector<int> > vec(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> vec[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i][j] == 1) {
                if (vec[j][i] != 1 || i == j) {
                    fout << "NO";
                    return 0;
                }
            }
        }
    }
    fout << "YES";
    return 0;
}