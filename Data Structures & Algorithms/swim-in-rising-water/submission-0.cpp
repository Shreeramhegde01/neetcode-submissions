class DUS{
    public:
        vector<int> parent;
        vector<int> size;
        DUS(int n){
            parent.resize(n);
            size.resize(n+1,1);
            iota(parent.begin(),parent.end(),0);
        }
        int find(int a){
            if(a==parent[a]) return a;
            return parent[a]=find(parent[a]);
        }
        void unite(int a,int b){
            a=find(a);
            b=find(b);
            if(size[a]<size[b]) swap(a,b);
            size[a]+=size[b];
            parent[b]=a;
        }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        DUS d(n*n);
        vector<array<int,3>> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr.push_back({grid[i][j],i,j});
            }
        }
        sort(arr.begin(),arr.end());
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
        for(auto&[h,i,j]:arr){
            vis[i][j]=true;
            for(auto [r,c]:dir){
                int nr=r+i;
                int nc=c+j;
                if(nr>=0 and nc>=0 and nr<n and nc<n and vis[nr][nc]) d.unite(nr*n+nc,i*n+j);
            }
            if(d.find(0)==d.find(n*n-1)) return h;
        }
        return 0;
    }
};
