#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> ii;

const int maxn = 2e5 + 15;

int t;
int n;
long long ar[maxn];

void solve()
{
    scanf("%d", &n);
    long long oddcnt = 0;
    long long evencnt = 0;
    long long evensum = 0;
    long long oddmx = 0;
    long long evenmx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &ar[i]);
        if (ar[i] & 1) {
            oddcnt++;
            oddmx = max(oddmx, ar[i]);
        } else {
            evensum += ar[i];
            evenmx = max(evenmx, ar[i]);
        }
    }
    evencnt = n - oddcnt;

    if (evencnt == 0 || oddcnt == 0) {
        printf("0\n");
        return;
    }

    sort(ar, ar + n);
    // reverse(ar, ar + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] % 2 == 0) {
            if (ar[i] > oddmx) {
                oddmx += evenmx;
                ans++;
                i--;
            } else {
                oddmx += ar[i];
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &t);

    while (t--)
        solve();
    return 0;
}