#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;
//gcd*lcm=a*b
int gcd1(int a, int b)
{
	if (b == 0) return a;
	return gcd1(b, a % b);
}

int main()
{
	int count = 0;
	int x0, y0;
	cin >> x0 >> y0;
	for (int i = x0; i <= y0; i++)
	{
		if ((x0 * y0) % i != 0) continue;
		int j = (x0 * y0) / i;
		if (gcd1(i, j) == x0) count++;
	}
	cout << count << endl;
	return 0;
}