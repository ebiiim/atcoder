// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,s,n) for (int i=(s); i<(int)(n); ++i)
#define PI 3.14159265358979323846264338327950L
#define noflush ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'
#define put(expr) cout<<expr<<'\n'
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64;
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
typedef float f32; typedef double f64; typedef long double f80;
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; }
template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
using namespace std;
const int INF = 1<<30; /* INF > 10^9 */ const i64 INFLL = 1LL<<60; /* INFLL > 10^18*/
// clang-format on

// 連結成分の個数をBFSで数える

using Graph = vector<vector<int>>;

// input:
//   G: graph
//   s: start from
//   D: distance array
//      - set all elems -1 by `vector<int> D(N, -1);` for the first run
//      - set this array to do BFS for graph with multiple linked components
void BFS(const Graph &G, int s, vector<int> &D) {
  int N = (int)G.size();  // num of vertex
  // vector<int> dist(N, -1);  // -1 represents not seen
  queue<int> que;

  // start from s
  D[s] = 0;
  que.push(s);

  // do BFS
  while (!que.empty()) {
    int v = que.front();  // vertex to see
    que.pop();

    // see adjacencies of v
    for (auto x : G[v]) {
      if (D[x] != -1) continue;  // seen

      // set dist and enqueue
      D[x] = D[v] + 1;
      que.push(x);
    }
  }
}

int main() {
  noflush;

  int N, M;
  cin >> N >> M;

  Graph G(N);

  // 隣接リスト表現 adjacency-list representation
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);  // 有向グラフならこれを消す
  };

  vector<int> dist(N, -1);  // -1 represents not seen

  // 0から開始
  BFS(G, 0, dist);
  int count = 1;

  // distに-1があるなら再度BFS
  bool ok = false;
  while (!ok) {
    rep(i, dist.size()) {
      ok = true;
      if (dist[i] == -1) {
        ok = false;
        BFS(G, i, dist);
        ++count;
      }
    }
  }
  put(count);
}
