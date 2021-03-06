// github.com/andy489

// https://www.hackerrank.com/contests/practice-3-sda/challenges/monster-trucks

#include <iostream>

using namespace std;
typedef long long ll;

ll powNeeded(ll *trucks, ll *powers, ll n, ll distance) {
    ll power(0);
    int i(0);
    for (; i < n; ++i)
        power += (abs(distance - trucks[i]) * powers[i]);
    return power;
}

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll binSearch(ll *trucks, ll *powers, ll n, ll start, ll end) {
    int i;
    if (end - start < 3) {
        ll currMin = powNeeded(trucks, powers, n, start);
        for (i = start + 1; i < end + 1; ++i)
            currMin = min(currMin, powNeeded(trucks, powers, n, i));
        return currMin;
    }
    if (start >= end)
        return powNeeded(trucks, powers, n, end);
    ll mid = (end + start) / 2;

    if (powNeeded(trucks, powers, n, mid) < powNeeded(trucks, powers, n, mid + 1))
        return binSearch(trucks, powers, n, start, mid);
    else if (powNeeded(trucks, powers, n, mid) > powNeeded(trucks, powers, n, mid + 1))
        return binSearch(trucks, powers, n, mid + 1, end);
    else
        return powNeeded(trucks, powers, n, mid);
}

void truck() {
    ll n;
    cin >> n;
    if (n <= 1) {
        cout << 0;
        return;
    }

    ll *k = new ll[n];
    ll *m = new ll[n];
    int i(0);
    for (; i < n; ++i)
        cin >> k[i] >> m[i];

    ll low, hi;

    for (i = 0; i < n; ++i) {
        if (low > k[i])
            low = k[i];
        if (hi < k[i])
            hi = k[i];
    }
    cout << binSearch(k, m, n, low, hi);
}

int main() {
    return truck(), 0;
}
