class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        for(int x:arr1)
        {
            bool valid=true;
            for(int y:arr2)
            {
                int res=abs(x-y);
                if(res<=d) valid=false;
            }
            if(valid) ++cnt;
        }
        return cnt;
    }
};