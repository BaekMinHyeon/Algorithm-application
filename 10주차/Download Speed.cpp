#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>

using namespace std;

#define V 500 // n의 최댓값
long graph[V][V];
int n;

// s: 시작, t: 마지막, parent: bfs를 하면서 
bool bfs(long rGraph[V][V], int s, int t, int* parent)
{
    bool visited[V];
    memset(visited, false, sizeof(visited)); // 초기화
    visited[s] = true;
    queue<int> q;
    q.push(s);
    // BFS 탐색 방법
    while (!q.empty()) {
        int u = q.front(); // 맨앞
        q.pop();// 맨앞 없애줌

        for (int v = 0; v < n; v++) { // v : 도착지
            if (visited[v] == false && rGraph[u][v] > 0) { // 지나갈 수 있는 조건(방문하지 않았고 weight가 0보다 크다)
                if (v == t) { // 마지막 도착
                    parent[v] = u; // 어디랑 이어져있는지
                    return true;
                }
                // 마지막 가기전까지
                q.push(v); // bfs탐색을 위한 저장
                parent[v] = u; // 어디랑 이어져있는지
                visited[v] = true;
            }
        }
    }
    // 마지막에 도달 못함
    return false;
}

// fordFulkerson 알고리즘(max-flow)
long fordFulkerson(long graph[V][V], int s, int t)
{
    int u, v;
    long rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V]; // BFS를 하면서 어떤 vertex와 이어져있는지
    long max_flow = 0; // 초기 값
    // 마지막에 도달 할때까지 BFS 반복
    while (bfs(rGraph, s, t, parent)) {
        long path_flow = LONG_MAX; // path_flow 중 최솟값 찾음
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        } // 지나가는 길중 가장 작은 값 구함

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        } // 가장 작은 값 처음에서 마지막으로 가는 길은 빼주고 마지막에서 처음으로 가는길에는 더해줌
        max_flow += path_flow; // max-flow 구함(가장 작았던 값들 도달 못할 때까지 더해줌)
    }
    return max_flow;
}

int main() {
    int m;
    cin >> n >> m;
    int a, b;
    long weight;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> weight;
        a--;
        b--;
        graph[a][b] += weight;
    }
    cout << fordFulkerson(graph, 0, n-1) << endl;
    return 0;
}