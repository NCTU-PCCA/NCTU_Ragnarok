void ZAlgorithm(string word,string pattern){
    int Z[word.size()+pattern.size()];
    string S = pattern+word;
    Z[0] = 0;
    for(int i=1,best=0;i<S.size();i++){
      if(best+Z[best] <= i)Z[i] = 0;
      else Z[i] = min(Z[i-best],best+Z[best]-i);
      while(S[i+Z[i]] == S[Z[i]])Z[i]++;
      if(i+Z[i] > best+Z[best])best = i;
    }
    for(int i=pattern.size();i<S.size();i++){
        if(Z[i] >= pattern.size())cout << i-pattern.size() << " ";
    }
}
