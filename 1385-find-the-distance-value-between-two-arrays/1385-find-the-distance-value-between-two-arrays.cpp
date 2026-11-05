class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int cnt=0;
        for(int x:arr1)
        {
            bool valid=true;
            int l,m,h;
            l=0;
            h=arr2.size()-1;
            while(l<=h && valid)
            {
                m=(l+h)/2;
                int diff=abs(arr2[m]-x);
                if(diff<=d) valid=false;
                if(arr2[m]>x) h=m-1;
                else l=m+1;
            }
            if(valid) ++cnt;
        }
        return cnt;
    }
};