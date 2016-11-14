const int NUM = 100;

int M,A[NUM],T[NUM*4];

//    1
//  2   3
// 4 5 6 7
// x 1 2 x
// one-based
void Build(int N){
    while(M=1;M<N+2;M<<=1);
    for(int i=1;i<=N;i++) T[M+i] = A[i];
    for(int i=M-1;i;i--) T[i] = T[i<<1]+T[i<<1|1];
}

// Single modify
void Modify(int x,int d){
    T[x+=M] = d;
    for(x>>1;x;x>>=1) T[x] = T[x<<1]+T[x<<1|1];
}
// Range query
int Query(int L,int R){
    L = L+M-1;R = R+M+1;
    int ans = 0;
    for(;L^R^1;L>>=1,R>>=1){
        if(~L&1) ans += T[L^1];
        if( R&1) ans += T[R^1];
    }
    return ans;
}
