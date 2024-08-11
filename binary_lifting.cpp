 dp=vector<vector<ll>>(n,vector<ll>(21,-1));
void dfs(ll node,ll n){
	    for(int i = 0; i < n; i++)
            dp[i][0] = par[i];
 
        for(int h = 1; h <20; h++)
            for(int i = 0; i < n; i++)
                if( dp[i][h-1] != -1)
                    dp[i][h] = dp[dp[i][h-1]][h-1];
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
    ll n,q;
    cin>>n>>q;
    par.assign(n,-1);
    adj.assign(n,{});
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
    dfs(0,n);
    rep(i,0,q){
        ll u,v;
        cin>>u>>v;
        u--;
        ll k=binlift(u,v);
        if(k!=-1)
        cout<<k+1<<endl;
        else
        cout<<k<<endl;
    }

