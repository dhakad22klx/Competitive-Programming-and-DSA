//modulo exponential

1. ll moduloexp(ll a,ll b){
    ll result =1;
    while(b>0){
        if(b&1){
            result= (result*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return result;
}

// GCD 
//a>b
ll gcd(ll a,ll b){
    if(b==0) return a;
    gdc(b,a%b);
}

2. There is a fact that the distance between adjacent prime numbers isn't big. For n = 1e9 maximal distanse is 282.
