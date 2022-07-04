#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<pair<long, long>> point;
	long x, y;
	long area = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			area += point[i].first * point[0].second - point[0].first * point[i].second;
		}
		else {
			area += point[i].first * point[i + 1].second - point[i + 1].first * point[i].second;
		}
	}
	cout << abs(area) << endl;
 }