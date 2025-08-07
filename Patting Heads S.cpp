#include <iostream>
#include <cmath>
using namespace std;
#define int long long
int N;
int A[100005];
int sum[100005];
int cnt[1000005];
signed main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		cnt[A[i]]++; //统计每个数字出现了多少次
	}
	for (int i = 0; i < N; i++)
	{
		int res = 0;
		int x = A[i];
		for (int d = 1; d * d <= x; d++)  //枚举每个数字的所有约数
		{
			if (x % d == 0)
			{
				res += cnt[d];
				if (d != x / d) res += cnt[x / d]; //如果d和x/d不相等，则需要加上x/d的出现次数
			}
		}
		res--; //d=1时会多加一次
		cout << res << endl;
	}
	return 0;
}