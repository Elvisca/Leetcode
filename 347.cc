#include <iostream>
#include <map>
#include <queue>

class solution{
public:
	vector<int> topKFrequent(vector<int> nums, int k) {
		unordered_map<int, int> record;
		for(int i = 0; i < nums.size(); i++) {
			record[nums[i]]++;
		}

		unordered_map<int, int>::iterator iter = record.begin();

		priority_queue<pair<int ,int>, vector< pair<int ,int> >, greater< pair<int ,int> > > myheap;
		for (; iter != record.end(); iter++) {
			if (myheap.size() == k) {
				if (iter->second > myheap.top().first) {
					myheap.pop();
					myheap.push(pair(iter->second, iter->first));
				}
			} else {
				myheap.push(pair(iter->second, iter->first));
			}
		}
		vector<int> vec;
		for (int i = 0; i < k; i++) {
			vec.push_back(myheap.top().second);
			myheap.pop();
		}
		return vec;
	}
};
