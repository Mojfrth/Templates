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
