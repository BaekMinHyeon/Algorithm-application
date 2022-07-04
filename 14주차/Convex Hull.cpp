#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	} // x좌표가 같으면 y좌표 작은 것 먼저
	else {
		return a.first < b.first;
	} // x 좌표 작은 순
}

int main() {
	int n; // point의 개수
	cin >> n;
	vector<pair<int, int>> point;
	vector<pair<int, int>> convex_up; // 위 테두리
	vector<pair<int, int>> convex_down; // 아래 테두리
	int x, y; // x, y좌표
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		point.push_back(make_pair(x, y)); // 좌표 추가
	}
	sort(point.begin(), point.end(), comp); // 정렬(x좌표 작은 것, 같으면 y좌표 작은 것)
	convex_up.push_back(make_pair(point[0].first, point[0].second)); // 첫번째 좌표
	convex_up.push_back(make_pair(point[1].first, point[1].second)); // 두번째 좌표
	int k = convex_up.size(); // k = 윗 테두리를 이루는 개수
	// 윗 테두리 만듦
	for (int i = 2; i < n; i++) { // 3번째 좌표부터 모든 좌표 돎
		while (k >= 2) { // 윗 테두리 이르는 것 2개 이상 필요(외적을 하기위해 3개가 필요하기 때문(확인하는 좌표까지 포함))
			pair<long, long> a = make_pair(convex_up[k - 1].first - convex_up[k - 2].first, convex_up[k - 1].second - convex_up[k - 2].second); // 윗 테두리 벡터로 연결
			pair<long, long> b = make_pair(point[i].first - convex_up[k-1].first, point[i].second - convex_up[k - 1].second); // 윗 테두리 연결된 화살표에서 이어서 테두리가 되는지 확인하는 좌표 벡터로 연결
			if (a.first*b.second - a.second*b.first > 0) { // 외적 : 반시계 방향(왼쪽에 있음) => 더 바깥쪽 테두리가 된다
				convex_up.pop_back(); // 윗 테두리에서 제거
				k--; // 윗 테두리 개수 감소
				continue; // break 안하기 위해 continue 사용
			}
			break;
		}
		convex_up.push_back(make_pair(point[i].first, point[i].second)); // 윗 테두리에 추가
		k++; // 윗 테두리 개수 증가
	}
	convex_down.push_back(make_pair(point[0].first, point[0].second)); // 첫번째 좌표
	convex_down.push_back(make_pair(point[1].first, point[1].second)); // 두번째 좌표
	k = convex_down.size(); // k = 아래 테두리를 이루는 개수
	// 아래 테두리 만듦
	for (int i = 2; i < n; i++) { // 3번째 좌표부터 모든 좌표 돎
		while (k >= 2) { // 아래 테두리 이르는 것 2개 이상 필요(외적을 하기위해 3개가 필요하기 때문(확인하는 좌표까지 포함))
			pair<long, long> a = make_pair(convex_down[k - 1].first - convex_down[k - 2].first, convex_down[k - 1].second - convex_down[k - 2].second); // 아래 테두리 벡터로 연결
			pair<long, long> b = make_pair(point[i].first - convex_down[k - 1].first, point[i].second - convex_down[k - 1].second); // // 아래 테두리 연결된 화살표에서 이어서 테두리가 되는지 확인하는 좌표 벡터로 연결
			if (a.first * b.second - a.second * b.first < 0) { // 외적 : 시계 방향(오른쪽에 있음) => 더 바깥쪽 테두리가 된다
				convex_down.pop_back(); // 아래 테두리에서 제거
				k--; // 아래 테두리 개수 감소
				continue; // break 안 들어가기 위해 사용
			}
			break; 
		}
		convex_down.push_back(make_pair(point[i].first, point[i].second)); // 아래 테두리 추가
		k++; // 아래 테두리 개수 증가
	}
	//convex_up과 down이 시작과 끝 겹치기 때문에 삭제 필요
	convex_down.erase(convex_down.begin(), convex_down.begin() + 1); // 시작삭제
	convex_down.pop_back(); // 끝삭제
	
	cout << convex_up.size() + convex_down.size() << endl; // 테두리를 이루는 개수 출력
	for (int i = 0; i < convex_up.size(); i++)
		cout << convex_up[i].first << " " << convex_up[i].second << endl; // 위 테두리 좌표 출력
	for (int i = 0; i < convex_down.size(); i++)
		cout << convex_down[i].first << " " << convex_down[i].second << endl; // 아래 테두리 좌표 출력
	return 0;
}