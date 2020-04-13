/* <baekjoon_solution2178.c> */
// Solver: JONGHO KIM <jongho_kim3@tmax.co.kr>
// See https://www.acmicpc.net/problem/2178

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Given by problem
#define MIN_N     2
#define MAX_N   100
#define MIN_M     2
#define MAX_M   100

// The newline and NULL will exist
#define MAX_LINE_LEN   (MAX_M + 2)

#define MAX_VERTEX     (MAX_N * MAX_M)
#define MAX_NEIGHBOR   4

struct graph {

  int vertex[MAX_N][MAX_M];   // vertex[row][col] := vertex id
  /* NO edges */
  int n;
  int m;
};

const int dx[MAX_NEIGHBOR] = {1, 0, -1,  0};
const int dy[MAX_NEIGHBOR] = {0, 1,  0, -1};

#define BAEKJOON 1

/* Function declarations in order to use inline functions */
int build_graph(int argc, char *argv[], struct graph *g);
int bfs(const struct graph g);

inline int build_graph(int argc, char *argv[], struct graph *g) {

  int fd;
  FILE *fs;
  int r, c;   // row, column
  char buff[MAX_LINE_LEN];
  int line_len;

#ifdef BAEKJOON
  fs = stdin;
#else
  fs = fopen("input1.txt", "r");
#endif

  // Read n and m
  fgets(buff, MAX_LINE_LEN, fs);
  sscanf(buff, "%d%d", &g->n, &g->m);
#ifndef BAEKJOON
  printf("N: %d\nM: %d\n", g->n, g->m);
#endif

  // Flush the buffer
  memset(buff, 0, sizeof(char) * MAX_LINE_LEN);
  line_len = g->m + 2;

  // Init
  memset(g->vertex, 0, sizeof(int) * MAX_VERTEX);

  // Build a graph
  for(r=0; r<g->n; r++) {
    fgets(buff, line_len, fs);
#ifndef BAEKJOON
    printf("Line #%d: %s", r, buff);
#endif
    for(c=0; c<g->m; c++) {
      if(buff[c] == '1') {
        g->vertex[r][c] = 1;
      }
    }
  }

#ifndef BAEKJOON
  fclose(fs);
#endif

  return 0;
}


inline int bfs(const struct graph g) {

  int visited[MAX_N][MAX_M];
  int discovered[MAX_N][MAX_M];
  int queue_row[MAX_VERTEX];
  int queue_col[MAX_VERTEX];
  int queue_start, queue_end;
  int current_depth_queue_start, current_depth_queue_end;
  int u_row, u_col;
  int tmp_row, tmp_col;
  int w_row, w_col;
  int depth;
  int i, j;

  // Init
  queue_row[0] = 0;
  queue_col[0] = 0;
  queue_start = 0;
  queue_end = 0;
  memset(visited, 0, sizeof(int) * MAX_N * MAX_M);
  memset(discovered, 0, sizeof(int) * MAX_N * MAX_M);

  for(depth=0; queue_start <= queue_end; depth++) {

#ifndef BAEKJOON
    printf("Depth: %d\n", depth);
#endif

    current_depth_queue_start = queue_start;
    current_depth_queue_end = queue_end;

    for(i=current_depth_queue_start; i<=current_depth_queue_end; i++) {
      // Visit u
      ++queue_start;
      u_row = queue_row[i];
      u_col = queue_col[i];
#ifndef BAEKJOON
      printf("\tVisit vertex u: [%d][%d]\n", u_row, u_col);
#endif
      if(u_row == (g.n-1) && u_col == (g.m-1)) return depth;
      visited[u_row][u_col] = 1;

      // Discover w
      for(j=0; j<MAX_NEIGHBOR; j++) {
        tmp_row = u_row + dx[j];
        tmp_col = u_col + dy[j];
        if(tmp_row >= 0 && tmp_row < g.n && tmp_col >=0 && tmp_col < g.m && g.vertex[tmp_row][tmp_col] && !visited[tmp_row][tmp_col] && !discovered[tmp_row][tmp_col]) {
          w_row = tmp_row;
          w_col = tmp_col;
#ifndef BAEKJOON
          printf("\t\tDiscover vertex w: [%d][%d]\n", w_row, w_col);
#endif
          ++queue_end;
          discovered[w_row][w_col] = 1;
          queue_row[queue_end] = w_row;
          queue_col[queue_end] = w_col;
        }
      }
    }
  }

  return -1;
}


int main(int argc, char *argv[]) {

  struct graph g;
  int path_len;
  int answer;

  build_graph(argc, argv, &g);
  path_len = bfs(g);
  answer = path_len + 1;


#ifndef BAEKJOON
  printf("\nANSWER: ");
#endif

  // Print the answer
  printf("%d", answer);

#ifndef BAEKJOON
  printf("\n");
#endif

  return 0;
}
