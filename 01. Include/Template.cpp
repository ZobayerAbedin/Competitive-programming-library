#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

// or just use #include<bits/stdc++.h>

#define I ios::sync_with_stdio(false); cin.tie(0);
#define Q int tt; cin>>tt ; for(int qq=1; qq <= tt; qq++)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// vector ??

#define mp make_pair
#define ff first
#define ss second

// vector
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define rall rbegin(), rend()
#define pb push_back
#define V vector

#define lb lower_bound
#define ub upper_bound

//loops
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)
#define R0F(i, a) for(int i = (a) - 1; i >= 0 ; i++)

// random number
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    uniform_int_distribution < int > uid(l, r);
    return uid(rng);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}