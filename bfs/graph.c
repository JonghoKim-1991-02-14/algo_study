/* <graph.c> */
#include "graph.h"
#include <string.h>   // C standard library

int find_neighbor(const struct graph g, const vertex_t v, vertex_t *result) {

   int i;
   vertex_t u;
   int num_neighbor;

   num_neighbor = -1;

   for(i=0; i<g.num_edge_list; i++) {

      u = g.e[i].src;
      if(u == v) {

        memcpy(result, g.e[i].dest, sizeof(vertex_t) * g.e[i].num_dest);
        num_neighbor = g.e[i].num_dest;
        break;
      }
   }

   return num_neighbor;
}
