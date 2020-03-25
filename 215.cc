#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int> > myheap;

		for (int i = 0; i < k; i++) {
			myheap.push(nums[i]);
		}

		for (int i = k; i < nums.size(); i++) {
			if (nums[i] > myheap.top()) {
				myheap.pop();
				myheap.push(nums[i]);
			}
		}

        return  myheap.top();
	}

};
