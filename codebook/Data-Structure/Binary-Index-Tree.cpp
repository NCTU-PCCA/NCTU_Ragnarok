/*
can   single update, range query sum
can't insert, delete
*/

struct BIT{
    vector<int> val;
    
    inline int lsb(int x){ return x & -x; }
    
    int sum(int x){
        int s = 0;
        while(x > 0){
            s += val[x];
            x -= lower_bit(x);
        }
        return s;
    }

    void update(int x,int d){
        while(x <= A.size()){
            val[x] += d;
            x += lower_bit(x);
        }
    }

    int query(int a,int b){
        if(a > b) swap(a,b);
        return sum(b)-sum(a-1);
    }
};

struct BITRMQ{
    vector<int> val,LT,RT;
    
    BITRMQ(){}
    BITRMQ(int n,int v):val(n+1,v){
        LT.resize(n+1); RT.resize(n+1);
        for(int i=0;i<=n;i++) LT[i] = RT[i] = i;
    }

    inline int lsb(int x){ return x & -x; }

    int query(int a,int b){
        if(a >= SZ(LT) or b >= SZ(LT) or a < 1 or b < 1) while(1);
        int s = LLONG_MAX,i = a,x = a,y = b;

        while(x + lsb(x) <= b){
            if(s > val[RT[x]]){ s = val[RT[x]]; i = RT[x]; }
            x += lsb(x);
        }
        if(s > val[x]){ s = val[x]; i = x; }
        while(y != x){
            if(s > val[LT[y]]){ s = val[LT[y]]; i = LT[y]; }
            y -= lsb(y);
        }
        
        return i;
    }

    void _magic(int now,int x,int d,bool LR){
        vector<int> &T = LR ? LT : RT;
        if(T[now] != x){ if(val[T[now]] > d) T[now] = x; }
        else{
            int a = now,b = now;
            if(LR) a = now - lsb(now) + 1;
            else b = min(SZ(T)-1,now + lsb(now) - 1);
            if(a <= x-1){
                int s = query(a,x-1);
                if(val[s] < d) T[now] = s;
            }
            if(x+1 <= b){
                int s = query(x+1,b);
                if(val[s] < d) T[now] = s;
            }
        }
    }

    void update(int x,int d){
        val[x] = d;
        for(int now=x;now<=SZ(val);now+=lsb(now)) _magic(now,x,d,true);
        for(int now=x;now>0;now-=lsb(now)) _magic(now,x,d,false);
    }
};
