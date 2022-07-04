#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>

using namespace std;

#define V 500 // n�� �ִ�
long graph[V][V];
int n;

// s: ����, t: ������, parent: bfs�� �ϸ鼭 
bool bfs(long rGraph[V][V], int s, int t, int* parent)
{
    bool visited[V];
    memset(visited, false, sizeof(visited)); // �ʱ�ȭ
    visited[s] = true;
    queue<int> q;
    q.push(s);
    // BFS Ž�� ���
    while (!q.empty()) {
        int u = q.front(); // �Ǿ�
        q.pop();// �Ǿ� ������

        for (int v = 0; v < n; v++) { // v : ������
            if (visited[v] == false && rGraph[u][v] > 0) { // ������ �� �ִ� ����(�湮���� �ʾҰ� weight�� 0���� ũ��)
                if (v == t) { // ������ ����
                    parent[v] = u; // ���� �̾����ִ���
                    return true;
                }
                // ������ ����������
                q.push(v); // bfsŽ���� ���� ����
                parent[v] = u; // ���� �̾����ִ���
                visited[v] = true;
            }
        }
    }
    // �������� ���� ����
    return false;
}

// fordFulkerson �˰���(max-flow)
long fordFulkerson(long graph[V][V], int s, int t)
{
    int u, v;
    long rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V]; // BFS�� �ϸ鼭 � vertex�� �̾����ִ���
    long max_flow = 0; // �ʱ� ��
    // �������� ���� �Ҷ����� BFS �ݺ�
    while (bfs(rGraph, s, t, parent)) {
        long path_flow = LONG_MAX; // path_flow �� �ּڰ� ã��
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        } // �������� ���� ���� ���� �� ����

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        } // ���� ���� �� ó������ ���������� ���� ���� ���ְ� ���������� ó������ ���±濡�� ������
        max_flow += path_flow; // max-flow ����(���� �۾Ҵ� ���� ���� ���� ������ ������)
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