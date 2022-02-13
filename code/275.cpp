#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool cmp(int lhs, int rhs) {
	return lhs >= rhs;
}

class Solution {
public:
	int hIndex(vector<int> &citations) {
		if (citations.empty()) {
			return 0;
		}
		int left = *citations.begin();
		int right = *citations.rbegin();
		int res = 0;
		while (left <= right) {
			int mid = (left + right) / 2; //分数
			int counts = count_if(citations.begin(), citations.end(), bind2nd(ptr_fun(cmp), mid)); //数量
			if (counts <= mid) {
				res = std::max(counts, res);
				right = mid - 1;
			} else {
				res = std::max(mid, res);
				left = mid + 1;
			}
		}
		return res;
	}
};

int main() {
	Solution solution{};
	{
		std::vector<int> citations = {100};
		assert(solution.hIndex(citations) == 1);
	}
	{
		std::vector<int> citations = {0, 1, 3, 5, 6};
		assert(solution.hIndex(citations) == 3);
	}
	{
		std::vector<int> citations = {0};
		assert(solution.hIndex(citations) == 0);
	}
	{
		std::vector<int> citations = {1, 1};
		assert(solution.hIndex(citations) == 1);
	}
	{
		std::vector<int> citations = {0, 1};
		assert(solution.hIndex(citations) == 1);
	}
	return 0;
}
