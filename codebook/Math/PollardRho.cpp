int PollardRho(int n,int c){
    int x = 2,y = 2, k = 2;
    for(int i=2;;i++){
        x = (x * x + c) % n;
        int d = __gcd(x-y,n);
        if(d > 1) return d;
        if(i == k){ y = x;k <<= 1; }
    }
}
