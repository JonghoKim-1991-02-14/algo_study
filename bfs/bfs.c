/* <bfs.c> */
#include <string.h>   // C standard library
#include "bfs.h"

const size_t BUFFSIZE = 1000;

// Returns length of the shortest path between v1 and v2.
// If an error occurs, negative number will be returned
int bfs(const struct graph g, const vertex v1, const vertex v2) {

   vertex discovered[BUFFSIZE]; // queue of vertices
   vertex buff[BUFFSIZE];
   int    visited[BUFFSIZE];   // key: vertex, value: whether visited (boolean)
   vertex u, w;
   int num_neighbor;
   int d_start, d_end, v_start, v_end;
   int depth;
   int i, j, k;

   memcpy(discovered, 0, BUFFSIZE * sizeof(vertex));
   memcpy(visited, 0, BUFFSIZE * sizeof(int));

   d_start = 0;
   d_end   = 0;
   v_end   = -1;
   discovered[0] = v1;   // We start from v1

   for(depth = 0; /* continue unless break */ ; depth++) {

      // Visit vertex u
      v_start = v_end + 1;
      v_end  += (d_end - d_start + 1);

      for(i=d_start; i<=d_end; i++) {

         u = discovered[i];
         visited[u] = 1;

         if(u == v2) goto exit_bfs;

	       // Discover vertex w, which is unvisited neighbor of vertex u
	       d_start = d_end + 1;

	       for(j=v_start; j<=v_end; j++) {

	          memcpy(buff, 0, BUFFSIZE * sizeof(vertex));
	          num_neighbor = find_neighbor(g, u, buff);

	          for(k=0; k<num_neighbor; k++) {

	             w = buff[k];

               // Not visited neighbors are added to queue
					     if(!visited[w]) {

	                discovered[d_end] = w;
	                d_end += 1;
	             }
	          }
	       }   // end discover
      }   // end visit
	 }   // end depdth

exit_bfs:

   return depth;
}
