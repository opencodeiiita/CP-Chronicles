/*
Submission Link:
https://codeforces.com/contest/769/submission/357206338
*/

/*
Problem: Cycle In Maze
Link: https://codeforces.com/contest/769/problem/C
Author: Krishna200608

Problem Statement:

    A robot starts at cell 'X' inside a grid. It has to make exactly k moves and end up back at the starting cell.
    Among all valid paths, we must output the lexicographically smallest path string, where the order of preference is
    D < L < R < U. If no such path exists, the answer is "IMPOSSIBLE".

Approach:
    The goal is to generate the lexicographically smallest valid path, so at every step we try moves in the fixed order:
    Down, Left, Right, and then Up.

    From the current cell, a move is allowed only if two conditions are satisfied.
    First, the destination cell must lie within the grid and must not be a wall '*'.
    Second, after making this move, it should still be possible to return to the starting cell 'X' within the remaining
    number of steps.

    To efficiently check the second condition, we first run a BFS starting from 'X'. This allows us to compute the shortest
    distance from every cell in the grid back to 'X', stored in a distance array.

    If the value of k is odd, it is immediately impossible to form such a cycle, since any cycle in a grid graph must have
    an even length.

    After preprocessing, we construct the path greedily. For exactly k steps, we repeatedly choose the smallest possible
    valid direction that keeps the solution feasible.

Time Complexity:
    The BFS runs in O(N × M), where N and M are the grid dimensioins. The path construction : O(k).
    Overall time complexity is O(N × M + k).

Space Complexity:
    O(N × M) : used for storing the distance array.
*/


#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
const int M = 1e9+7;
const double PI = acos(-1.0);
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ll long long
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define ff first
#define ss second
#define inn(x) int x; std::cin >> x;
#define ill(x) ll x; std::cin >> x;
#define all(x) x.begin(),x.end()
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];
#define out(a) for(int i = 0; i<a.size(); i++) cout<<a[i]<< " " ;
typedef vector<int> vi;
typedef vector<ll> vll;
#define ceil_div(n, x)  ( ((n) % (x) == 0) ? ((n) / (x)) : ((n) / (x) + 1) )
#define debug(x) cout << "x -> " << x << endl;
#define outt(x) cout << x << endl;
#define endl "\n"
 
// D < L < R<U
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dc[] = {'D', 'L', 'R', 'U'};

void solve(){
    int n, m, k;
    if(!(cin >> n >> m >> k)) return;

    vector<string> g(n);
    int sx, sy;
    for(int i = 0; i < n; i++) {
        cin >> g[i];
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'X') {
                sx = i; sy = j;
            }
        }
    }

    if(k % 2 != 0) {
        outt("IMPOSSIBLE");
        return;
    }

    vector<vi> d(n, vi(m, 1e9));
    queue<pair<int, int>> q;
    
    d[sx][sy] = 0;
    q.push({sx, sy});

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '*' && d[nr][nc] == 1e9) {
                d[nr][nc] = d[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }


    int cx = sx, cy = sy;
    string path = "";

    for(int i = 0; i < k; i++) {
        int rem = k - 1 - i; 
        bool moved = false;

        for(int j = 0; j < 4; j++) {
            int nx = cx + dx[j];
            int ny = cy + dy[j];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '*') {
                
                if(d[nx][ny] <= rem) {
                    path += dc[j];
                    cx = nx;
                    cy = ny;
                    moved = true;
                    break; 
                }
            }
        }

        if(!moved) {
            outt("IMPOSSIBLE");
            return;
        }
    }

    outt(path);
}

signed main(){
ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
auto begin = std::chrono::high_resolution_clock::now();
    int t=1;
    while(t--){
        solve();
    }
 
 
 
auto end = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms";
return 0;
}