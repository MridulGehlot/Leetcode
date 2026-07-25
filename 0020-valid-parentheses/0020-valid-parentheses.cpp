class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> mp;
        mp['(']=1;
        mp[')']=-1;
        mp['{']=2;
        mp['}']=-2;
        mp['[']=3;
        mp[']']=-3;
        stack<int> stk;
        for(char ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[') stk.push(mp[ch]);
            else
            {
                if(stk.empty()) return false;
                int a=stk.top();
                stk.pop();
                if((a+mp[ch])!=0) return false;
            }
        }
        return stk.empty();
    }
};