class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int x=i;
            while(x)
            {
                if(x&1) ans[i]++;
                x>>=1;
            }
        }
        return ans;
    }
};