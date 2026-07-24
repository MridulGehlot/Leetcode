class Solution {
public:
    int hammingWeight(int n) {
        int x,cnt;
        x=n;
        cnt=0;
        while(x)
        {
            if(x&1) cnt++;
            x>>=1;
        }
        return cnt;
    }
};