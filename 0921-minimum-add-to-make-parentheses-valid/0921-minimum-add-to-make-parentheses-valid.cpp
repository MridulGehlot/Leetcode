class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int cnt=0;
        for(char ch:s)
        {
            if(ch=='(') stk.push(ch);
            else 
            {
                if(stk.empty()) ++cnt;
                else stk.pop();
            }
        }
        return cnt+stk.size();
    }
};