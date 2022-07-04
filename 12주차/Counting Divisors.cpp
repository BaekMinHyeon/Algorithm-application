#include <iostream>
#include <vector>
 
using namespace std;
 
vector<pair<int, int>> count(int n) {
	vector<pair<int, int>> f;
	int c = 1;
	for (int x = 2; x * x <= n; x++) {
		while (n % x == 0) {
			if (f.size() == 0)
				f.push_back(make_pair(x, c));
			else {
				if (x == f[f.size() - 1].first)
					f[f.size()-1].second++;
				else {
					c = 1;
					f.push_back(make_pair(x, c));
				}
			}
			n /= x;
		}
	}
	c = 1;
	if (n > 1) f.push_back(make_pair(n, c));
	return f;
 
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> f;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		f = count(x);
		int have = 1;
		for (int j = 0; j < f.size(); j++)
			have *= (f[j].second+1);
		cout << have << endl;
	}
}