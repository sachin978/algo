#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define um unordered_map
#define sz size
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(),x.end()
#define scanvector(v,n) int n;cin>>n;vector<int> v(n);fr(i,0,n) cin>>v[i];
#define int_max INT_MAX
#define int_min INT_MIN
#define null NULL
const int M = 1e9 + 7;

const int N = 1001;
int a[N][N];
vector<vector<int>> adjmat(N,vector<int>(N,INT_MAX));
vector<int> adjlist[N],revadjlist[N],adjlist2[N],cadjlist[N];
vector<int> vis(N),dfsvis(N),height(N),depth(N),level(N),d(N,INT_MIN);
vector<int> parent(N),size(N),color(N),indegree(N);
int lca[N][N];

void dfs(int v,int p){
    parent[v]=p;
    for(auto c:adjlist[v]){
        if(c!=p){
            level[c]=level[v]+1;
            dfs(c,v);
        }
    }
}

int LCA(int a,int b,int ln){
    if(level[a]<level[b]) swap(a,b);
    int d = level[a]-level[b];
    while(d){
        int i = log2(d);
        a = lca[a][i];
        d-=(1<<i);
    }
    if(a==b) return a;
    for(int i=ln;i>=0;i--){
        if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i]){
            a=lca[a][i];
            b=lca[b][i];
        }
    }
    return parent[a];
}

int main() {
    int n;cin>>n;
    fr(i,0,n-1){
        int a,b;cin>>a>>b;
        adjlist[a].pb(b);
        adjlist[b].pb(a);
    }

    // for LCA --> LCA[N][logN] tabel then LCA(a,b) function , for LCA[i][0] , bfs to store parents of all
    // LCA[N+1][logN + 1]
    
    int ln = log2(n)+1;
    memset(lca,-1,sizeof(lca));
    
    
    dfs(1,-1);
    fr(i,1,n+1) lca[i][0] = parent[i];
    
    fr(i,1,n+1){
        fr(j,1,ln+1){
            if(lca[i][j-1]!=-1)
                lca[i][j] = lca[lca[i][j-1]][j-1];
        }
    }
    
    int q;cin>>q;
    while(q--){
        int d,x,y;cin>>d>>x>>y;
        int a = LCA(x,y,ln);
        int ans = 0;
        if( (a==x && d==0) || (a==y && d==1) ) ans=1;
        ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}
