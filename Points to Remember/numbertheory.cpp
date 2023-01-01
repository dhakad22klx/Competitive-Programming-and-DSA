//modulo exponential

ll moduloexp(ll a,ll b){
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


