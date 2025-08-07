#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n, R;
int main()
{
	string ans;
	cin >> n >> R;
	if (n == 0) ans = "0";
	int n1 = n;
	while (n != 0)
	{
		int r = n % R;
		n /= R;
		if (r < 0)
		{
			r += abs(R);
			n += 1;
		}
		if(r<10)
			ans += to_string(r);
		else
			ans += char('A' + r - 10);
	}
	reverse(ans.begin(), ans.end());
	string Ans;
	Ans =to_string(n1) + "=" + ans + "(base" + to_string(R) + ")";
	cout << Ans << endl;
	return 0;
}