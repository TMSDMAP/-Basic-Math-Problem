
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int max_id = N * (N - 1) / 2;
	vector<set<int>> dp(N + 1);  //s是不同情况下交点数减少的数量
	dp[0].insert(0); //初始状态，没有点，交点数为0
	for (int i = 1; i <= N; ++i) {
		for (int s : dp[i - 1]) dp[i].insert(s); //不加入平行组
		for (int m = 2; m <= i; m++) { //加入平行组
			int delta = m * (m - 1) / 2;
			for (int s : dp[i - m]) {
				dp[i].insert(s + delta);  //加入平行组后减少的交点数增加了
			}
		}
	}
	set<int> result;
	for (int s : dp[N]) {
		result.insert(max_id - s); //计算不同情况下的交点数
	}
	cout << result.size() << endl;  //输出不同交点数的数量
	return 0;
}


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, Max = -1, ans = 0;
bool f[10005];
void dfs(int n, int k)
{
	if (n == 0) {
		f[k] = true;
		Max = max(Max, k);
	}
	else
		for (int r = n; r >= 1; r--)
			dfs(n - r, r * (n - r) + k);
}
 //也可以用递归+记忆化搜索
int main() {
	cin >> n;
	memset(f, false, sizeof f);
	dfs(n, 0);
	for (int i = 0; i <= Max; i++)
		if (f[i]) ans++;
	cout << ans << endl;
	return 0;
}