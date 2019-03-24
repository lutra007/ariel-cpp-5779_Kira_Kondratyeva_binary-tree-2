#include <iostream>
using namespace std;

struct Node {
  int x;
  Node *left;
  Node *right;
};

namespace ariel {
class Tree {
public:  
  ~Tree();
  void insert(int key);
  bool contains(int key);
  void remove(int key);
  int parent(int key);
  int left(int key);
  int right(int key);
  void print();
  int root();
  int size();
  
private:
  Node *my_tree = NULL;
  int tree_size = 0;
  
  void insert(int x, Node *&MyTree);
  bool search(int key,Node *&my_tree);
  void remove(int x, Node *&MyTree);
  int parent(int key, int par, Node *&my_tree);
  int leaf(int key, bool check_side, Node *&my_tree);
  void print(Node *&my_tree);
  int bring_left(Node *&MyTree);
  bool empty(Node *&MyTree);
  int root(Node *&my_tree);
  void del(Node *&my_tree);
};
}
