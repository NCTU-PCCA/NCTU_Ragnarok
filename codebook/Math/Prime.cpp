// Complexity : O(NlogN)
void BuildPrime(bool prime[],int N){
    for(int i=2;i<N;i++) prime[i] = true;
    for(int i=2;i<N;i++){
        if(prime[i]) for(int j=i*i;j<N;j+=i)prime[j] = false;
    }
}

// Complexity : O(N)
void BuildPrime(vector<int> primelist,bool prime[],int N){
    for(int m=2;m<N;m++){
        if(prime[m] == true) primelist.push_back(m);
        for(auto i:primelist){
            if(m*i >= N) break;
            prime[m*i] = false;
            if(m%i == 0) break;
        }
    }
}

void ExBuildPrime(int first[],bool prime[],int N){
    for(int i=2;i<N;i++){
        prime[i] = true;
        first[i] = 1;
    }
    for(int i=2;i<N;i++){
        if(prime[i]) for(int j=i*i;j<N;j+=i){
            prime[j] = false;
            if(first[j] == 1) first[j] = i;
        }
    }
}
