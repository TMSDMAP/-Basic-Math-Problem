#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <string>
using namespace std;

long long n;
int main()
{
	cin >> n;
	string res;
	res = bitset<32>(n).to_string();
	string ans1 = res.substr(0, 16);
	string ans2 = res.substr(16, 16);
	string ans = ans2 + ans1;
	long long num = stoll(ans, nullptr, 2);
	cout << num << endl;
}
