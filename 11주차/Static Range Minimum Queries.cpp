#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define V 2000000
int tree[2*V];
int A[V];
 
 
// segment tree
int m(int node, int start, int end, int l, int r)
{
	if (r < start or end < l)
	{
		return INT32_MAX;
	}
	if (l <= start and end <= r)
	{
		return tree[node];
	}
	// range represented by a node is partially inside and partially outside the given range
	int mid = (start + end) / 2;
	int left = m(2 * node, start, mid, l, r);
	int right = m(2 * node + 1, mid + 1, end, l, r);
	return min(left, right);
}
 
 
// segment tree
void build(int node, int start, int end)
{
	if (start == end)
	{
		// Leaf node will have a single element
		tree[node] = A[start];
	}
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}
int main() {
	int n, q;
	cin >> n >> q;
	int value;
	for (int i = 1; i <= n; i++) {
		cin >> value;
		A[i] = value;
	}
	build(1, 1, n);
	int a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << m(1, 1, n, a, b) << endl;
	}
	return 0;
}