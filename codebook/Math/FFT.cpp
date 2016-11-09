const int MAXN = 262144;

const double PI = acos(-1.0);
const complex<double> I(0, 1);
complex<double> omega[MAXN+1];

void pre_FFT(){
    for(int i=0; i<=MAXN; i++)omega[i] = exp(i * 2 * PI / MAXN * I);
}

void FFT(int n, complex<double> a[], bool inv=false){
    int basic = MAXN / n;
    int theta = basic;
    for(int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for(int i = 0; i < mh; i++) {
            complex<double> w = omega[inv ? MAXN-(i*theta%MAXN) : i*theta%MAXN];
            for(int j = i; j < n; j += m) {
                int k = j + mh;
                complex<double> x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta = (theta * 2) % MAXN;
    }
    int i = 0;
    for(int j = 1; j < n - 1; j++) {
        for(int k = n >> 1; k > (i ^= k); k >>= 1);
        if(j < i) swap(a[i], a[j]);
    }
    if(inv)for(i = 0; i < n; i++)a[i] /= n;
}

