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

	// inclusion of elements
	output.push_back(num[index]);
	arraySubset(ans, output, index + 1, num);

	// exclusion of elements
	output.pop_back();
	arraySubset(ans, output, index + 1, num);
}

void subsetSum(vector<int> &ans, int sum, int index, vector<int> num)
{
	if (index >= num.size())
	{
		ans.push_back(sum);
		return;
	}

	// picking of elements
	subsetSum(ans, sum + num[index], index + 1, num);

	// not picking of elements
	subsetSum(ans, sum, index + 1, num);
}

// leetcode https://leetcode.com/problems/combination-sum/
// each element can be repeated to sum up equal to the target variable.
void CombinationSum(int index, vector<int> arr, vector<int> output, vector<vector<int>> &ans, int target)
{
	if (index >= arr.size())
	{
		if (0 == target)
		{
			ans.push_back(output);
		}
		return;
	}

	if (arr[index] <= target)
	{
		output.push_back(arr[index]);

		// index remains same to preserve repetition
		CombinationSum(index, arr, output, ans, target - arr[index]);

		output.pop_back();
	}
	// index is changed to get other elements
	CombinationSum(index + 1, arr, output, ans, target);
}

// leetcode https://leetcode.com/problems/combination-sum-ii/
// each element cannot be repeated.
void CombinationSumNoRepition(vector<vector<int>> &ans, vector<int> output, int index, vector<int> arr, int target)
{
	if (index >= arr.size())
	{
		if (target == 0)
			ans.push_back(output);
		return;
	}

	if (arr[index] <= target)
	{

		// inclusion of elements
		output.push_back(arr[index]);
		CombinationSumNoRepition(ans, output, index + 1, arr, target - arr[index]);

		// exclusion of elements
		output.pop_back();
	}
	CombinationSumNoRepition(ans, output, index + 1, arr, target);
}

void subsetString(vector<string> ans, string output, int index, string str)
{
	if (index >= str.size())
	{
		ans.push_back(output);
		return;
	}
	subsetString(ans, output, index + 1, str);
	// inclusion of elements
	output.push_back(str[index]);
	subsetString(ans, output, index + 1, str);
	// automatic exclusion of last elements
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
		// backtracking
		swap(str[i], str[index]);
	}
}

void keypadCombinations(string digit, int index, string output, vector<string> mapping, vector<string> &collection)
{
	if (index >= digit.length())
	{
		collection.push_back(output);
		return;
	}

	int num = digit[index] - '0';
	string val = mapping[num];

	for (int i = 0; i < val.length(); ++i)
	{
		output.push_back(val[i]);
		keypadCombinations(digit, index + 1, output, mapping, collection);
		// backtracking
		output.pop_back();
	}
}

void inline printVectorString(vector<string> s)
{
	for (auto i : s)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
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
	printVectorString(answer2);

	cout << endl;

	vector<string> answer3;
	stringPermutation(answer3, 0, test);
	cout << "Following is the recursive permutation" << endl;
	printVectorString(answer3);

	cout << endl;

	cout << "KeyPad Problem" << endl;
	vector<string> mapping{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	test = "34";
	vector<string> collection;
	output2 = "";
	keypadCombinations(test, 0, output2, mapping, collection);
	printVectorString(collection);
	cout << endl;

	vector<int> ans0;
	int sum = 0;
	cout << "Following is the subsetSum" << endl;
	subsetSum(ans0, sum, 0, a);
	for (auto i : ans0)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}