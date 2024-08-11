void dfs(int node,int par){
   for(auto it:adj[node]){
       if(it!=par){
           l[it]=1+l[node];
           dfs(it,node);
       }
   }
}
int main() {
  int n;
  cin>>n;
  adj.assign(n,{});
  l.assign(n,0);
  rep(i,0,n-1){
      int x,y;
      cin>>x>>y;
      x--;
      y--;
      adj[x].pb(y);
      adj[y].pb(x);
  }
  dfs(0,-1);
  int ln=0;
  rep(i,0,n){
    //   cout<<l[i]<<" ";
      if(l[i]>l[ln])
      ln=i;
  }
  l.assign(n,0);
  dfs(ln,-1);
  int k=*max_element(l.begin(),l.end());
  cout<<k;    
    return 0;
}
