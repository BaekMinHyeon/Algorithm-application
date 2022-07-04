#include <iostream>

int main(){
	long long n;
	std::cin >> n;
	while (true) {
		printf("%lld ", n);
		if (n == 1)
			break;
		if (n % 2 == 0) {
			n = n / 2;
		}
		else {
			n = 3 * n + 1;
		}
	}

}