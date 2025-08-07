#include <iostream>
#include <cmath>
using namespace std;
#define int long long
int a, b, c;
int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

signed main()
{
	cin >> a >> b >> c;
	int g = a/gcd(a, b)*b;
	g = g/gcd(g, c)*c;
	printf("%lld",g);
}