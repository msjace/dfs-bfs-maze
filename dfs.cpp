#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

class MazeSearch {
private:
    vector<vector<char>> maze;
    vector<vector<int>> steps; 
    pair<int, int> start, exit;
    int rows, cols;
    bool found = false;

    const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isMovablePoint(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != 'X' && steps[x][y] == 0;
    }

    void dfs(int x, int y, int step) {
        if (make_pair(x, y) == exit) {
            steps[x][y] = step;
            found = true;
            return;
        }

        steps[x][y] = step;

        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (isMovablePoint(nx, ny)) {
                dfs(nx, ny, step + 1);
                if (found) return; 
            }
        }

        steps[x][y] = 0;
    }

public:
    MazeSearch(const vector<vector<char>>& inputMaze) {
        maze = inputMaze;
        rows = maze.size();
        cols = maze[0].size();
        steps = vector<vector<int>>(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (maze[i][j] == 'S') start = {i, j};
                if (maze[i][j] == 'E') exit = {i, j};
            }
        }
    }

    void solve() {
        dfs(start.first, start.second, 1);
    }

    void printResult() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (steps[i][j] > 0) {
                    cout << setw(3) << steps[i][j]; 
                } else {
                    cout << setw(3) << maze[i][j]; 
                }
            }
            cout << endl;
        }
    }
};

int main() {

    // ex.1
    vector<vector<char>> maze = {
        {'S', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'E'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O'}
    };

    //ex.2
    //  vector<vector<char>> maze = {
    //     {'S', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    //     {'X', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
    //     {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'X'},
    //     {'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X'},
    //     {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
    //     {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
    //     {'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'E'},
    //     {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
    //     {'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    //     {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    // };

    MazeSearch solver(maze);

    solver.solve();
    solver.printResult();

    return 0;
}
