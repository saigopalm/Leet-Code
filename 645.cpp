/*
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and 
return them in the form of an array.

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int y = 0; // got replaced
        int x = 0; // duplicate
        int n = nums.size();
        int N = (n * (n+1)) / 2;
        vector<int> duplicates(n, 1);

        for(const int num : nums){
            N -= num;

            if(duplicates[num - 1] == 0){
                x = num;
            }
            else{
                duplicates[num - 1] = 0;
            }
        }

        y = x + N;

        vector<int> sol = {x,y};
        
        return sol;

    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,2,4};
    vector<int> arr1 = sol.findErrorNums(arr);
    
    cout << arr1[0] << "," << arr1[1] << endl;
    return 0;
}