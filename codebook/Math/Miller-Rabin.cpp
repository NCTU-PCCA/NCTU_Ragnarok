bool MillerRabin(int a,int n){
    if(a == n)return true;
    if(__gcd(a,n) != 1)return false;
    int s = 0,d = n-1;
    int power_of_a;
    while(d%2 == 0){d/=2;s++;}
    power_of_a=ExPower(a,d,n);
    if(power_of_a == 1)return true;
    for(int i=0;i<s;i++){
        if(power_of_a == n-1)return true;
        power_of_a=power_of_a*power_of_a%n;
    }
    return false;
}

bool PrimeMillerRabin(int n){
    int a_set[3]={2,7,61};
    //LL a_set[7]={2,325,9375,28178,450775,9780504,1795265022};
    if(n == 2 || n == 3)return true;
    if(n <= 1 || n%2 == 0 || n%3 == 0)return false;
    for(int i=0;i<3;i++){
        if(!MillerRabin(a_set[i],n))return false;
    }
    return true;
}
