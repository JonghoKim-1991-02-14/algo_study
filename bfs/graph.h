/* <graph.h> */

#include <stdlib.h>   // C standard library
#include <stdint.h>   // C standard library

typedef uint32_t vertex;

struct edge {

  vertex  src;
  vertex  dest;
};

struct edge_list {

  vertex  src;
  vertex *dest;
  size_t  num_dest;
};


struct graph {

  vertex *v;
  struct edge_list *e;
  size_t num_vertex;
  size_t num_edge;   // For statistics
};


int insert_vertex_autoincrease(struct graph *g);
int insert_vertex(struct graph *g, const vertex v);

int insert_edge(struct graph *g, const struct edge e);

// This function finds neighbor vertices of vertex v and assign them to result,
// then returns number of neighbors.
// If an error occurs, the function returns a negative number
int find_neighbor(const struct graph g, const vertex v, vertex *result);
