/**
 *  Solver: JONGHO KIM <jongho_kim3@tmax.co.kr>
 *  https://www.acmicpc.net/problem/1753
 */

#include <stdio.h>

#define MAX_NUM_V   200000
#define MAX_NUM_E  3000000
#define MAX_K       200000   // 1 <= K <= num_v
#define MIN_W            1
#define MAX_W           10
#define BUFFSIZE        10


int main(int argc, char *argv[]) {

  int num_v, num_e;
  int k;
  int u, v, w;

  FILE *fs;
  char buff[BUFFSIZE];
  fs = stdin;

  // Read num_v and num_e
  fgets(buff, BUFFSIZE, fs);
  sscanf(buff, "%d %d", &num_v, &num_e);

  // Read k
  fgets(buff, BUFFSIZE, fs);
  sscanf(buff, "%d", &k);

  return 0;
}
