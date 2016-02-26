#include <iostream>
#include <list>
#include <map>
#include <unordered_set>

using namespace std;

class Graph {
    map<int, unordered_set<int>> neighboursList;

    void dfs(int currentNode, list<int> &currentPath, unordered_set<int> &visited, list<int> &maxPath) {
        if (visited.find(currentNode) == visited.end()) {
            // if not visited
            visited.insert(currentNode);
            currentPath.push_back(currentNode);
            if (currentPath.size() > maxPath.size())
                maxPath = currentPath;

            for (int v : neighboursList[currentNode]) {
                if (neighboursList[v].find(currentNode) != neighboursList[v].end())
                    // if the edge is two-way
                    dfs(v, currentPath, visited, maxPath);
            }

            currentPath.pop_back();
            visited.erase(currentNode);
        }
    }

    void createGraph(list<pair<int, int> > &edges) {
        for (pair<int, int> &edge : edges) {
            neighboursList[edge.first].insert(edge.second);
        }
    }
public:
    Graph(list<pair<int, int> > &edges) {
        createGraph(edges);
    }

    list<int> maxTwoWayFrom(int n) {
        unordered_set<int> visited;
        list<int> currentPath, maxPath;
        dfs(n, currentPath, visited, maxPath);
        return maxPath;
    }
};

int main() {
    list<pair<int, int> > edges = {
            make_pair(1, 2),
            make_pair(2, 1),
            make_pair(2, 3),
            make_pair(3, 2),
            make_pair(3, 4),
            make_pair(3, 5),
            make_pair(5, 3),
            make_pair(1, 5),
            make_pair(5, 4),
            make_pair(1, 6),
            make_pair(6, 1),
            make_pair(6, 7),
            make_pair(7, 6),
    };

    Graph g(edges);

    list<int> maxPath = g.maxTwoWayFrom(1);
    for (int v : maxPath)
        cout << v << " ";
    cout << endl;

    return 0;
}