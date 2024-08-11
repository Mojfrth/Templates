 bool d(int node,int c){
        v[node]=c;
        vis[node]=1;
        for(auto it:adj[node]){
            if(v[it]==0){
                bool x=d(it,3-c);
                if(x==false)
                return false;
            }
            else if(v[it]==c){
                return false;
            }
        }
        return true;
    }
