#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll f[1000005];
ll sum = 0;
int main()
{
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j <= n; j += i) {
			f[j]++;
		}
	} // 约数反演，直接统计每个数被作为约数的次数
	for (ll i = 1; i <= n; i++)
		sum += f[i];
	cout << sum << endl;
	return 0;
}