struct fraction_positive{
    int p,q;
    fraction_positive(){}
    fraction_positive(int p,int q):p(p),q(q){}
    void reduction(){
        int G = __gcd(p,q);
        p /= G;
        q /= G;
    }
    bool operator==(const fraction_positive& B) const {
        return (p == B.p && q == B.q);
    }
    bool operator!=(const fraction_positive& B) const {
        return (p != B.p || q != B.q);
    }
    bool operator>(const fraction_positive& B) const {
        return (p*B.q > B.p*q);
    }
    bool operator>=(const fraction_positive& B) const {
        return (p*B.q >= B.p*q);
    }
    bool operator<(const fraction_positive& B) const {
        return (p*B.q < B.p*q);
    }
    bool operator<=(const fraction_positive& B) const {
        return (p*B.q <= B.p*q);
    }
    fraction_positive operator+(const fraction_positive& B) const {
        fraction_positive F;
        F.p = p*B.q+B.p*q;
        F.q = q*B.q;
        F.reduction();
        return F;
    }
    fraction_positive operator-(const fraction_positive& B) const {
        fraction_positive F;
        F.p = p*B.q-B.p*q;
        F.q = q*B.q;
        F.reduction();
        return F;
    }
    fraction_positive operator*(const fraction_positive& B) const {
        fraction_positive F;
        F.p = p*B.p;
        F.q = q*B.q;
        F.reduction();
        return F;
    }
    fraction_positive operator/(const fraction_positive& B) const {
        fraction_positive F;
        F.p = p*B.q;
        F.q = q*B.p;
        F.reduction();
        return F;
    }
    fraction_positive operator*(int x) const {
        fraction_positive F = *this;
        F.p *= x;
        F.reduction();
        return F;
    }
    fraction_positive operator/(int x) const {
        fraction_positive F = *this;
        F.q *= x;
        F.reduction();
        return F;
    }
};

struct fraction{
    fraction_positive N;
    bool sign,broken;//0 positive 1 negative
    fraction():broken(false){}
    fraction(int p,int q,bool sign):sign(sign){
        if(q == 0){broken = true;cout << "===divide by zero===" << endl;}
        else{N.p = p;N.q = q;N.reduction();}
    }
    bool operator==(const fraction& B) const {
        return (N == B.N && sign == B.sign);
    }
    bool operator!=(const fraction& B) const {
        return (N != B.N || sign != B.sign);
    }
    bool operator>(const fraction& B) const {
        return (!sign && B.sign) || (!sign && N > B.N) || (sign && N < B.N);
    }
    bool operator>=(const fraction& B) const {
        return  (!sign && B.sign) || (!sign && N >= B.N) || (sign && N <= B.N);
    }
    bool operator<(const fraction& B) const {
        return !(*this >= B);
    }
    bool operator<=(const fraction& B) const {
        return !(*this > B);
    }
    fraction operator+(const fraction& B) const {
        fraction F;
        if(broken || B.broken){F.broken = true;return F;}
        if(sign^B.sign){
            const fraction_positive& big = (N > B.N ? N : B.N);
            const fraction_positive& small = (N <= B.N ? N : B.N);
            F.N = big - small;
            F.sign = (N > B.N ? sign : B.sign);
        }
        else{
            F.N = N+B.N;
            F.sign = sign;
        }
        return F;
    }
    fraction operator-(const fraction& B) const {
        fraction F = B;
        if(broken || B.broken){F.broken = true;return F;}
        F.sign = !F.sign;
        return (*this+F);
    }
    fraction operator*(const fraction& B) const {
        fraction F;
        if(broken || B.broken){F.broken = true;return F;}
        F.N = N*B.N;
        F.sign = sign^B.sign;
        return F;
    }
    fraction operator/(const fraction& B) const {
        fraction F;
        if(broken || B.broken || B.N.p == 0){F.broken = true;return F;}
        F.N = N/B.N;
        F.sign = sign^B.sign;
        return F;
    }
    fraction operator*(int x) const {
        fraction F = *this;
        if(broken){F.broken = true;return F;}
        F.N = F.N*abs(x);
        if(x < 0)F.sign = !F.sign;
        return F;
    }
    fraction operator/(int x) const {
        fraction F = *this;
        if(x == 0){F.broken = true;return F;}
        F.N = F.N/abs(x);
        if(x < 0)F.sign = !F.sign;
        return F;
    }
    friend istream& operator>>(istream& in,fraction& B){
        int x;
        char c;
        B.sign = false;
        in >> x;if(x < 0){B.sign = true;x = -x;}
        B.N.p = x;
        in >> c >> x;if(x == 0){B.broken = true;return in;}
        B.N.q = x;
        B.N.reduction();
        return in;
    }
    friend ostream& operator<<(ostream& out,const fraction& B){
        if(B.broken){return out << "NaN";}
        if(B.sign)out << '-';
        return out << B.N.p << '/' << B.N.q;
    }
};
