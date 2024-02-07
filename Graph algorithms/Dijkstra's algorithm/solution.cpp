#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

typedef pair<long long, long long> pll;

long long dijkstra(vector<vector<pll>>& graph, long long start, long long end) {
    long long n = graph.size();
    vector<long long> distance(n, LLONG_MAX);
    distance[start] = 0;
    vector<bool> visited(n, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long dist = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        visited[node] = true;

        if (node == end) {
            return distance[end];
        }

        for (const auto& neighbor : graph[node]) {
            long long nextNode = neighbor.first;
            long long weight = neighbor.second;

            if (!visited[nextNode]) {
                long long newDist = dist + weight;

                if (newDist < distance[nextNode]) {
                    distance[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }
    }

    return distance[end];
}

int main() {
    ifstream inputFile("input.txt");
    long long n, m;
    inputFile >> n >> m;
    vector<vector<pll>> graph(n);

    for (long long i = 0; i < m; ++i) {
        long long u, v, w;
        inputFile >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }
    inputFile.close();

    long long result = dijkstra(graph, 0, n - 1);

    ofstream outputFile("output.txt");
    outputFile << result;
    outputFile.close();

    return 0;
}
