int ExGCD(int A,int B,int& X,int& Y,int s0 = 1,int s1 = 0,int t0 = 0,int t1 = 1){
  if(A%B == 0){
    X = s1;
    Y = t1;
    return B;
  }
  s0-=s1*(A/B);
  t0-=t1*(A/B);
  return ExGCD(B,A%B,X,Y,s1,s0,t1,t0);
}
