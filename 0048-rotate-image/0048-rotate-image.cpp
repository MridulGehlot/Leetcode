class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int l,r;
        l=0;
        r=rows-1;
        while(l<r)
        {
            swap(matrix[l],matrix[r]);
            l++;
            r--;
        }
        for(int i=0;i<rows;++i)
        {
            for(int j=i;j<cols;++j)
            {
                if(i==j) continue;
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};