#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> ii;

const int maxn = 4e5 + 15;

int t;
int n, k;
int ar[maxn];

void solve()
{
    scanf("%d%d", &n, &k);
    const int md = k + k;
    vector<int> lit(md, 0);
    int mx = 0;
    int tot = 0;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        mx = max(mx, x);
        x %= md;
        tot += !lit[x];
        lit[x] = 1;
    }
    int ok = false;
    int r = 0;
    int cur = 0;
    for (int i = 0; i < md && !ok; i++) {
        while (r - i < k) {
            cur += lit[r % md];
            r++;
        }
        if (cur == tot)
            ok = true;
        cur -= lit[i];
    }

    if (!ok) {
        printf("-1\n");
        return;
    }
    int add = 0;
    for (int i = 0; i < k; i++) {
        if (lit[(mx % md + i) % md])
            add = i;
    }
    printf("%d\n", mx + add);
}

int main()
{
    scanf("%d", &t);

    while (t--)
        solve();
    return 0;
}