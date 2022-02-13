
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <functional>

using namespace std;


template<typename T>
class cmp : public binary_function<T, T, bool> {
public:
	inline bool operator()(const T &lhs, const T &rhs) const {
		return lhs >= rhs;
	}
};

class Solution {
public:
	int hIndex(vector<int> &citations) {
		if (citations.empty()) {
			return 0;
		}
		std::sort(citations.begin(), citations.end());
		int left = *citations.begin();
		int right = *citations.rbegin();
		int res = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			int counts = std::count_if(citations.begin(), citations.end(), bind2nd(cmp<int>(), mid));
			if (counts <= mid) {
				res = std::max(res, counts);
				right = mid - 1;
			} else {
				res = std::max(res, mid);
				left = mid + 1;
			}
		}
		return res;
	}
};

int main() {
	std::vector<int> citations = {3, 0, 6, 1, 5};
	Solution solution{};
	assert(solution.hIndex(citations) == 3);
	return 0;
}
