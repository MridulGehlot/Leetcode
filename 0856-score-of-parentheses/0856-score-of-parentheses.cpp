class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        int depth=0;
        char prev='\0';
        for(char ch:s)
        {
            if(ch=='(') ++depth;
            else
            {
                --depth;
                if(prev=='(') score+=(1<<depth);
            }
            prev=ch;
        }
        return score;
    }
};