/*
 * Problem 58
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_size = s.size();
        int length=0, i = s_size - 1;

        if(isspace(s[i])){
            while(isspace(s[i])){
                i--;
            }
        }
        while(!isspace(s[i]) & i >= 0){
            length++;
            if(i != 0){
                i--;
            }
            else{
                break;
            }
        }
        return length;
    }
    
};

int main(){
    
    string str = "sairam";
    Solution sol;
    int len = sol.lengthOfLastWord(str);
    cout << len;
    return 0;
}
