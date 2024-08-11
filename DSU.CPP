class DSU {
        public:
        vector<int>par,size;
        DSU(int n)
        {
            par=vector<int>(n);
            size=vector<int>(n,1);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        
        int find(int x)
        {
            if(par[x]==x)return x;
            return par[x]=find(par[x]);
        }
        
        void Union(int a,int b)
        {
            a=find(a);
            b=find(b);
            if(a!=b){
                if(size[a]<size[b])
                    swap(a,b);
                par[b]=a;
                size[a]+=size[b];
            }
        }
    };
    
