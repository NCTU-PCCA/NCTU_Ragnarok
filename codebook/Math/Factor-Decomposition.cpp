vector<pair<int,int>> FactorDecomposition(int x){
  vector<pair<int,int>> Ans;
  while(x > 1){
    int p,e = 0;
    if(prime[x] == true)p = x;else p = first[x];
    while(x%p == 0){x/=p;e++;}
    Ans.push_back(make_pair(p,e));
  }
  return Ans;
}
