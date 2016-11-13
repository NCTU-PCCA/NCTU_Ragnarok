// Complexity : O(T+P)
void predo(string pattern,int dp[]){
    dp[0] = 0;
    for(int i=1;i<pattern.size();i++){
        dp[i] = dp[i-1];
        while(dp[i] > 0 && pattern[dp[i]] != pattern[i]) dp[i] = dp[dp[i]-1];
        if(pattern[dp[i]] == pattern[i]) dp[i]++;
    }
}

void KMP(string text,string pattern){
    int dp[pattern.size()];predo(pattern,dp);
    for(int i=0,match=0;i<text.size();i++){
        while(match > 0 && pattern[match] != text[i]) match = dp[match-1];
        if(pattern[match] == text[i]) match++;
        if(match == pattern.size()){
            // do something with i-pattern.size()+1
            match = dp[match-1];
        }
    }
}
