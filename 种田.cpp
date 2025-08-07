#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	while(b) {
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
}
int main() {
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	while (x > 0 && y > 0) {
		if (x < y) swap(x, y);
		ll cnt = x / y; // 一次性放cnt个y*y正方形
		ans += 4 * y*cnt;
		x =x % y;
	}
	cout << ans << endl;
	return 0;
}