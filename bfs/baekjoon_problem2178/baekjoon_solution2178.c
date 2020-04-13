/* <solution2178.c> */
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
  //int edge_list[MAX_VERTEX][MAX_NEIGHBOR];   // edge_list[src vertex id][neighbor index] := dest vertex id
  int num_vertex;
  int n;
  int m;
};

#define BAEKJOON 1

int build_graph(int argc, char *argv[], struct graph *g) {

  int fd;
  FILE *fs;
  int r, c;   // row, column
  char buff[MAX_LINE_LEN];
  int line_len;

#ifdef BAEKJOON
  fs = stdin;
#else
  fs = fopen("input4.txt", "r");
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
  //memset(g->edge_list, 0, sizeof(int) * MAX_VERTEX * MAX_NEIGHBOR);
  g->num_vertex = 0;

  // Build a graph
  for(r=0; r<g->n; r++) {
    fgets(buff, line_len, fs);
#ifndef BAEKJOON
    printf("Line #%d: %s", r, buff);
#endif
    for(c=0; c<g->m; c++) {
      if(buff[c] == '1') {
        g->num_vertex += 1;
        g->vertex[r][c] = 1;
      }
    }
  }

#ifndef BAEKJOON
  fclose(fs);
#endif

  return 0;
}


int bfs(const struct graph g) {

  int discovered[MAX_VERTEX];
  int d_start, d_end, next_d_end;
  int visited[MAX_N][MAX_M];
  int row, col;
  int depth;
  int i, j;
  int u;   // vertex u

  // Init
  discovered[0] = 0;
  d_start = 0;
  d_end = 0;
  memset(visited, 0, sizeof(int) * MAX_N * MAX_M);

  for(depth=0; ; depth++) {

#ifndef BAEKJOON
    printf("Depth: %d\n", depth);
#endif
    next_d_end = d_end;

    for(i=d_start; i<=d_end; i++) {
      // Visit u
      u = discovered[i];
      row = u / g.m;
      col = u % g.m;
#ifndef BAEKJOON
      printf("\tVisit vertex u=%d, [%d][%d]\n", u, row, col);
#endif
      if(row == (g.n-1) && col == (g.m-1)) return depth;
      visited[row][col] = 1;

      // Discover w
      if(row > 0 && !visited[row-1][col] && g.vertex[row-1][col]) {
        next_d_end += 1;
        discovered[next_d_end] = (u - g.m);
#ifndef BAEKJOON
        printf("\t\tDiscover vertex w=%d, [%d][%d]\n", (u - g.m), (row-1), col);
#endif
      }

      if(col > 0 && !visited[row][col-1] && g.vertex[row][col-1]) {
        next_d_end += 1;
        discovered[next_d_end] = (u - 1);
#ifndef BAEKJOON
        printf("\t\tDiscover vertex w=%d, [%d][%d]\n", (u - 1), row, (col - 1));
#endif
      }

      if(row < (g.n-1) && !visited[row+1][col] && g.vertex[row+1][col]) {
        next_d_end += 1;
        discovered[next_d_end] = (u + g.m);
#ifndef BAEKJOON
        printf("\t\tDiscover vertex w=%d, [%d][%d]\n", (u + g.m), (row+1), col);
#endif
      }

      if(col < (g.m-1) && !visited[row][col+1] && g.vertex[row][col+1]) {
        next_d_end += 1;
        discovered[next_d_end] = (u + 1);
#ifndef BAEKJOON
        printf("\t\tDiscover vertex w=%d, [%d][%d]\n", (u + 1), row, (col + 1));
#endif
      }
    }

    d_start = (d_end + 1);
    d_end = next_d_end;
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

  // Print the answer
  printf("%d", answer);

  return 0;
}
