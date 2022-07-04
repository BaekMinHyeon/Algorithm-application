#include <iostream>

using namespace std;

int getZarr(string str, int Z[], string p)
{
	int count = 0; // ������ ����
	int n = str.length(); // pattern+#+�Է¹����� ����
	int x, y, i; // ���� ������ index, ���� index
	x = y = 0; // ���۰� �� �ʱ�ȭ 0
	for (int k = 1; k < n; ++k)
	{
		//Case 1 (���� ���� �ִ��� ó������ üũ�ؾߵȴ�)
		if (k > y)
		{
			x = y = k; 
			while (y < n && str[y - x] == str[y]) // #�������� ���ϰ� str��
				y++;
			Z[k] = y - x; // ���� ���� ����
			y--; // ++���ְ� ���� ���� ���� üũ �Ͽ��� ������ ������ ���� �ͱ��� ��Ÿ���� ���� 1 ����
		}
		else // y >= k
		{
			i = k - x;
			// Case 2
			if (Z[i] < y - k + 1) // y�� �Ѿ�� �ʴ´�
				Z[k] = Z[i]; // �״�� �־���
			else // Z[i] >= y-k+1
			{
				// Case 3 (y������ ���ϰ� ��ġ �� ���ĺ��� �˻�)
				x = k;
				while (y < n && str[y - x] == str[y])
					y++;
				Z[k] = y - x; // ���� ���� ����
				y--; // ++���ְ� ���� ���� ���� üũ �Ͽ��� ������ ������ ���� �ͱ��� ��Ÿ���� ���� 1 ����
			}
		}
		if (Z[k] == p.length()) // ������ ���̿� ��ġ�Ѵ�. �� ���ϰ� ��ġ
			count++;
	}
	return count;
}

int main() {
	string n; // �Է�
	cin >> n;
	int Z[2000001]; // z-array(prefix�� �Ͽ� ó������ ������ �Ͽ� ���������� ���� ���� ����) 
	string m; // pattern
	cin >> m;
	string s = m + "#" + n; // pattern+#+�Է�(pattern�� �Է� ���� a-z���� �ƹ��ų� �������)
	cout << getZarr(s, Z, m) << endl; // ������ ���� ���
	return 0;
}