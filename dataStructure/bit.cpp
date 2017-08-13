#define N_BIT 
struct BIT{
	ll c[N_BIT];
    int n;
    BIT(int n){        
		memset(c,0,sizeof(c));n=n;
    }
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void modify(int x,ll y){
        for(;x<=n;x+=lowbit(x))
            c[x]+=y;
    }
    inline ll query(int x){
        ll ret=0;
        for(;x;x-=lowbit(x))
            ret+=c[x];
        return ret;
    }
    inline ll query(int l,int r){
        return query(r)-query(l-1);
    }
};
