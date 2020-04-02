#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
   假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

   注意：
   总人数少于1100人。
*/

/*
  输入:
  [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

  输出:
  [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [] (vector<int> &a, vector<int> &b) {
											   return (a[0] == b[0] ? a[1] < b[1]: a[0] > b[0]);});
											   /* return (a[0]>b[0] ? true:(a[0]==b[0] ?(a[1]<b[1]):false));}); */
		list<vector<int>> tmp;
		for (auto p : people) {
			auto pos = tmp.begin();
			advance(pos, p[1]);
			tmp.insert(pos, p);
		}
		return vector<vector<int>> (tmp.begin(), tmp.end());
	}
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [] (vector<int> &a, vector<int> &b) {
											   return (a[0] == b[0] ? a[1] < b[1]: a[0] > b[0]);});
		int len = people.size();
		list<vector<int>> tmp;
		for (int i = 0;  i < len; i++) {
			auto pos = tmp.begin();
			advance(pos, people[i][1]);
			tmp.insert(pos, people[i]);
		}
		return vector<vector<int>> (tmp.begin(), tmp.end());
	}
};

int main(int argc, char *argv[])
{

	return 0;
}
