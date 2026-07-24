class Solution {
public:
    int reverseBits(int n) {
        long x=0;
        for(int i=0;i<32;i++)
        {
            x<<=1;
            if(n&1) x|=1;
            n>>=1;
        }
        return x;
    }
};