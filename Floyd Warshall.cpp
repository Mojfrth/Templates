 ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> dis(n,vector<ll>(n,1e18));
    rep(i,0,n){
        dis[i][i]=0;
    }
    rep(i,0,m){
        ll x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        dis[x][y]=min(dis[x][y],w);
        dis[y][x]=min(dis[y][x],w);
    }
   for(int k=0;k<n;k++){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
           }
       }
   }
   while(q--){
       ll x,y;
       cin>>x>>y;
       x--;
       y--;
       if(dis[x][y]==1e18)
       cout<<-1<<endl;
       else
       cout<<dis[x][y]<<endl;
   }
