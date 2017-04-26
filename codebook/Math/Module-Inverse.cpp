int inverse(int A,int M,int X = 1,int Y = 0){
  if(A%M == 0){
    if(Y < 0)Y+=M;
    return Y;
  }
  X-=Y*(A/M);
  return inverse(M,A%M,Y,X);
}


inline int inverse(int A,int M){
    return ExPower(A,M-2,M);
}
