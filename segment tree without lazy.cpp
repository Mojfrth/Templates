class NumArray {
public:
    int n;
    vector<int> st;
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n);
        build(0,0,n-1,nums);
    }
    void build(int i,int l,int r,vector<int> &nums){
        if(l==r){
            st[i]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        st[i]=st[2*i+1]+st[2*i+2];
    }
    void upd(int idx,int val,int i,int l,int r){
        if(l==r){
            st[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid){
            upd(idx,val,2*i+1,l,mid);
        }
        else{
            upd(idx,val,2*i+2,mid+1,r);
        }
         st[i]=st[2*i+1]+st[2*i+2];
    }
    int query(int s,int e,int i,int l,int r){
        if(l>e||r<s)
            return 0;
        if(l>=s && r<=e)
            return st[i];
        int mid=(l+r)/2;
        return query(s,e,2*i+1,l,mid)+query(s,e,2*i+2,mid+1,r);
    }
    
    void update(int idx, int val) {
        upd(idx,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
       return query(left,right,0,0,n-1);
    }
};
