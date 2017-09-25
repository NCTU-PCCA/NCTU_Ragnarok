int __gcd(int a,int b)
int __builtin_ffs (unsigned int x)
int __builtin_ffsl (unsigned long)
int __builtin_ffsll (unsigned long long)
// 返回右起第一個1的位置
// Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.

int __builtin_clz (unsigned int x)
int __builtin_clzl (unsigned long)
int __builtin_clzll (unsigned long long)
// 返回左起第一個1之前0的個數
// Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
 
int __builtin_ctz (unsigned int x)
int __builtin_ctzl (unsigned long)
int __builtin_ctzll (unsigned long long)
// 返回右起第一個1之後的0的個數
// Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
 
int __builtin_popcount (unsigned int x)
int __builtin_popcountl (unsigned long)
int __builtin_popcountll (unsigned long long)
// 返回1的個數
// Returns the number of 1-bits in x.
 
int __builtin_parity (unsigned int x)
int __builtin_parityl (unsigned long)
int __builtin_parityll (unsigned long long)
// 返回1的個數的奇偶性(1的個數 mod 2的值)
// Returns the parity of x, i.e. the number of 1-bits in x modulo 2. 
