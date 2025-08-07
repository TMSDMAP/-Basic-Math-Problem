#include <iostream>
#include <vector>
using namespace std;
int t, n;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
//a肯定是分子，a2肯定是分母，每次对a2进行约分，看是否能约分到1就行
int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			if (i == 2) continue;
			a[2] = a[2] / gcd(a[2], a[i]);
			if (a[2] == 1) break;
		}
		if (a[2] == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
