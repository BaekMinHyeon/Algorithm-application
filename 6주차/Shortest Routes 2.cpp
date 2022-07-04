#include <iostream>
#include <queue>
#include <vector>
#include <climits>
 
using namespace std;
 
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	int a, b;
	long long c;
	int outa, outb;
	vector<vector<long long>> d(n, vector<long long>(n, LLONG_MAX)); // distance
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		d[a - 1][b - 1] = min(d[a - 1][b - 1],c);
		d[b - 1][a - 1] = d[a - 1][b - 1];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			d[i][i] = 0;
			for (int j = 0; j < n; j++) {
				if (d[k - 1][j] != LLONG_MAX && d[i][k - 1] != LLONG_MAX) {
					d[i][j] = min(d[i][j], d[k - 1][j] + d[i][k - 1]);
					d[j][i] = d[i][j];
				}
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> outa >> outb;
		if (d[outa - 1][outb - 1] == LLONG_MAX)
			cout << -1 << "\n";
		else
			cout << d[outa - 1][outb - 1] << "\n";
	}
	return 0;
}