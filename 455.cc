#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		int gi = 0,si = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		while (gi < g.size() && si < s.size()) {
			if (g.at(gi) <= s.at(si)) {
				gi++;
			}
			si++;
		}
		return gi;
	}
};

int main(int argc, char *argv[])
{

	return 0;
}
