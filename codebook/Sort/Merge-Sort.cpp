void Merge(int* N,int L,int M){
    int tmp[L],p=0; int a,b;
    for(a=0,b=M;a<M && b<L;){
        if(N[a] < N[b]){ tmp[p++]=N[a]; a++; }
        else{ tmp[p++]=N[b]; b++;}
    }
    if(a == M)for(int i=b;i<L;i++)tmp[p++]=N[i];
    else for(int i=a;i<M;i++)tmp[p++]=N[i];
    for(int i=0;i<L;i++)N[i]=tmp[i];
}
void MergeSort(int* N,int L){
    int M=L/2;
    if(L == 1)return;
    MergeSort(N,M);
    MergeSort(N+M,L-M);
    Merge(N,L,M);
}
