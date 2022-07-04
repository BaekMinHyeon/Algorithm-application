#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
#define V 2000000
int A[V];
int tree[V];
int B[V];
 
void update(int node, int start, int end, int val)
{
	if (start == end)
	{
		// Leaf node
		tree[node] -= val;
		cout << B[node] << " ";
	}
	else
	{
		int mid = (start + end) / 2;
		if (tree[2*node] >= val)
		{
			update(2 * node, start, mid, val);
		}
		else
		{
			update(2 * node + 1, mid + 1, end, val);
		}
		// Internal node will have the sum of both of its children
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}
 
 
 
void build(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = A[start];
		B[node] = start;
	}
	else
	{
		int mid = (start + end) / 2;
		// Recurse on the left child
		build(2 * node, start, mid);
		// Recurse on the right child
		build(2 * node + 1, mid + 1, end);
		// Internal node will have the sum of both of its children
		tree[node] = max(tree[2 * node],tree[2 * node + 1]);
	}
}
 
int main() {
	int n, m;
	cin >> n >> m;
	int h, r;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		A[i] = h;
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		cin >> r;
		if (tree[1] < r)
			cout << 0 << " ";
		else
			update(1, 1, n, r);
	}
 
	return 0;
}