#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
	int  NumberOf1(int n) {
		int i = 0;
		int x = 1;
		int count = 0;
		for (i = 0; i < 32; i++)
		{
			if ((n & (x << i)) != 0)
			{
				count++;
			}
		}
		return count;

	}
};
int main()
{
	int n = 0;
	Solution a;
	cin >> n;
	cout << a.NumberOf1(n) << endl;
	return 0;
}