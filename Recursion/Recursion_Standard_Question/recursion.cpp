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
// int cou=INT_MAX;
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

void subsetString(vector<string> &ans, string output, int index, string str)
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

void nQueen(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &left, vector<int> &upperDiag, vector<int> &lowerDiag, int n)
{
	if (col == n)
	{
		ans.push_back(board);
		return;
	}

	for (int row = 0; row < n; row++)
	{
		if (!left[row] && !lowerDiag[row + col] && !upperDiag[n - 1 + col - row])
		{
			board[row][col] = 'Q';
			left[row] = 1;
			lowerDiag[row + col] = 1;
			upperDiag[n - 1 + col - row] = 1;
			nQueen(col + 1, board, ans, left, upperDiag, lowerDiag, n);
			board[row][col] = '.';
			left[row] = 0;
			lowerDiag[row + col] = 0;
			upperDiag[n - 1 + col - row] = 0;
		}
	}
}

void palindromePartition(int ind, vector<vector<string>> &ans, vector<string> &pal, string s)
{
	if (ind == s.length())
	{
		ans.push_back(pal);
		return;
	}
	for (int i = ind; i < s.length(); ++i)
	{

		if (isPalindrome(s, ind, i))
		{
			pal.push_back(s.substr(ind, i - ind + 1));
			palindromePartition(i + 1, ans, pal, s);
			pal.pop_back();
		}
	}
}

bool isValidSudoku(vector<vector<char>> &board)
{
	int row[9][9] = {0}, col[9][9] = {0}, grid_3x3[9][9] = {0};

	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] != '.')
			{
				int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
				if (row[i][num] || col[j][num] || grid_3x3[k][num])
					return false;
				row[i][num] = col[j][num] = grid_3x3[k][num] = 1;
			}

	return true;
}

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
			return 0;
	}
	return 1;
}

bool solveSudoku(vector<vector<char>> &board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == '.')
			{
				for (char c = '1'; c <= '9'; c++)
				{
					if (isValid(board, i, j, c))
					{
						board[i][j] = c;
						if (solve(board))
							return 1;
						else
							board[i][j] = '.';
					}
				}
				return 0;
			}
		}
	}
	return true;
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

	string str = "ramisgod";
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

	string test = "amr";
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

	vector<vector<string>> ans1;
	int n = 8;
	string s(n, '.');
	vector<string> board(n, s);
	vector<int> left(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
	nQueen(0, board, ans1, left, upperDiag, lowerDiag, n);
	cout << endl;

	cout << "Palindrome Partition for 23" << endl;
	vector<vector<string>> ans00;
	vector<string> pal;
	string s = "aabb";
	palindromePartition(0, ans00, pal, s);
	for (auto a : ans00)
	{
		for (auto b : a)
		{
			cout << b << ", ";
		}
		cout << endl;
	}
	cout << endl;

	vector<int> v{5, 8, 10, 6};
	vector<int> out;
	vector<vector<int>> ans11;
	cout << "CombinationSum for 23" << endl;
	CombinationSum(0, v, out, ans11, 23);
	for (auto a : ans11)
	{
		for (auto b : a)
		{
			cout << b << ", ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}