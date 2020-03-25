#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#if 0
class solution{
public:
	string frequencySort(string s) {
		unordered_map<char, int> record;
		for(int i = 0; i < s.size(); i++) {
			record[s[i]]++;
		}

		unordered_map<char, int>::iterator iter = record.begin();

		priority_queue<pair<int ,char>, vector< pair<int ,char> >, less< pair<int ,char> > > myheap;
		for (; iter != record.end(); iter++) {
			myheap.push(pair(iter->second, iter->first));
		}
		string str;
		str.reserve(s.size());
		while(!myheap.empty()) {
			for (int i = 0; i < myheap.top().first; i++) {
				str += myheap.top().second;
			}
			myheap.pop();
		}
		return str;
	}
};
#endif

class solution{
public:
	string frequencySort(string s) {
		vector<int> vec1(128);
		for(int i = 0; i < s.size(); i++) {
			++vec1[s.at(i)];
		}

		vector<int> vec2(128);
		for(int i = 0; i < vec2.size(); i++) {
			vec2.at(i)  = i;;
		}

		sort(vec2.begin(), vec2.end(),
			 [&vec1](const char &c1, const char &c2) {
				 return vec1[c1] > vec1[c2];
			 });

		string str;
		str.reserve(s.size());
		for (int i = 0; i < vec2.size(); i++) {
			if (vec1.at(vec2.at(i)) == 0) {
				break;
			}
			for (int k = 0; k < vec1.at(vec2.at(i)); k++) {
				str += vec2.at(i);
			}
		}
		return str;
	}
};

int main(int argc, char *argv[])
{
	solution sol;
	string mystr("tree");
	string tmp = sol.frequencySort(mystr);

	cout << tmp << endl;
	return 0;
}
