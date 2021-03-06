#include <iostream>
#include <vector>

using namespace std;

class UFDS {
private:
	vector<int> p, rank, setSizes;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
			}
			else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
			numSets--;
		}
	}
	int SetSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	UFDS ufds(n);
	int a, b;
	int max = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
                            a--;
                            b--;
		ufds.unionSet(a, b);
		if (ufds.SetSize(a) > max)
			max = ufds.SetSize(a);
		cout << ufds.numDisjointSets() << " " << max << endl;
	}


	return 0;
}