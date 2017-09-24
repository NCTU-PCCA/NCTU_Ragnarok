/* Complexity: O(n)
 * n: n people
 * k: kill the kth person
 * p: last pth person died
 */
int Josephus(int n, int k, int p){
    int ans = ( k - 1 ) % p;
    for(int i=p+1;i<=n;i++) ans = ( ans + k ) % i;
    return ans;
}
