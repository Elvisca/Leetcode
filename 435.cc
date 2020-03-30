#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/* 贪心算法思路 顾名思义先拿到一个有效的，然后迭代比较有更好的就替换
   步骤：1.将区间按照结束的值进行升序排列
		 2.排序后的队列从头向后遍历，如果后继节点的起始大于前节点的结束，说明有重叠，
			按照逻辑，选取剩余空间更大的范围，即选择前节点
		 3.遍历完成后得到最大的可用范围个数，使用总个数减去最大范围个数就是结果
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
		if (intervals.size() == 0) {
			return 0;
		}

		sort(intervals.begin(), intervals.end(), mysort);
		int prev, curr = 1;
		prev = intervals.at(0).at(1);
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals.at(i).at(0) < prev) {
				continue;
			}
			prev = intervals.at(i).at(1);
			curr++;
		}
		return (intervals.size() - curr);
	}

	bool mysort(vector<int> &v1, vector<int> &v2) {
		return (v1.at(1) < v2.at(1));
	}
};

class Solution1 {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
		if (intervals.size() == 0) {
			return 0;
		}

		sort(intervals.begin(), intervals.end(), mysort);
		vector<int> vec(intervals.size());
		vec[0] = 1;
		int ans = 1;
		for (int i = 1; i < intervals.size(); i++) {
			int m_max = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (intervals.at(j).at(1) < intervals.at(i).at(0)) {
					m_max = max(m_max, vec[j]);
					break;
				}
			}
			vec[i] = max(m_max + 1, vec[i - 1]);
			ans = max(ans, vec[i]);
		}
		return (intervals.size() - ans);
	}

	bool mysort(vector<int> &v1, vector<int> &v2) {
		return (v1.at(1) < v2.at(1));
	}
};

int main(int argc, char *argv[])
{

	return 0;
}
