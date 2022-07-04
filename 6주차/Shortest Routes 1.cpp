#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
 
int main() {
	int n, m; // n: vertex, m: edge
	cin >> n >> m;
	int a; // start
	int b; // end
	int c; // weight
	vector<long> d(n, LONG_MAX); // distance
	vector<bool> visit(n, false);
	vector<vector<pair<int, int>>> list(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		list[a - 1].push_back({ b - 1, c });
	}
 
	priority_queue<pair<long,int>> pq; // first: distance, second :vertex
	d[0] = 0;
	pq.push({ 0, 0 });
	while (pq.empty() == false) {
		int t = pq.top().second;
		long D = -pq.top().first;
		pq.pop();
		if (visit[t] == false) {
			for (int i = 0; i < list[t].size(); i++) {
				if (d[list[t][i].first] > D + list[t][i].second)
					d[list[t][i].first] = D + list[t][i].second;
				pq.push({ -d[list[t][i].first], list[t][i].first });
			}
			visit[t] = true;
		}
	}
	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
	return 0;
}