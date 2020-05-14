/**
 *   Problem: https://www.acmicpc.net/problem/2263
 *   Solver:  Jongho Kim <jongho_kim3@tmax.co.kr>
 */
#include <stdio.h>
#define MAX_N 100000

void print_preorder(int inorder_begin, int inorder_end, const int *inorder_list, int postorder_begin, int postorder_end, const int *postorder_list);

int main(int argc, char *argv[]) {

  int n;   // Number of nodes
  int inorder_list[MAX_N], postorder_list[MAX_N];
  int preorder_list[MAX_N];
  int i;

  // Read input
  scanf("%d", &n);

  for(i=0; i<n; i++)
    scanf("%d", &inorder_list[i]);

  for(i=0; i<n; i++)
    scanf("%d", &postorder_list[i]);

  //
  print_preorder(0, (n - 1), inorder_list, 0, (n - 1), postorder_list);
  printf("\n");

  return 0;
}

void print_preorder(int inorder_begin, int inorder_end, const int *inorder_list, int postorder_begin, int postorder_end, const int *postorder_list) {

  int root;
  int root_inorder;
  int lsubtree_root_postorder;   // Position of the root node of the left subtree
  int i, j;

  // NOTE: By post-order, the root node is always at the last
  root = postorder_list[postorder_end];

  // NOTE: By pre-order, the root node is always at the first
  printf("%d", root);

  // Find root node in the in-order list.
  // The root node should always exist
  root_inorder = -1;
  for(i=inorder_begin; i<=inorder_end; i++) {
    if(inorder_list[i] == root) {
      root_inorder = i;
      break;
    }
  }

  // This initialization can handle exception: the case in which the left subtree does not exist
  lsubtree_root_postorder = (postorder_begin - 1);

  if(root_inorder > inorder_begin) {   /* Check if the left subtree exists */
    printf(" ");

    // Find the root of the left subtree
    for(i=(postorder_end - 1); i>=postorder_begin; i--) {
      for(j=(root_inorder - 1); j>= inorder_begin; j--) {

        if(postorder_list[i] == inorder_list[j]) {
          lsubtree_root_postorder = i;
          goto print_left_subtree;
        }
      }
    }

    // Print the left subtree
print_left_subtree:
    print_preorder(inorder_begin, (root_inorder - 1), inorder_list, postorder_begin, lsubtree_root_postorder, postorder_list);
  }

  if(root_inorder < inorder_end) {   /* Check if the right subtree exists */
    printf(" ");
    // Print the right subtree
    print_preorder((root_inorder + 1), inorder_end, inorder_list, (lsubtree_root_postorder + 1), (postorder_end - 1), postorder_list);
  }
}
