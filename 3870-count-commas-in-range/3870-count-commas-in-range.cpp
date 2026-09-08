class Solution {
public:
    int countCommas(int n) {
        if(n<=999) return 0;
        //if(n<=99999) return n-999;
        //return n-998;
        return n-999;
    }
};