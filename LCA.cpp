void dfs(ll node,ll l){
	    dp[node][0]=par[node];
	    lev[node]=l;
	    repe(i,1,20){
	        if(dp[node][i-1]!=-1)
	        dp[node][i]=dp[dp[node][i-1]][i-1];
	    }
	    for(auto it:adj[node]){
	        if(it!=par[node]){
	            dfs(it,l+1);
	        }
	    }
	}
	
	ll binlift(ll node,ll k){
	  for (int i = 20;i>=0;i--) 
        { 
            if ((k>>i) & 1) 
            { 
                node = dp[node][i]; 
                if (node == -1) 
                    return -1; 
            } 
        }
        return node;
	} 
	
	ll lca(ll a,ll b){
	    if(lev[a]<lev[b]){
	        swap(a,b);
	    }
	    ll k=lev[a]-lev[b];
	    a=binlift(a,k);
	    if(a==b)
	    return a;
	    for(int i=20;i>=0;i--){
	        if(dp[a][i]!=dp[b][i]){
	            a=dp[a][i];
	            b=dp[b][i];
	        }
	    }
	    return dp[a][0];
	}
int main() 
{ 
    ll n,q;
    cin>>n>>q;
    par.assign(n,-1);
    adj.assign(n,{});
    lev.assign(n,0);
    dp=vector<vector<ll>>(n,vector<ll>(21,-1));
    // vector<vector<ll>> dp(n,vector<ll>(20,0));
    rep(i,1,n){
        ll u;
        cin>>u;
        u--;
        adj[u].pb(i);
        adj[i].pb(u);
        par[i]=u;
    }
    dfs(0,0);
    rep(i,0,q){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        ll k=lca(u,v);
        if(k!=-1)
        cout<<k+1<<endl;
        else
        cout<<k<<endl;
    }
