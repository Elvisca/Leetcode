#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/* 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。

   一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
*/

/*
  输入:
  [[10,16], [2,8], [1,6], [7,12]]

  输出:
  2

  解释:
  对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
*/

class Solution {
public:
	static bool mysort(vector<int> &a, vector<int> &b) {
		return (a.at(1) < b.at(1));
	}

    int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0) {
			return 0;
		}

		sort(points.begin(), points.end(), [] (vector<int> &a, vector<int> &b) {
											   return (a.at(1) < b.at(1));});
		int ans = 1, m_p;
		m_p = points[0][1];
		for (auto p : points) {
			if (p[0] <= m_p) {
				continue;
			}
			ans++;
			m_p = p[1];
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{

	return 0;
}
