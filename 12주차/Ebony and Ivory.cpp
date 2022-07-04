#include <iostream>
#include <string.h>
#include <tuple>
#include <cmath>

using namespace std;

//gcd와 그 gcd에 맞는 x, y를 구하는 함수
tuple<int, int, int> gcd(int a, int b){
    if (b == 0){
        return {1, 0, a};
    } else {
        int x, y, g;
        tie(x, y, g) = gcd(b, a%b);
        return {y, x-(a/b)*y, g};
    }
}

int main()
{
    //입력
    int a, b, c;
    cin >> a >> b >> c;

    //gcd를 이용해 x, y, g를 구함
    int x, y, g;
    if (a < b) tie(y, x, g) = gcd(b, a);
    else tie(x, y, g) = gcd(a, b);
    if( c % g != 0) {
        cout << "No";
        return 0;
    }
    //cout << x << y << g;
    //gcd와 c간의 비율을 찾아주고
    //그것으로 c에 대한 x, y를 찾아줌
    int ratio = c / g;
    int realX = x * ratio;
    int realY = y * ratio;

    //c에 대한 x, y를 가지고 디오판토스 방정식을 이용해 
    //0보다 큰 k 정수가 있는지 확인해서 있으면 yes 없으면 no를 출력해준다.
    double k1, k2;
    k1 = ceil(g*(-realX)/(double)b);
    k2 = floor(g*(realY)/(double)a);
    if(k2 - k1 >= 0) cout << "Yes";
    else cout << "No";
    return 0;
}
