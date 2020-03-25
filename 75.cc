#include <iostream>
#include <map>
#include <queue>

class solution{
public:
	void sortColors(vector<int>& nums) {
        vector<int> vec(3);
        for (int i = 0; i < nums.size(); i++) {
            ++vec[nums[i]];
        }
        int k = 0;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i]; j++) {
                nums[k++] = i;
            }
        }
    }
};
