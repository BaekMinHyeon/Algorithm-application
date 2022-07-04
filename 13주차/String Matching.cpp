#include <iostream>

using namespace std;

int getZarr(string str, int Z[], string p)
{
	int count = 0; // 패턴의 개수
	int n = str.length(); // pattern+#+입력문자의 길이
	int x, y, i; // 패턴 시작의 index, 끝의 index
	x = y = 0; // 시작과 끝 초기화 0
	for (int k = 1; k < n; ++k)
	{
		//Case 1 (같은 것이 있는지 처음부터 체크해야된다)
		if (k > y)
		{
			x = y = k; 
			while (y < n && str[y - x] == str[y]) // #전까지의 패턴과 str비교
				y++;
			Z[k] = y - x; // 같은 것의 개수
			y--; // ++해주고 같지 않은 것을 체크 하였기 때문에 마지막 같은 것까지 나타내기 위해 1 감소
		}
		else // y >= k
		{
			i = k - x;
			// Case 2
			if (Z[i] < y - k + 1) // y를 넘어가지 않는다
				Z[k] = Z[i]; // 그대로 넣어줌
			else // Z[i] >= y-k+1
			{
				// Case 3 (y까지는 패턴과 일치 그 이후부터 검사)
				x = k;
				while (y < n && str[y - x] == str[y])
					y++;
				Z[k] = y - x; // 같은 것의 개수
				y--; // ++해주고 같지 않은 것을 체크 하였기 때문에 마지막 같은 것까지 나타내기 위해 1 감소
			}
		}
		if (Z[k] == p.length()) // 패턴의 길이와 일치한다. 즉 패턴과 일치
			count++;
	}
	return count;
}

int main() {
	string n; // 입력
	cin >> n;
	int Z[2000001]; // z-array(prefix로 하여 처음부터 시작을 하여 연속적으로 같은 것의 개수) 
	string m; // pattern
	cin >> m;
	string s = m + "#" + n; // pattern+#+입력(pattern과 입력 사이 a-z빼고 아무거나 상관없음)
	cout << getZarr(s, Z, m) << endl; // 패턴의 개수 출력
	return 0;
}