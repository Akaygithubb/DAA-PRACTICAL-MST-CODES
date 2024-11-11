#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;
// Define the pair type for storing (distance, vertex) in the priority queue
typedef pair<int, int> pii;
// Dijkstra's Algorithm
void dijkstra(int src, const vector<vector<pii>>& graph, int V) {
// Initialize distance array with infinity
vector<int> dist(V, INT_MAX);
// Priority queue to store (distance, vertex), starting with (0, src)
priority_queue<pii, vector<pii>, greater<pii>> pq;
dist[src] = 0; // Distance to source is 0
pq.push({0, src}); // Push the source vertex with distance 0
while (!pq.empty()) {
int u = pq.top().second; // Get the vertex with the smallest distance
pq.pop();
// Loop through all adjacent vertices of u
for (auto& edge : graph[u]) {
int v = edge.first; // Neighbor vertex
int weight = edge.second; // Edge weight
// If a shorter path is found
if (dist[u] + weight < dist[v]) {
dist[v] = dist[u] + weight; // Update distance
pq.push({dist[v], v}); // Push the updated distance to the priority queue
}
}
}
// Output the shortest distances
cout << "Vertex \t Distance from Source " << src << endl;
for (int i = 0; i < V; ++i) {
cout << i << "\t" << dist[i] << endl;
}



}
int main() {
int V = 5; // Number of vertices
vector<vector<pii>> graph(V);
// Add edges to the graph (example graph)
// For each edge, use graph[u].push_back({v, weight})
graph[0].push_back({1, 9});
graph[0].push_back({2, 6});
graph[0].push_back({3, 5});
graph[0].push_back({4, 3});
graph[2].push_back({1, 2});
graph[2].push_back({3, 4});
int src = 0; // Source vertex
dijkstra(src, graph, V); // Call Dijkstra's algorithm
return 0;
}
