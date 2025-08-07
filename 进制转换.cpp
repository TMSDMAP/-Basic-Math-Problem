#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int main()
{
	cin >> n;
	char s[100];
	cin >> s;
	int len = strlen(s);
	int ans = 0;
	int m1 = 1;
	for (int i = len-1; i >=0; i--)
	{
		int t;
		if (s[i] >= '0' && s[i] <= '9')
			t = s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			t = s[i] - 'A' + 10;
		ans += t * m1;
		m1 *= n;
	}
	int m;
	cin >> m;
	char s1[100];
	for (int i = 0;; i++)
	{
		if (ans <= 0)
		{
			s1[i] = '\0';
			break;
		}
		int t = ans % m;
		if (t < 10)
			s1[i] = t + '0';
		else
			s1[i] = t - 10 + 'A';
		ans /= m;
	}
	
	int len1 = strlen(s1);
	for(int i = len1 - 1; i >= 0; i--)
	{
		cout << s1[i];
	}
	return 0;
}
