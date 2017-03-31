int ExMultiply(int a,int b,int n){
    a %= n;b %= n;
    int r = 0;
    while(b){
        if(b&1)r = ((a+r >= n)? a+r-n : a+r);
        a = ((a+a >= n)? a+a-n : a+a);
        b >>= 1;
    }
    return r;
}

int ExExPower(int a,int d,int n){
    if(d == 0)return 1;
    int k = ExExPower(a,d/2,n);
    if(d%2)return ExMultiply(ExMultiply(k,k,n),a,n);
    return ExMultiply(k,k,n);
}

bool MillerRabin(int n,int a){
    if(__gcd(n,a) == n)return true;
    if(__gcd(n,a) != 1)return false;
    // a^(d*2^r)
    int d = n-1, r = 0;
    while(d%2 == 0){ d /= 2;r++; }
    // a^d = ? (mod n)
    int remain = ExExPower(a,d,n);
    if(remain == 1 || remain == n-1)return true;
    while(r--){
        remain = ExMultiply(remain,remain,n);
        if(remain == n-1)return true;
    }
    return false;
}

bool IsPrime(int n){
    int a[7] = {2,325,9375,28178,450775,9780504,1795265022};
    for(int i=0;i<7;i++)if(!MillerRabin(n,a[i]))return false;
    return true;
}
