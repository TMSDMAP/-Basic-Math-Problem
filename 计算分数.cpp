#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
char s[105];
ll fenzi[105], fenmu[105];
ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int i = 0;
int k = 0;
void trans()
{
	ll sum = 0;
	while (s[i] != '/')
	{
		sum = sum * 10 + s[i] - '0';
		i++;
	}
	fenzi[k] = sum;
	i++; sum = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		sum = sum * 10 + s[i] - '0';
		i++;
	}
	fenmu[k] = sum;
	k++;
}

int main()
{
	cin >> s;
	int len = strlen(s);


	if (s[0] != '-')
	{
		trans();
	}

	while (i < len)
	{
		if (s[i] == '+')
		{
			i++;
			trans();
		}
		else if (s[i] == '-')
		{
			i++;
			trans();
			fenzi[k - 1] = -fenzi[k - 1];
		}
	}
	/*int m = 2;
	ll g1 =fenmu[0]*fenmu[1]/gcd(fenmu[0], fenmu[1]);
	while (m <k)
	{
		g1 = g1*fenmu[m]/gcd(g1, fenmu[m]);
		m++;
	}
	cout << g1 << endl;
	ll sum2 = 0;
	for (int j = 0; j < k; j++)
	{
		sum2 += fenzi[j] * g1 / fenmu[j];
	}
	ll t = gcd(abs(sum2), g1);
	ll t1 = sum2 / t;
	ll t2 = g1 / t;
	if(t2!=1)
	cout << t1 << '/' << t2 << endl;
	else
		cout << t1 << endl;*/
	ll res_num = fenzi[0], res_den = fenmu[0];  //逐步累加分子和分母
	for (int j = 1; j < k; j++)
	{
		ll a = res_num, b = res_den;
		ll c = fenzi[j], d = fenmu[j];
		ll lcm = b / gcd(b, d) * d;  //每次求最小公倍数
		res_num = a * (lcm / b) + c * (lcm / d);  //分子相加
		res_den = lcm;  //分母为最小公倍数
		ll g = gcd(abs(res_num), res_den);  //化简分数
		res_num /= g;
		res_den /= g;
	}
	ll g = gcd(abs(res_num), res_den);  //注意可能不进循环（只有一个分数时），仍需要化简
	res_num /= g;
	res_den /= g;
	if (res_den != 1)
		cout << res_num << '/' << res_den << endl;
	else
		cout << res_num << endl;


	return 0;
}
/* 更优化的版本
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void parseFraction(const char* s, int& i, ll& num, ll& den) {
	int sign = 1;
	if (s[i] == '-') { sign = -1; i++; }
	num = 0; den = 0;
	while (isdigit(s[i])) num = num * 10 + (s[i++] - '0');
	i++;
	while (isdigit(s[i])) den = den * 10 + (s[i++] - '0');
	num *= sign;
}

int main() {
	char s[1005];
	cin >> s;
	int len = strlen(s), i = 0;
	ll res_num, res_den;
	parseFraction(s, i, res_num, res_den);
	ll g = gcd(abs(res_num), res_den);
	res_num /= g;
	res_den /= g;
	while (i < len) {
		char op = s[i++];
		ll num, den;
		parseFraction(s, i, num, den);
		ll lcm = res_den / gcd(res_den, den) * den;
		if (op == '+')
			res_num = res_num * (lcm / res_den) + num * (lcm / den);
		else if (op=='-')
			res_num = res_num * (lcm / res_den) - num * (lcm / den);
		res_den = lcm;
		ll g = gcd(abs(res_num), res_den);
		res_num /= g;
		res_den /= g;
		if (res_den < 0)
		{
			res_num = -res_num;
			res_den = -res_den;
		}
	}
	if (res_den != 1)
		cout << res_num << '/' << res_den << endl;
	else
		cout << res_num << endl;
	return 0;
}
*/