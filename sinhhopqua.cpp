//Tran Huu Nam - huunam0@gmail.com - 2/2022
#include "testlib.h"
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(int argc, char* argv[])
{
   registerGen(argc, argv, 1);
   lli g1 = argc >= 2 ? stoll(argv[1],nullptr,10) : 10;
   lli g2 = argc >= 3 ? stoll(argv[2],nullptr,10) : g1;
   lli m = rnd.next(50000, 100000);
   lli n = rnd.next(1LL * m, 200000LL);
   cout<<n<<" "<<m<<endl;
   lli b[m + 5], a[n + 5];
   for (int i = 1; i <= m; i++) b[i] = rnd.next(1LL, 1000000000LL);
   sort(b + 1, b + m + 1);
   for (int i = 1; i <= m; i ++) a[i] = rnd.next(1LL * b[i], 1000000000LL);
   for (int i = m + 1; i <= n; i++) a[i] = rnd.next(1LL, 1000000000LL);
   shuffle(a + 1, a + n + 1);
   for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
   shuffle(b + 1, b + m + 1);
   for (int i = 1; i <= m; i++) cout<<b[i]<<" ";
   return 0;
	
}