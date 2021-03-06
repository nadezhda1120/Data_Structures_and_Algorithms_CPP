// github.com/andy489

// https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem

#include <iostream>
#include <algorithm>

using namespace std;

bool covered[100000];
int n, k, i, arr[100000];

bool check(int towersCnt) {
    for (i = 0; i < n; ++i)
        covered[i] = 0;
    for (i = 0; i < n; ++i) {
        if (!covered[i]) {
            int j = i;
            --towersCnt;
            while (arr[j] <= arr[i] + k && j < n)
                covered[j++] = 1;
            --j;
            int l = j + 1;
            while (arr[l] <= arr[j] + k && l < n)
                covered[l++] = 1;
        }
    }
    return towersCnt >= 0;
}

int getSmallestNumberOfTowersNeeded() {
    int left = 0, right = 100000, result;;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid))
            result = mid, right = mid - 1;
        else
            left = mid + 1;
    }
    return result;
}

int main() {
    cin >> n >> k;
    for (; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    return cout << getSmallestNumberOfTowersNeeded(), 0;
}
