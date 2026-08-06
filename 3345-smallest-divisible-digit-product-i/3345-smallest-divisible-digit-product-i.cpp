class Solution {
public:
    int smallestNumber(int n, int t) {
        int x,num;
        for(int i=0;i<=9;i++)
        {
            x=n+i;
            num=1;
            while(x)
            {
                num*=x%10;
                x/=10;
            }
            if(num%t==0) return n+i;
        }
        return 0;
    }
};