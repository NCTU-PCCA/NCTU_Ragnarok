int Phi(int x){
    vector<pair<int,int>> FD = FactorDecomposition(x);
    int ans = 1;
    for(auto i:FD){
        ans *= i.first-1;
        ans *= Power(i.first,i.second-1);
    }
    return ans;
}

void BuildPhi(int phi[],int N){
    bool prime[N];for(int i=0;i<N;i++) prime[i] = true;
    vector<int> primelist;
    phi[1] = 1;
    for(int m=2;m<N;m++){
        if(prime[m] == true){
            phi[m] = m-1;
            primelist.push_back(m);
        }
        for(auto i:primelist){
            if(m*i >= N) break;
            prime[m*i] = false;
            if(m%i == 0){
                int now = m,power = 1;
                while(now%i == 0){ now /= i;power *= i; }
                phi[m*i] = phi[m]*power*(i-1);
                break;
            }
            else phi[m*i] = phi[m]*(i-1);
        }
    }
}
