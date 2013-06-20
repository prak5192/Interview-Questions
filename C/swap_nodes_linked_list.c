#if 0
A complete swap algorithm which cares of several scenarios while 
swapping two nodes in a linked list which doesn't have any special 
nodes.
Senarios considered while swapping:-
1)two nodes which are far away
2)two nodes which are far away, one is node is at beginning of 
the list
3)two node which are neighbors
4)two nodes which are neibhors, one node is at beginning of the 
list

#endif

Node *SwapNodes(Node *list, Node *node1, Node *node2)
{
  Node *node1prev, *node2prev, *tmp;

  node1prev = FindPrev(list, node1);
  node2prev = FindPrev(list, node2);

  tmp = node2->next;

  /* check whether node to swapped is in beggining (i.e. header node) */
  if (node1 != list){
    node1prev->next = node2;
  } else {
    /* as we do not have special header node,if the first node and some
     other node, need to be swapped, then update the list (
     makes new min node as logical header) */
    list = node2;
  }

  /* are nodes to be swapped neibgoring nodes? */
  if (node1->next == node2){
    /* nodes to be swapped are neibhoring nodes, then swap them simply */
    node2->next = node1;
    node1->next = tmp;
  } else {
    /* nodes to be swapped are not neibhor nodes,they are apart
    so, consider all scenarios */
    node2->next = node1->next;
    node1->next = tmp;
    node2prev->next = node1;
  }
  return list;
}
