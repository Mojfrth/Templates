vector<vector<ll>> adj;
vll sub;
 
void dl(ll u, ll p) {
    sub[u] = 1;
    for (auto it : adj[u]) {
        if (it != p) {
            dl(it, u);
            sub[u] += sub[it];
        }
    }
}
 
ll f(ll u, ll p) {
    for (auto it : adj[u]) {
        if (it != p) {
            if (sub[it] > sub.size() / 2) {
                return f(it, u);
            }
        }
    }
    return u;
}
dl(0,-1);
f(0,-1);
