#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(vector<int> a, int k, int lb, int ub)
{
	int mid = (ub + lb) / 2;
	if (ub < lb)
		return -1;
	if (a[mid] == k)
		return mid;
	if (a[mid] > k)
		return binarySearchRecursive(a, k, lb, mid - 1);
	else
		return binarySearchRecursive(a, k, mid + 1, ub);
}

int binarySearch(vector<int> a, int k)
{
	int st = 0, end = a.size();
	while (st < end)
	{
		int mid = (st + end) / 2;
		if (a[mid] == k)
			return mid;
		if (a[mid] > k)
			end = mid;
		else
			st = mid + 1;
	}
	return -1;
}

string reverseString(string s, int low, int high)
{
	if (low >= high)
		return s;
	swap(s[low], s[high]);
	return reverseString(s, low + 1, high - 1);
}

bool isPalindrome(string s, int low, int high)
{
	if (low >= high)
		return 1;
	if (s[low] == s[high])
		return true;
	else
		return false;
}

int main()
{
	vector<int> a{0, 3, 5, 6, 12, 19};
	int num = 12;
	cout << "Position of " << num << " using binarySearch " << binarySearch(a, num) << endl;
	cout << "Position of " << num << " using binarySearch recursive " << binarySearchRecursive(a, num, 0, a.size()) << endl
		 << endl;

	string str = "shalini_kutiya_hai";
	str = reverseString(str, 0, str.size() - 1);
	cout << str << " = string reversed to = " << reverseString(str, 0, str.size() - 1) << endl;

	str = "10";
	string ans = isPalindrome(str, 0, str.size() - 1) ? "a Palindrome" : "not a palindronme";
	cout << str << " is " << ans << "\n\n";
	return 0;
}