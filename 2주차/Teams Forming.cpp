#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	int min = 0;
	cin >> n;
	while (n < 2 && n > 100 || n % 2 == 1) {
		cin >> n;
	}
	vector<int> arr(n);
	for (int i = 0; i < arr.size(); i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		if (i % 2 == 1)
			min += arr[i] - arr[i - 1];
	}
	cout << min;

}