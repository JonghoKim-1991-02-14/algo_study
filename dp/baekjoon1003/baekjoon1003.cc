/**
 *   Solver: JONGHO KIM <jongho_kim3@tmax.co.kr>
 *   https://www.acmicpc.net/problem/1003
 */

#include <cstdio>
#include <string>
using namespace std;

#define MAX_N   40

int fib[MAX_N][2];   // Store solutions
int cur_n;

void calfib(int n, int *zero, int *one) {

  int i;

  if(cur_n >= n) goto skip_filling;

  for(i=cur_n+1; i<=n; i++) {

    fib[i][0] = fib[i-1][0] + fib[i-2][0];
    fib[i][1] = fib[i-1][1] + fib[i-2][1];
  }


skip_filling:
  *zero = fib[n][0];
  *one  = fib[n][1];
}

int main(int argc, char *argv[]) {

  int t;   // number of test case
  int n;

  //
  int i;
  int zero, one;

  //
  cur_n = 1;
  fib[0][0] = 1;
  fib[0][1] = 0;
  fib[1][0] = 0;
  fib[1][1] = 1;

  scanf("%d", &t);
  for(i=0; i<t; i++) {
    scanf("%d", &n);
    calfib(n, &zero, &one);
    printf("%d %d\n", zero, one);
  }

  return 0;
}
