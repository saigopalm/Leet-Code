/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int modulus = pow(10,9) + 7;

        vector<int> memo_0(n, 0);
        vector<int> memo_1(n, 0);

        for(int j = 0; j < n; j++){
            memo_0[j] = arr[j];
            sum += memo_0[j];
        }

        for(int i = 1; i < n; i++){
            for(int j = i; j < n; j++){
                if(i % 2 == 1){
                    memo_1[j] = min(memo_0[j-1], memo_0[j]);
                    sum += memo_1[j];
                }
                else{
                    memo_0[j] = min(memo_1[j-1], memo_1[j]);
                    sum += memo_0[j];
                }
            }
            sum = sum % modulus;
        }

        return sum;
    }
};

int main(){

    Solution sol;

    vector<int> arr = {11,81,94,43,3};

    cout << sol.sumSubarrayMins(arr);
}