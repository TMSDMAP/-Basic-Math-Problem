#include <iostream>
using namespace std;
#define int long long
int n, m, k,t;
int f[2005][2005];
int ans[2005][2005];
signed main()
{
	cin >> t >> k;
	for (int i = 0; i <= 2000; i++)
		f[i][0] = 1;
	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= 2000; j++) {
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j])%k;
			if (f[i][j] == 0&&i>=j) ans[i][j]++;
			ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
		}
	}
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				cout << f[i][j] << " ";
			}
			cout << endl;
		}  //前缀和是前面的累计，j>i时也会不为0，所以上面要把所有ans求出来
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}	
		cout << ans[n][m] << endl;
	}
	return 0;
}