/*
  680. 验证回文字符串 Ⅱ

 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

 示例 1:

 输入: "aba"
 输出: True
 示例 2:

 输入: "abca"
 输出: True
 解释: 你可以删除c字符。
 注意:

 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int p1 = 0, p2 = s.size() - 1;
        int diff = 0;
        /* bool res = true; */
        while (p1 <= p2) {
            if (s[p1] != s[p2]) {
				return isvalidPalindrome(s, p1 + 1, p2) || isvalidPalindrome(s, p1, p2 - 1);
			}
			p1++;
			p2--;
        }
        return true;
    }

	bool isvalidPalindrome(string s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--]) {
				return false;
			}
		}
		return true;
	}
};


int main(int argc, char *argv[])
{
	Solution ms;
	ms.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
	return 0;
}
