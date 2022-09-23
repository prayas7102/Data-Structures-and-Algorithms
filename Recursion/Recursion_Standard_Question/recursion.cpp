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

void arraySubset(vector<vector<int>> &ans, vector<int> output, int index, vector<int> num)
{
	if (index >= num.size())
	{
		ans.push_back(output);
		return;
	}

	// exclusion of elements
	arraySubset(ans, output, index + 1, num);

	output.push_back(num[index]);

	// inclusion of elements
	arraySubset(ans, output, index + 1, num);
}

void subsetString(vector<string> &ans, string output, int index, string str)
{
	if (index >= str.size())
	{
		ans.push_back(output);
		return;
	}
	// exclusion of elements
	subsetString(ans, output, index + 1, str);
	output.push_back(str[index]);
	// inclusion of elements
	subsetString(ans, output, index + 1, str);
}

void stringPermutation(vector<string> &ans, int index, string str)
{
	if (index >= str.size())
	{
		ans.push_back(str);
		return;
	}
	for (int i = index; i < str.size(); i++)
	{
		swap(str[i], str[index]);
		stringPermutation(ans, index + 1, str);
		swap(str[i], str[index]);
	}
}

int main()
{
	vector<int> a{0, 3, 6, 12};
	int num = 12;
	cout << "Position of " << num << " using binarySearch " << binarySearch(a, num) << endl;
	cout << "Position of " << num << " using binarySearch recursive " << binarySearchRecursive(a, num, 0, a.size()) << endl
		 << endl;

	string str = "shalini_kutiya_hai";
	str = reverseString(str, 0, str.size() - 1);
	cout << str << " = string reversed to = " << reverseString(str, 0, str.size() - 1) << endl
		 << endl;

	str = "10";
	string ans = isPalindrome(str, 0, str.size() - 1) ? "a Palindrome" : "not a palindronme";
	cout << str << " is " << ans << "\n\n";

	vector<vector<int>> answer;
	vector<int> output;
	cout << "Following is the recursive combinations" << endl;
	arraySubset(answer, output, 0, a);
	for (auto i : answer)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	cout << endl;

	string test = "ram";
	string output2;
	vector<string> answer2;
	subsetString(answer2, output2, 0, test);
	cout << "Following is the recursive combinations" << endl;
	for (auto i : answer2)
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}

	cout << endl;

	vector<string> answer3;
	stringPermutation(answer3, 0, test);
	cout << "Following is the recursive permutation" << endl;
	for (auto i : answer3)
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}