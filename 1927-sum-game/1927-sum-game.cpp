class Solution {
public:
    bool sumGame(string num) {
        int n,lsum,rsum,lcnt,rcnt;
        lsum=0;
        rsum=0;
        lcnt=0;
        rcnt=0;
        n=num.size();
        for(int i=0;i<n;++i)
        {
            if(num[i]=='?') 
            {
                if(i<n/2) ++lcnt;
                else ++rcnt;
            }
            else
            {
                if(i<n/2) lsum+=num[i]-'0';
                else rsum+=num[i]-'0';
            }
        }
        int total = lcnt+rcnt;
        if(total%2) return true;
        int left=2*lsum+9*lcnt;
        int right=2*rsum+9*rcnt;
        if(left==right) return false;
        return true;
    }
};