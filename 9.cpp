/*
Problem 9
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

*/ 

// Solution

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	string num = to_string(x); // find the correct function to do this
		int size = num.size();
		int i = 0;
		bool value = true;
		while(i < size / 2){
			if(num[i] == num[size-1-i]){
				i++;
			}
			else{
				value = false;
				return value;
				exit;
			}
		}
		return value;
    }
};

int main(){
	int x = 122231;
	Solution sol;
	cout << sol.isPalindrome(x) << endl;
	return 0;
}