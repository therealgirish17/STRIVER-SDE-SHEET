class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_one_zero=0; //Check if there is zero in first row
        int row_tot = matrix.size(); 
        int col_tot = matrix[0].size();
        
        for(int i=0; i<col_tot; i++) {
            if(matrix[0][i]==0) {
                row_one_zero=1; //Set row_one_zero to 1 if zero exist in first row
            }
        }
        
        for(int i=1; i<row_tot; i++) {
            for(int j=0; j<col_tot; j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0]=0; //Starting from second row, iterating through all columns, if there is zero, then set the first element of the corresponding row and col to 0
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1; i<row_tot; i++) {
            if(matrix[i][0]==0) {
                for(int j=0; j<col_tot; j++) {
                    matrix[i][j]=0; //Starting from the second row, if any row has first entry as 0, set all the entries in that row as 0
                }
            }
        }
        
        for(int i=0; i<col_tot; i++) {
            if(matrix[0][i]==0) {
                for(int j=0; j<row_tot; j++) {
                    matrix[j][i]=0; //Similarly for col, if first entry of the col is 0, set all the entries in that col to 0
                }
            }
        }
        
        if(row_one_zero==1) {
            for(int i=0; i<col_tot; i++) {
                matrix[0][i]=0; //If the first row contain 0, then set all the entries of the first row to 0
            }
        }
    }
    // Time Complexity: O(N^2)
    // Space complexity: O(1)
};
