#include <iostream>
#include <vector>
#include <algorithm>

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
        for (int i = 0; i < N; i++) p[i] = i;
        setSizes.assign(N, 1);
    } // vertex ����
    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    } // ������ �ö�(���� ������)
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    } // ���� set�� ������ Ȯ��
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
    } // union(��ħ)
    int setSize(int i) {
        return setSizes[findSet(i)];
    } // set�� ũ��
    int numDisjointSets() {
        return numSets;
    }
};

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.second == b.second)
        return a.first.first < b.first.first;
    return a.second < b.second;
} // weight�� ������ ����, ������ v1 �����ͺ��� ����

int main() {
    int n, m;
    cin >> n >> m;
    UFDS ufds(n);
    vector<pair<pair<int, int>, long>> list(m); // {{v1, v2}, weight} �迭
	int a, b;
    long c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        list[i] = {{ a, b }, c};
	} // v1, v2, weight ����־���
    sort(list.begin(), list.end(), compare);
    long weight = 0; // wight �ʱ�ȭ
    for (int i = 0; i < m; i++) {
        int size1 = ufds.setSize(list[i].first.first); // union�� ũ��
        ufds.unionSet(list[i].first.first, list[i].first.second); // union ����
        int size2 = ufds.setSize(list[i].first.first); // union�� ũ��
        if (size1 != size2) { // ũ�Ⱑ �ٸ��� ������ union���� ������
            weight += list[i].second; // ���� ���� ���� ũ�� 
        }
    }
    if (ufds.setSize(list[0].first.first) == n) {
        cout << weight << "\n";
    } // ��� �� ���� �Ǿ���
    else {
        cout << "IMPOSSIBLE\n";
    }
	return 0;
}