class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<=9) return true;
        long dummy=0;
        long tmp=x;
        while(tmp)
        {
            dummy=dummy*10+tmp%10;
            tmp/=10;
        }
        return dummy==x;
    }
};