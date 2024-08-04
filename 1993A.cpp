#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

int t;
int n;
char ar[555];

void solve()
{
    scanf("%d", &n);
    scanf("%s", ar);
    int cnt[128] {};

    for (int i = 0; i < 4 * n; i++) {
        cnt[ar[i]]++;
    }

    printf("%d\n", min(cnt['A'], n) + min(cnt['B'], n) + min(cnt['C'], n) + min(cnt['D'], n));
}

int main()
{
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}
