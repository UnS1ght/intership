#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void bfs(const std::vector<std::vector<int>>& graph, int start, std::vector<int>& dst) {
    std::queue<int> q;
    q.push(start);
    dst[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (dst[neighbor] == -1) {
                dst[neighbor] = dst[current] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    std::ifstream infile("graph.txt");
    if (!infile) {

        std::cerr << "Ошибка считывания данных из файла";
        return 1;
    }
    int startVertex, vertices, edges
    
    infile >> vertices >> edges;
    std::vector<std::vector<int>> graph(vertices);
    for (int i = 0; i < edges; ++i) {

        int u, v;
        infile >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    infile >> startVertex;
    std::vector<int> dst(vertices, -1);
    bfs(graph, startVertex, dst);
    for (int i = 0; i < vertices; ++i) {
        std::cout << dst[i] << std::endl;
    }

    return 0;
}