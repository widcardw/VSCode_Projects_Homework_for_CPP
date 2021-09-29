#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,cnt,ans;
int f[N];
struct Edge{
    int a,b,w;
    bool operator <(const Edge &W) const{
        return w<W.w;
    }
}edges[N];
int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i].a=a;edges[i].b=b;edges[i].w=c;
    }
    for(int i=1;i<=n;i++) f[i]=i;
    sort(edges,edges+m);
   // for(int i=0;i<m;i++) cout<<edges[i].w<<endl;
    for(int i=0;i<m;i++){
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        if(find(a)!=find(b)){
            cnt++;
            ans+=w;
            f[find(a)]=find(b);
        }
    }
    if(cnt<n-1) cout<<"impossible"<<endl;
    else cout<<ans<<endl;
   // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    // cout<<ans<<endl;
}
