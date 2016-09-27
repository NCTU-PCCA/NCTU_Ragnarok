void BuildPrime(bool prime[],int N){
  for(int i=2;i<N;i++)prime[i] = true;
  for(int i=2;i<N;i++){
    if(prime[i]){for(int j=i*i;j<N;j+=i)prime[j] = false;}
  }
}

void ExBuildPrime(int first[],bool prime[],int N){
  for(int i=2;i<N;i++){
    prime[i] = true;
    first[i] = 1;
  }
  for(int i=2;i<N;i++){
    if(prime[i]){for(int j=i*i;j<N;j+=i){
      prime[j] = false;
      if(first[j] == 1)first[j] = i;
    }}
  }
}
