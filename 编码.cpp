#include <iostream>
#include <string>
using namespace std;

int comb(int n, int m) {
	if (m<0 || m>n) return 0;
	int res = 1;
	for (int i = 1; i <= m; i++)
		res = res * (n - i + 1) / i;
	return res;
}
// 顺序是a...z,ab...az,bc...bz,......
//要先从小于长度len开始统计，从字符串中选n个字符，他们的排列方式是固定的，所以是组合
//再考虑长度相等的，从左到右，只要左边小，右边就任意，也是组合数
int main() {
	string s;
	cin >> s;
	int len = s.length();
	if (len > 6)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < len; ++i) {
		if (s[i] <= s[i - 1])
		{
			cout << 0 << endl;
			return 0;
		}
	}
	int ans = 0;
	for (int i = 1; i < len; i++)
		ans += comb(26, i);
	int p = -1;
	for (int i = 0; i < len; ++i) {
		for (char c = p + 1+'a'; c < s[i]; ++c) {
			ans += comb(26 - (c - 'a' + 1), len - i - 1);
		}
		p = s[i] - 'a';
	}
	ans += 1;
	cout << ans << endl;
	return 0;
}