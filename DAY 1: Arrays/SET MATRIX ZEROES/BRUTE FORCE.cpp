class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, col;  //Using set because this avoid duplicates in row and col
        int row_tot = matrix.size();
        int col_tot = matrix[0].size();
        
        for(int i=0; i<row_tot; i++) {
            for(int j=0; j<col_tot; j++) {
                if(matrix[i][j]==0) {
                    row.insert(i);  //If the entry is zero, we store its row number and col number
                    col.insert(j);
                }
            }
        }
        
        set<int>::iterator itr;
        for(itr=row.begin(); itr!=row.end(); itr++) {
            for(int i=0; i<col_tot; i++) {
                matrix[*itr][i]=0; //Making all entries 0 in the row stored
            }
        }
        for(itr=col.begin(); itr!=col.end(); itr++) {
            for(int i=0; i<row_tot; i++) {
                matrix[i][*itr]=0; //Making al entries 0 in the col stored
            }
        }
       // Time complexity: O(N^2)
       // Space complexity: O(max(row_tot, col_tot))
    }
};
