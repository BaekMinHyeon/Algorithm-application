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
    } // vertex 생성
    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    } // 맨위로 올라감(맨위 작은값)
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    } // 같은 set에 들어가는지 확인
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
    } // union(합침)
    int setSize(int i) {
        return setSizes[findSet(i)];
    } // set의 크기
    int numDisjointSets() {
        return numSets;
    }
};

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.second == b.second)
        return a.first.first < b.first.first;
    return a.second < b.second;
} // weight로 작은것 부터, 같으면 v1 작은것부터 정렬

int main() {
    int n, m;
    cin >> n >> m;
    UFDS ufds(n);
    vector<pair<pair<int, int>, long>> list(m); // {{v1, v2}, weight} 배열
	int a, b;
    long c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        list[i] = {{ a, b }, c};
	} // v1, v2, weight 집어넣어줌
    sort(list.begin(), list.end(), compare);
    long weight = 0; // wight 초기화
    for (int i = 0; i < m; i++) {
        int size1 = ufds.setSize(list[i].first.first); // union전 크기
        ufds.unionSet(list[i].first.first, list[i].first.second); // union 실행
        int size2 = ufds.setSize(list[i].first.first); // union후 크기
        if (size1 != size2) { // 크기가 다르기 때문에 union으로 합쳐짐
            weight += list[i].second; // 연결 가장 작은 크기 
        }
    }
    if (ufds.setSize(list[0].first.first) == n) {
        cout << weight << "\n";
    } // 모두 다 연결 되었다
    else {
        cout << "IMPOSSIBLE\n";
    }
	return 0;
}