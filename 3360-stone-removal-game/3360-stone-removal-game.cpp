class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        if(n>=19 && n<=26) return false;
        if(n>=34 && n<=39) return false;
        if(n>=45 && n<=48) return false;
        return true;
    }
};