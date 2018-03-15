#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

void neighbours_search(vector<vector<int>> &arr,
                       queue<pair<int, int>> &next_points,
                       pair<int, int> position,
                       int length) {
    int i = position.first;
    int j = position.second;
    int n = arr.size();
    int m = arr[0].size();
    if (i > 0) {
        if (arr[i - 1][j] == 0) {
            arr[i - 1][j] = length;
            next_points.push(make_pair(i - 1, j));
        }
    }
    if (i < n - 1) {
        if (arr[i + 1][j] == 0) {
            arr[i + 1][j] = length;
            next_points.push(make_pair(i + 1, j));
        }
    }
    if (j > 0) {
        if (arr[i][j - 1] == 0) {
            arr[i][j - 1] = length;
            next_points.push(make_pair(i, j - 1));
        }
    }
    if (j < m - 1) {
        if (arr[i][j + 1] == 0) {
            arr[i][j + 1] = length;
            next_points.push(make_pair(i, j + 1));
        }
    }
}

string route_search(vector<vector<int>> &arr,
                    pair<int, int> start_position,
                    pair<int, int> end_position,
                    int length) {
    pair<int, int> cur_position = end_position;
    string route;
    while (cur_position != start_position) {
        int i = cur_position.first;
        int j = cur_position.second;
        int n = arr.size();
        int m = arr[0].size();
        length--;
        if (i > 0) {
            if (arr[i - 1][j] == length - 1) {
                route += 'D';
                cur_position = make_pair(i - 1, j);
                continue;
            }
        }
        if (i < n - 1) {
            if (arr[i + 1][j] == length - 1) {
                route += 'U';
                cur_position = make_pair(i + 1, j);
                continue;
            }
        }
        if (j > 0) {
            if (arr[i][j - 1] == length - 1) {
                route += 'R';
                cur_position = make_pair(i, j - 1);
                continue;
            }
        }
        if (j < m - 1) {
            if (arr[i][j + 1] == length - 1) {
                route += 'L';
                cur_position = make_pair(i, j + 1);
                continue;
            }
        }
    }
    return route;
}

void wave_search(vector<vector<int>> &arr_length,
                 pair<int, int> start_position,
                 pair<int, int> end_position,
                 int &length) {
    queue<pair<int, int>> cur_positions;
    cur_positions.push(start_position);
    while (!cur_positions.empty()) {
        queue<pair<int, int>> next_positions;
        length++;
        for (auto point = cur_positions.front(); !cur_positions.empty(); cur_positions.pop()) {
            if (point == end_position) return;
            neighbours_search(arr_length, next_positions, point, length);
        }
        cur_positions = next_positions;
    }
}


int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    pair<int, int> start_position;
    pair<int, int> end_position;
    int n, m;
    fin >> n >> m;
    vector<vector<char>> labirint(n, vector<char>(m));
    vector<vector<int>> arr_length(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> labirint[i][j];
            if (labirint[i][j] == 'S')
                start_position = make_pair(i, j);
            else if (labirint[i][j] == 'T')
                end_position = make_pair(i, j);
            if (labirint[i][j] == '#' || labirint[i][j] == 'S')
                arr_length[i][j] = -1;
            else if (labirint[i][j] == '.' || labirint[i][j] == 'T')
                arr_length[i][j] = 0;
        }
    }
    int length = 0;
    wave_search(arr_length, start_position, end_position, length);
    arr_length[start_position.first][start_position.second] = 0;
    if (arr_length[end_position.first][end_position.second] > 0) {
        fout << length - 1 << endl;
        string route = route_search(arr_length, start_position, end_position, length);
        reverse(route.begin(), route.end());
        fout << route;
    } else {
        fout << -1;
    }
    fout.close();
    return 0;
}