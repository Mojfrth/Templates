ll n;
vector<ll> st;
vector<ll> lazy;
 
void build(ll i,ll l,ll r,vector<ll> &p){
    if(l==r){
        st[i]=p[l];
        return;
    }
    ll mid=l+(r-l)/2;
    build(2*i+1,l,mid,p);
    build(2*i+2,mid+1,r,p);
    st[i]=st[2*i+1]+st[2*i+2];
}
 
void upd(ll i,ll l,ll r,ll s,ll e,ll val){
    if(lazy[i]!=0){
        st[i]+=(r-l+1)*lazy[i];
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>e||r<s||l>r)
    return;
    if(l>=s && r<=e){
        st[i]+=(r-l+1)*val;
        if(l!=r){
            lazy[2*i+1]+=val;
            lazy[2*i+2]+=val;
        }
        return;
    }
    // int mid=(l+r)/2;
    ll mid=l+(r-l)/2;
    upd(2*i+1,l,mid,s,e,val);
    upd(2*i+2,mid+1,r,s,e,val);
    st[i]=st[2*i+1]+st[2*i+2];
}
 
ll query(ll i,ll l,ll r,ll idx){
    if(l>r||l>idx||idx>r)
    return 0;
    if(lazy[i]!=0){
        st[i]+=(r-l+1)*lazy[i];
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l==r)
    return st[i];
    // int mid=(l+r)/2;
    ll mid=l+(r-l)/2;
    if(idx<=mid){
        return query(2*i+1,l,mid,idx);
    }
    else
    return query(2*i+2,mid+1,r,idx);
}
