const int MAX_DIGIT = 1000;
const int POSTIONAL = 4;
const int POSTIONAL_NOTATION = 10000;

struct PositiveBigInt{
    int N[MAX_DIGIT],L;
    PositiveBigInt():L(0){}
    PositiveBigInt(string S){
        set_value(S);
    }
    PositiveBigInt(int* N,int L){
        set_value(N,L);
    }
    void set_value(string S){
        L=(S.size()-1)/POSTIONAL+1;
        for(int i=0;i<L;i++)N[i]=0;
        for(int i=0;i*POSTIONAL<S.size();i++){
            int pow10=1;
            for(int j=i*POSTIONAL;j<S.size() && j<i*POSTIONAL+POSTIONAL;j++){
                N[i]+=(S[S.size()-1-j]-48)*pow10;
                pow10*=10;
            }
        }
    }
    void set_value(int* N,int L){
        this->L=L;
        for(int i=0;i<L;i++)this->N[i]=N[i];
    }
    bool equal_zero() const {
        if(L == 1 && N[0] == 0)return true;
        return false;
    }
    void kill_zero(){
        while(L > 1 && N[L-1] == 0)L--;
    }
    int magic(int *Num,int Length,const PositiveBigInt& A) const {
        PositiveBigInt B(Num,Length);
        B.kill_zero();
        int Ans=0;
        while(B >= A){
            B=B-A;
            Ans++;
        }
        for(int i=0;i<Length;i++){
            if(i < B.L)Num[i]=B.N[i];
            else Num[i]=0;
        }
        return Ans;
    }
    PositiveBigInt operator+(const PositiveBigInt& A) const {
        const PositiveBigInt &X=(*this > A ? *this : A);
        const PositiveBigInt &Y=(*this <= A ? *this : A);
        PositiveBigInt tmp=X;
        for(int i=0;i<Y.L;i++)tmp.N[i]+=Y.N[i];
        tmp.N[tmp.L]=0;
        for(int i=0;i<tmp.L;i++){
            tmp.N[i+1]+=tmp.N[i]/POSTIONAL_NOTATION;
            tmp.N[i]%=POSTIONAL_NOTATION;
        }
        if(tmp.N[tmp.L] > 0)tmp.L++;
        return tmp;
    }
    PositiveBigInt operator-(const PositiveBigInt& A) const {
        const PositiveBigInt &X=(*this > A ? *this : A);
        const PositiveBigInt &Y=(*this <= A ? *this : A);
        PositiveBigInt tmp=X;
        for(int i=0;i<Y.L;i++)tmp.N[i]-=Y.N[i];
        for(int i=0;i<tmp.L;i++){
            if(tmp.N[i] < 0){
                tmp.N[i+1]--;
                tmp.N[i]+=POSTIONAL_NOTATION;
            }
        }
        tmp.kill_zero();
        return tmp;
    }
    PositiveBigInt operator*(const PositiveBigInt& A) const {
        PositiveBigInt tmp;
        tmp.L=L+A.L;
        for(int i=0;i<tmp.L;i++)tmp.N[i]=0;
        for(int i=0;i<L;i++){
            for(int j=0;j<A.L;j++)tmp.N[i+j]+=N[i]*A.N[j];
            for(int j=0;j<tmp.L;j++){
                tmp.N[j+1]+=tmp.N[j]/POSTIONAL_NOTATION;
                tmp.N[j]%=POSTIONAL_NOTATION;
            }
        }
        tmp.kill_zero();
        return tmp;
    }
    PositiveBigInt operator/(const PositiveBigInt& A) const {
        if(*this < A)return PositiveBigInt("0");
        PositiveBigInt Div,Mod=*this;
        Div.L=L;
        for(int i=L-1;i>=0;i--)Div.N[i]=magic(Mod.N+i,Mod.L-i,A);
        Div.kill_zero();
        return Div;
    }
    PositiveBigInt operator%(const PositiveBigInt& A) const {
        if(*this < A)return *this;
        PositiveBigInt Mod=*this;
        for(int i=L-1;i>=0;i--)magic(Mod.N+i,Mod.L-i,A);
        Mod.kill_zero();
        return Mod;
    }
    bool operator>(const PositiveBigInt& A) const {
        if(L > A.L)return true;
        else if(L < A.L)return false;
        for(int i=L-1;i>=0;i--){
            if(N[i] > A.N[i])return true;
            else if(N[i] < A.N[i])return false;
        }
        return false;
    }
    bool operator>=(const PositiveBigInt& A) const {
        if(L > A.L)return true;
        else if(L < A.L)return false;
        for(int i=L-1;i>=0;i--){
            if(N[i] > A.N[i])return true;
            else if(N[i] < A.N[i])return false;
        }
        return true;
    }
    bool operator<(const PositiveBigInt& A) const {
        return !(*this >= A);
    }
    bool operator<=(const PositiveBigInt& A) const {
        return !(*this > A);
    }
    bool operator==(const PositiveBigInt& A) const {
        if(L != A.L)return false;
        for(int i=0;i<L;i++){
            if(N[i] != A.N[i])return false;
        }
        return true;
    }
    bool operator!=(const PositiveBigInt& A) const {
        return !(*this == A);
    }
    PositiveBigInt operator=(const PositiveBigInt& A){
        L=A.L;
        for(int i=0;i<L;i++)N[i]=A.N[i];
        return (*this);
    }
};

ostream& operator<<(ostream& o,const PositiveBigInt& A){
    o << A.N[A.L-1];
    for(int i=A.L-2;i>=0;i--){
        for(int c=1,tmp=A.N[i];c < POSTIONAL && tmp*10 < POSTIONAL_NOTATION;c++,tmp*=10)o << "0";
        o << A.N[i];
    }
    return o;
}

struct BigInt{
    PositiveBigInt N;
    bool sign;
    BigInt(){}
    BigInt(string S){
        set_value(S);
    }
    void set_value(string S){
        if(S[0] == '-'){
            sign=false;
            N.set_value(S.substr(1,S.size()-1));
        }
        else{
            sign=true;
            N.set_value(S);
        }
    }
    BigInt operator+(const BigInt& A) const {
        BigInt tmp;
        if(sign^A.sign){
            tmp.N=N-A.N;
            if(N > A.N)tmp.sign=sign;
            else if(N < A.N)tmp.sign=A.sign;
            else tmp.sign=true;
        }
        else{
            tmp.N=N+A.N;
            tmp.sign=sign;
        }
        return tmp;
    }
    BigInt operator-(const BigInt& A) const {
        BigInt tmp=A;
        tmp.sign=!tmp.sign;
        return (*this + tmp);
    }
    BigInt operator*(const BigInt& A) const {
        BigInt tmp;
        if(N.equal_zero() || A.N.equal_zero())tmp.sign=true;
        else tmp.sign=!(sign^A.sign);
        tmp.N=N*A.N;
        return tmp;
    }
    BigInt operator/(const BigInt& A) const {
        if(A.N.equal_zero()){printf("divided by 0 error!!\n");return BigInt("0");}
        BigInt tmp;
        if(N.equal_zero())tmp.sign=true;
        else tmp.sign=!(sign^A.sign);
        tmp.N=N/A.N;
        return tmp;
    }
    BigInt operator%(const BigInt& A) const {
        if(A.N.equal_zero()){printf("divided by 0 error!!\n");return BigInt("0");}
        BigInt tmp;
        tmp.sign=true;
        tmp.N=N%A.N;
        return tmp;
    }
    bool operator>(const BigInt& A) const {
        if(sign == true && A.sign == true)return (N > A.N);
        if(sign == true && A.sign == false)return true;
        if(sign == false && A.sign == true)return false;
        if(sign == false && A.sign == false)return (N < A.N);
    }
    bool operator>=(const BigInt& A) const {
        if(sign == true && A.sign == true)return (N >= A.N);
        if(sign == true && A.sign == false)return true;
        if(sign == false && A.sign == true)return false;
        if(sign == false && A.sign == false)return (N <= A.N);
    }
    bool operator<(const BigInt& A) const {
        return !(*this >= A);
    }
    bool operator<=(const BigInt& A) const {
        return !(*this > A);
    }
    bool operator==(const BigInt& A) const {
        if(sign != A.sign)return false;
        return (N == A.N);
    }
    bool operator!=(const BigInt& A) const {
        return !(*this == A);
    }
    BigInt operator=(const BigInt &A){
        N=A.N;
        sign=A.sign;
        return (*this);
    }
    BigInt operator+=(const BigInt &A){
        return (*this)=(*this)+A;
    }
    BigInt operator-=(const BigInt &A){
        return (*this)=(*this)-A;
    }
    BigInt operator*=(const BigInt &A){
        return (*this)=(*this)*A;
    }
    BigInt operator/=(const BigInt &A){
        return (*this)=(*this)/A;
    }
    BigInt operator%=(const BigInt &A){
        return (*this)=(*this)%A;
    }
    BigInt operator++(){
        (*this)=(*this)+BigInt("1");
        return (*this);
    }
    BigInt operator++(int useless){
        BigInt tmp=(*this);
        (*this)=(*this)+BigInt("1");
        return tmp;
    }
    BigInt operator--(){
        (*this)=(*this)-BigInt("1");
        return (*this);
    }
    BigInt operator--(int useless){
        BigInt tmp=(*this);
        (*this)=(*this)-BigInt("1");
        return tmp;
    }
};

ostream& operator<<(ostream& o,const BigInt& A){
    if(!A.sign)o << '-';
    return o << A.N;
}
