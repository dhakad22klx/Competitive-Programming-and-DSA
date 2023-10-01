1.Dearrangement : https://codeforces.com/contest/888/problem/D 
//Deaarangement Precalculation
    v[0]=1;
    for(ll i=1;i<=k;i++)
    {
        v[i] = (i*v[i-1]) - (i%2 ? 1 : -1);
    }
