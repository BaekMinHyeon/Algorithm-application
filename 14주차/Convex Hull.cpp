#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	} // x��ǥ�� ������ y��ǥ ���� �� ����
	else {
		return a.first < b.first;
	} // x ��ǥ ���� ��
}

int main() {
	int n; // point�� ����
	cin >> n;
	vector<pair<int, int>> point;
	vector<pair<int, int>> convex_up; // �� �׵θ�
	vector<pair<int, int>> convex_down; // �Ʒ� �׵θ�
	int x, y; // x, y��ǥ
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		point.push_back(make_pair(x, y)); // ��ǥ �߰�
	}
	sort(point.begin(), point.end(), comp); // ����(x��ǥ ���� ��, ������ y��ǥ ���� ��)
	convex_up.push_back(make_pair(point[0].first, point[0].second)); // ù��° ��ǥ
	convex_up.push_back(make_pair(point[1].first, point[1].second)); // �ι�° ��ǥ
	int k = convex_up.size(); // k = �� �׵θ��� �̷�� ����
	// �� �׵θ� ����
	for (int i = 2; i < n; i++) { // 3��° ��ǥ���� ��� ��ǥ ��
		while (k >= 2) { // �� �׵θ� �̸��� �� 2�� �̻� �ʿ�(������ �ϱ����� 3���� �ʿ��ϱ� ����(Ȯ���ϴ� ��ǥ���� ����))
			pair<long, long> a = make_pair(convex_up[k - 1].first - convex_up[k - 2].first, convex_up[k - 1].second - convex_up[k - 2].second); // �� �׵θ� ���ͷ� ����
			pair<long, long> b = make_pair(point[i].first - convex_up[k-1].first, point[i].second - convex_up[k - 1].second); // �� �׵θ� ����� ȭ��ǥ���� �̾ �׵θ��� �Ǵ��� Ȯ���ϴ� ��ǥ ���ͷ� ����
			if (a.first*b.second - a.second*b.first > 0) { // ���� : �ݽð� ����(���ʿ� ����) => �� �ٱ��� �׵θ��� �ȴ�
				convex_up.pop_back(); // �� �׵θ����� ����
				k--; // �� �׵θ� ���� ����
				continue; // break ���ϱ� ���� continue ���
			}
			break;
		}
		convex_up.push_back(make_pair(point[i].first, point[i].second)); // �� �׵θ��� �߰�
		k++; // �� �׵θ� ���� ����
	}
	convex_down.push_back(make_pair(point[0].first, point[0].second)); // ù��° ��ǥ
	convex_down.push_back(make_pair(point[1].first, point[1].second)); // �ι�° ��ǥ
	k = convex_down.size(); // k = �Ʒ� �׵θ��� �̷�� ����
	// �Ʒ� �׵θ� ����
	for (int i = 2; i < n; i++) { // 3��° ��ǥ���� ��� ��ǥ ��
		while (k >= 2) { // �Ʒ� �׵θ� �̸��� �� 2�� �̻� �ʿ�(������ �ϱ����� 3���� �ʿ��ϱ� ����(Ȯ���ϴ� ��ǥ���� ����))
			pair<long, long> a = make_pair(convex_down[k - 1].first - convex_down[k - 2].first, convex_down[k - 1].second - convex_down[k - 2].second); // �Ʒ� �׵θ� ���ͷ� ����
			pair<long, long> b = make_pair(point[i].first - convex_down[k - 1].first, point[i].second - convex_down[k - 1].second); // // �Ʒ� �׵θ� ����� ȭ��ǥ���� �̾ �׵θ��� �Ǵ��� Ȯ���ϴ� ��ǥ ���ͷ� ����
			if (a.first * b.second - a.second * b.first < 0) { // ���� : �ð� ����(�����ʿ� ����) => �� �ٱ��� �׵θ��� �ȴ�
				convex_down.pop_back(); // �Ʒ� �׵θ����� ����
				k--; // �Ʒ� �׵θ� ���� ����
				continue; // break �� ���� ���� ���
			}
			break; 
		}
		convex_down.push_back(make_pair(point[i].first, point[i].second)); // �Ʒ� �׵θ� �߰�
		k++; // �Ʒ� �׵θ� ���� ����
	}
	//convex_up�� down�� ���۰� �� ��ġ�� ������ ���� �ʿ�
	convex_down.erase(convex_down.begin(), convex_down.begin() + 1); // ���ۻ���
	convex_down.pop_back(); // ������
	
	cout << convex_up.size() + convex_down.size() << endl; // �׵θ��� �̷�� ���� ���
	for (int i = 0; i < convex_up.size(); i++)
		cout << convex_up[i].first << " " << convex_up[i].second << endl; // �� �׵θ� ��ǥ ���
	for (int i = 0; i < convex_down.size(); i++)
		cout << convex_down[i].first << " " << convex_down[i].second << endl; // �Ʒ� �׵θ� ��ǥ ���
	return 0;
}