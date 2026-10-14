class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>(num*9)) return "";
        string ans="";
        while(ans.size()<num)
        {
            if(sum>9)
            {
                ans+='9';
                sum-=9;
            }
            else
            {
                ans+=sum+'0';
                sum=0;
            }
        }
        return ans;
    }
};