#include <iostream>
#include <stack>
#include <string>
#include <conio.h>
#include <sstream>

using namespace std;

class Graph
{
public:
    Graph() {
        cout << "Number of vertexes: ";
        cin >> numVer;
        cin.ignore(256, '\n');
        links = new int*[numVer];
        for (int i = 0; i < numVer; i++) {
            links[i] = new int[numVer];
        }
    }
    void fulling() {
        string line, dir;
        for (int i = 0; i < numVer; i++) {
            cout << "Enter direction of links " << i + 1 << ": ";
            getline(cin, line);
            stringstream ss(line);
            while (getline(ss, dir, ' ')) {
                if (dir != "0")
                    this->links[i][stoi(dir) - 1] = 1;
            }
        }
        cout << endl;
    }

    void DFS(int ver) {
        for (int j = 0; j < numVer; j++) {
            if (lastVer.empty()) {
                if (links[ver][j] == 1) {
                    stk.push(j);
                    lastVer.push(ver);
                    DFS(j);
                    lastVer.pop();
                }
            } else {
                if (links[ver][j] == 1 && j != lastVer.top()) {
                    stk.push(j);
                    lastVer.push(ver);
                    DFS(j);
                    lastVer.pop();
                }
            }
        }
    }

    void DFSTable() {
        for (int i = 0; i < numVer; i++) {
            DFS(i);
            while (stk.size()) {
                links[i][stk.top()] = 1;
                stk.pop();
            }
        }
    }

    void show() {
        for (int i = 0; i < numVer; i++) {
            links[i][i] = 1;
            for (int j = 0; j < numVer; j++) {
                cout << links[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int numVer, **links;
    stack <int> lastVer;
    stack <int> stk;
};

int main() {
    Graph graph;
    graph.fulling();
    graph.DFSTable();
    graph.show();
    _getch();
    return 0;
}