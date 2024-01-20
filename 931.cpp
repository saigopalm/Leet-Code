/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is 
either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> memo(n, vector<int>(n,0));

        // Initializing the first row same as given matrix
        for(int j = 0; j < n; j++){
            memo[0][j] = matrix[0][j];
        }

        for(int i=1; i < n; i++){
            for(int j=0; j < n; j++){
                if(j != 0 && j != n-1){
                    memo[i][j] = matrix[i][j] + min(memo[i-1][j], min(memo[i-1][j+1], memo[i-1][j-1]));
                }
                else if(j == 0){
                    memo[i][j] = matrix[i][j] + min(memo[i-1][j], memo[i-1][j+1]);
                }
                else if(j == n-1){
                    memo[i][j] = matrix[i][j] + min(memo[i-1][j], memo[i-1][j-1]);
                }
            }
        }

        int minsum_falling_path = memo[n-1][0];
        for(int j = 0; j < n; j++){
            if(memo[n-1][j] < minsum_falling_path){
                minsum_falling_path = memo[n-1][j];
            }
        }

        return minsum_falling_path;     
    }
};

int element(vector<vector<int>> &matrix);

int main(){

    vector<vector <int>> matrix1 {{2,1,3},{6,5,4},{7,8,9}};
    vector<vector <int>> matrix2 {{-19,57},{-40,-5}};

    Solution sol;
    cout << sol.minFallingPathSum(matrix1) << endl;
    cout << sol.minFallingPathSum(matrix2) << endl;

    // element(matrix);

    
}


int element(vector<vector<int>> &matrix){
    cout << matrix.size() << endl;
    return 0;
}