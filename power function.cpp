const  int MOD=1e9+7;
 
unsigned ll power(ll x,ll y,ll int p=MOD){
    unsigned ll res=1;
    x=x%p;
    while(y){
        if(y&1){
            res=(res*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}
