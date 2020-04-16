/**
 *  Solver: JONGHO KIM <jongho_kim3@tmax.co.kr>
 *  https://www.acmicpc.net/problem/1753
 */

#include <stdio.h>
#include <string.h>   // memset()

#define MAX_NUM_V     20000
#define MAX_NUM_E    300000
#define MAX_K        200000   // 1 <= K <= num_v
#define MIN_W             1
#define MAX_W            10

#define UVW_TRIPLE        3
#define U                 0
#define V                 1
#define W                 2

#define BYTE_INF       0x70
#define INF      0x70707070   // (MAX_W x MAX_NUM_V) < INF < MAX_INT32_T

#define BUFFSIZE        100

//#define DEBUG             1

void process_edge(const int u, const int v, const int w, int *vertex_cost, const int k) {

  int mincost;

  if(vertex_cost[v] > vertex_cost[u] + w)
    mincost = vertex_cost[u] + w;
  else
    mincost = vertex_cost[v];

  if(mincost >= INF) mincost = INF;

  vertex_cost[v] = mincost;

#ifdef DEBUG
  printf("%d -(%d)-> %d\n", u, w, v);
  printf("vertex_cost[%d] <- %d\n", v, mincost);
#endif
}


int main(int argc, char *argv[]) {

  int num_v, num_e;
  int k;
  int u, v, w;

  int vertex_cost[MAX_NUM_V + 1];   // Required SOLUTION
  int edge[MAX_NUM_E][UVW_TRIPLE];   // u -(w)-> v, u: source, v: destination, w: weight

  int i, j;

  // For I/O
  FILE *fs;
  char buff[BUFFSIZE];
  fs = stdin;

  // Read num_v and num_e
  fgets(buff, BUFFSIZE, fs);
  sscanf(buff, "%d %d", &num_v, &num_e);

  // Init
#ifdef DEBUG
  printf("\nBYTE_INF: %d, INF: %d\n", BYTE_INF, INF);
#endif
  memset(vertex_cost, BYTE_INF, sizeof(int) * (num_v+1));

  // Read k
  fgets(buff, BUFFSIZE, fs);
  sscanf(buff, "%d", &k);

  vertex_cost[k] = 0;

  for(i=0; i<num_e; i++) {

    fgets(buff, BUFFSIZE, fs);
    sscanf(buff, "%d %d %d", &edge[i][U], &edge[i][V], &edge[i][W]);
  }

#ifdef DEBUG
  printf("\n--- Initial Edges ---\n");
  for(i=1; i<num_v+1; i++) {
    if(vertex_cost[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", vertex_cost[i]);
  }
  printf("\n---------------------\n");
#endif

  for(i=0; i<num_v; i++) {
    for(j=0; j<num_e; j++) {
#ifdef DEBUG
      printf("Edge %d: ", j);
#endif
      process_edge(edge[j][U], edge[j][V], edge[j][W], vertex_cost, k);
    }
  }

  for(i=1; i<num_v+1; i++) {
    if(vertex_cost[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", vertex_cost[i]);
  }

  return 0;
}
