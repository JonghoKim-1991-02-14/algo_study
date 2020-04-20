/**
 *  Solver: JONGHO KIM <jongho_kim3@tmax.co.kr>
 *  https://www.acmicpc.net/problem/1753
 *  Reference: https://rebas.kr/695
 */

#include <cstdio>
#include <vector>
#include <algorithm>   // std::fill(), std::fill_n()
#include <queue>       // std::priority_queue

#define MAX_NUM_V     20000
#define MAX_NUM_E    300000
#define MAX_K         20000   // 1 <= K <= num_v

#define MIN_W             1
#define MAX_W            10
#define INF             1e9

typedef int vertex_t;

// Neighbor of a vertex.
// Note that this struct corresponds to an edge,
// because we will group the neighbors with the same source vertex
typedef struct node_t {

  vertex_t dest;
  int cost;

  // Define oparator < as the inverse of cost,
  // becuase std::priority_queue uses maxheap but we want to use minheap
  bool operator < (const node_t u) const { return cost > u.cost; };
} node_t;

typedef std::vector<node_t> neighbor_t;
typedef neighbor_t* graph_t;

void dijkstra(graph_t g, int start, int *dist, int num_v);

inline void dijkstra(graph_t g, int start, int *dist, int num_v) {

  std::priority_queue<node_t> pq;

  vertex_t v, u;
  int v_dist, vu_dist;
  std::vector<node_t>::iterator neighbor;

  // Init dist
  std::fill(dist, dist + num_v, INF);
  dist[start] = 0;

  // Push start vertex into the priority queue
  pq.push({.dest=start, .cost=0});

  //
  while(!pq.empty()) {

    // Pop and visit vertex v
    v = pq.top().dest;
    v_dist = pq.top().cost;
    pq.pop();
    if(dist[v] < v_dist) continue;

    // Iterate among the neighbors of vertex v
    for(neighbor=g[v].begin(); neighbor!=g[v].end(); ++neighbor) {

      // Discover vertex u among the neighbors of vertex v
      u = neighbor->dest;
      vu_dist = neighbor->cost + v_dist;
      if(dist[u] > vu_dist) {
        dist[u] = vu_dist;
        // Push vertex u and distance to the priority queue
        pq.push({.dest=u, .cost=vu_dist});
      }
    }
  }
}

int main(int argc, char *argv[]) {

  // Console inputs
  int num_v, num_e;
  int k;
  int u, v, w;

  //
  neighbor_t g[MAX_NUM_V];
  int dist[MAX_NUM_V];

  //
  int i, ret;

  std::scanf("%d %d", &num_v, &num_e);
  std::scanf("%d", &k), --k;
  for(i=0; i<num_e; i++) {
    std::scanf("%d %d %d", &u, &v, &w), --u, --v;
    g[u].push_back({v, w});
  }

  dijkstra(g, k, dist, num_v);

  for(i=0; i<num_v; i++) {
    ret = dist[i];
    if(ret == INF) printf("INF\n");
    else printf("%d\n", ret);
  }

  return 0;
}
