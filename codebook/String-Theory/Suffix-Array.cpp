int SA[MAXNUM],H[MAXNUM];
void SuffixArray(string text){
    int N = text.size(),A = 128;
    int SA2[MAXNUM],rank[MAXNUM],rank2[MAXNUM],radix[MAXNUM];
    for(int i=0;i<A;i++)radix[i] = 0;
    for(int i=0;i<N;i++)radix[rank[i] = text[i]]++;
    for(int i=0;i<A;i++)radix[i] += radix[i-1];
    for(int i=N-1;i>=0;i--)SA[--radix[text[i]]] = i;

    for(int power=1;power<N;power<<=1){
        for(int i=0;i<A;i++)radix[i] = 0;
        for(int i=0;i<N;i++)radix[rank[i]]++;
        for(int i=0;i<A;i++)radix[i] += radix[i-1];

        int now = 0;
        for(int i=N-power;i<N;i++)SA2[now++] = i;
        for(int i=0;i<N;i++){
            if(SA[i]-power >= 0)SA2[now++] = SA[i]-power;
        }

        for(int i=N-1;i>=0;i--)SA[--radix[rank[SA2[i]]]] = SA2[i];

        rank2[SA[0]] = now = 0;
        for (int i=1;i<N;i++){
            if (!(rank[SA[i-1]] == rank[SA[i]] && SA[i-1]+power < N && SA[i]+power < N && rank[SA[i-1]+power] == rank[SA[i]+power]))now++;
            rank2[SA[i]] = now;
        }
        swap(rank,rank2);
        if(now == N-1)break;
        A = now+1;
    }
    for(int i=0;i<N;i++)rank[SA[i]] = i;
    for(int i=0,k=0;i<N;i++,k?k--:0){
        if(rank[i] == 0){H[rank[i]] = 0;continue;}
        int j = SA[rank[i]-1];
        while(i+k < N && j+k < N && text[i+k] == text[j+k])k++;
        H[rank[i]] = k;
    }
}
