#include <iostream>
#include <algorithm>
using namespace std;
long long n;
long long a[52];
const long long MOD = 1e9 + 7;
int main()
{
	cin >> n;
	for(int i = 0;i<n;i++)
		cin >> a[i];
	sort(a, a + n);
	long long ans = 1;
	for (int i = 0; i < n; i++)
	{
		ans = (ans * (a[i] - i)) % MOD;
	}
	cout << ans << endl;
	return 0;
}
