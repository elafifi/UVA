/**
* Author  : Ahmed Elafifi   getting help by tutorial link: https://tutorial92.wordpress.com/2012/09/17/uva-10090-marbles-tutorial/
* Date    : 11/9/2018
* Category: Extended Euclidean Algorithim with Bezout's identity
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c1,c2,n1,n2;
ll eGCD(ll a,ll b,ll& x,ll& y)
{
    if(!b)
    {
        x = 1,y = 0;
        return a;
    }
    ll g = eGCD(b,a%b,y,x);
    y -= (a/b)*x;

    return g;
}




int main()
{
    /// a*n1 + b*n2 = g; multiply by n/gcd(n1,n2)
    /// n1 * m1 + n2 * m2 = n     as m1  = n1*n/gcd  and m2 = n2*n/gcd
    ///cost = c1 * m1 + c2 * m2 .
    ///m1 = m1 + n2 / g * t  ,
    /// m2 = m2 –  n1 / g * t
    ///c = c1 * m1 + c2 * m2 = c1 * ( m1 + n2 / g * t )  +   c2 * ( m2 – n1 /g * t) = c1*m1 +c2*m2 + t * (c1* n2/g – c2 *n1/g).
    ///ceil(-m1*g/n2) <= t <= floor(m2*g/n1),
    while(cin>>n,n)
    {
        cin>>c1>>n1;
        cin>>c2>>n2;

        ll m1,m2;
        ll g = eGCD(n1,n2,m1,m2);
        if(n%g != 0)
        {
            cout<<"failed"<<endl;
            continue;
        }
        m1 *= n/g, m2 *= n/g;
        ll lf = ceil(-(double)m1*g/n2), r = floor((double)m2*g/n1);
        if(lf>r)
        {
            cout<<"failed"<<endl;
            continue;
        }
        if((c1*n2/g - c2*n1/g)*lf < (c1*n2/g - c2*n1/g)*r)
            m1 += (n2/g)*lf , m2 -= (n1/g)*lf;
        else
            m1 += (n2/g)*r , m2 -= (n1/g)*r;
        cout<<m1<<" "<<m2<<endl;
    }

    return 0;
}
