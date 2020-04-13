/* <graph.c> */
#include "graph.h"
#include <string.h>   // C standard library

int find_neighbor(const struct graph g, const vertex v, vertex *result) {

   int i;
   vertex u;
   int result;

   result = -1;

   for(i=0; i<g.num_edge_list; i++) {

      u = g.e[i].src;
      if(u == v) {

        memcpy(result, g.e[i].dest, sizeof(vertex) * g.e[i].num_dest);
        result = g.e[i].num_dest;
        break;
      }
   }

   return result;
}
