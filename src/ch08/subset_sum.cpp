#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <climits>

using namespace std;

const int UNKNOWN = INT_MAX;

#define DEBUG 0
#if DEBUG
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets)
{
	if (index == set.size())
	{
		allSubsets[subset.size()].push_back(subset);
		return;	
	}

	GetAllSubsets(set, subset, index + 1, allSubsets);

	subset.push_back(set[index]);
	GetAllSubsets(set, subset, index + 1, allSubsets);
}

bool SubsetSum_BruteForce(vector<int> set, int target)
{
	vector<vector<vector<int>>> allSubsets(set.size() + 1);

	GetAllSubsets(set, {}, 0, allSubsets);

	for (int size = 0; size <= set.size(); size++)
	{
		PRINT("subset count: " << size << endl);

		for (auto subset : allSubsets[size])
		{
			PRINT("\t{}");

			int sum = 0;
			for (auto number : subset)
			{
				sum += number;
				PRINT(number << " ");
			}
			PRINT(" } = " << sum << endl);

			if (sum == target)
				return true;
		}
	}

	return false;
}

bool SubsetSum_Backtracking(vector<int>& set, int sum, int i)
{
	if (sum == 0)
	{
		return true;
	}

	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	return SubsetSum_Backtracking(set, sum - set[i], i + 1)
		|| SubsetSum_Backtracking(set, sum, i + 1);

}

bool SubsetSum_Memoization(vector<int>& set, int sum, int i, vector<vector<int>>& memo)
{
	if (sum == 0)
	{
		return true;
	}

	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	if (memo[i][sum] == UNKNOWN)
	{
		bool append  = SubsetSum_Memoization(set, sum - set[i], i + 1, memo);
		bool ignore  = SubsetSum_Memoization(set, sum, i + 1, memo);

		memo[i][sum] = append || ignore;
	}

	return memo[i][sum];
}

vector<string> types = 
{
	"BRUTE FORCE",
	"BACKTRACKING",
	"MEMOZATION",
	"TABULATION"
};

void GetTime(clock_t& timer, string type)
{
	timer = clock() - timer;

	cout << type << " duration: ";
	cout << fixed << setprecision(5) << (float)timer / CLOCKS_PER_SEC << endl;

	timer = clock();
}

int main()
{
	vector<int> set = {16, 1058, 22, 13, 46, 55, 3, 92, 47, 7,
		98, 367, 807, 106, 333, 85, 577, 9, 3059};

	int target = 6799;
	int tests = 3;

	sort(set.begin(), set.end());

	for (int i = 0; i < tests; i++)
	{
		bool found = false;

		clock_t timer = clock();

		switch (i)
		{
			case 0:
				found = SubsetSum_BruteForce(set, target);
				break;
			case 1:
				found = SubsetSum_Backtracking(set, target, 0);
				break;
			case 2:
				vector<vector<int>> memo(set.size(), vector<int>(7000, UNKNOWN));
				found = SubsetSum_Memoization(set, target, 0, memo);
				break;
		}

		if (found)
		{
			cout << "sum: " << target << " is exist" << endl;
		}
		else
		{
			cout << "sum: " << target << " is not exist" << endl;
		}

		GetTime(timer, types[i]);
		cout << endl;
	}
}
