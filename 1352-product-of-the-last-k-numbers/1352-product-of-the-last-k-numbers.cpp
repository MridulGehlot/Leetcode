class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0) v.clear();
        else
        {
            int x=1;
            if(!v.empty()) x=v.back();
            v.push_back(num*x);
        }
    }
    
    int getProduct(int k) {
        if(v.empty() || k>v.size()) return 0;
        if(k==v.size()) return v[k-1];
        int i=v.size()-k-1;
        return v.back()/v[i];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */