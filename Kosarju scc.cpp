//For finding we can reach from node a to node b in directed graph

vvll scc;
vll t;
vi p;
vvll adj;
vvll adjt;
vb vis;
stack<ll> s;
 
void dfs(ll node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            // p[it]=node;
            dfs(it);
        }
    }
    s.push(node);
}
void dfs2(ll node){
    vis[node]=1;
    t.pb(node);
    for(auto it:adjt[node]){
        if(!vis[it]){
            // p[it]=node;
            dfs2(it);
        }
    }
    // s.push(node);
}

ll n,m;
   cin>>n>>m;
   adj.assign(n,{});
   adjt.assign(n,{});
   vis.assign(n,false);
   rep(i,0,m){
       ll x,y;
       cin>>x>>y;
       x--;
       y--;
       adj[x].pb(y);
       adjt[y].pb(x);
   }
   for(int i=0;i<n;i++){
       if(!vis[i]){
           dfs(i);
       }
   }
   rep(i,0,n){
       vis[i]=false;
   }
   while(!s.empty()){
       int node=s.top();
       s.pop();
       if(!vis[node]){
           dfs2(node);
           scc.pb(t);
           t.clear();
       }
   }
   if(scc.size()==1)
   yes
   else{
       no
       cout<<scc[1][0]+1<<" "<<scc[0][0]+1;
   }
