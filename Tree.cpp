#include <vector>
#include "Tree.hpp"
using namespace std;

int main() try {
  ariel::Tree tree;
  
  cout << "Current size is " << tree.size() << "\n";
  
  //cout << tree.root() << " is in the root of the tree\n"; //should throw an exception: "Empty tree!"
  
  vector <int> my_data {5,3,6,4,2,1,8,7,9};
  for (int i=0; i < my_data.size(); i++) {
    int curr = my_data[i];
    cout << "Insert " << curr << "\n";
    tree.insert(curr);
  }
  cout << "\n";
  //tree.insert(6); // should throw an exception: "6 already exists"
  
  cout << "The tree:\n";
  tree.print();
  cout << "\n";
  
  cout << "Current size is " << tree.size() << "\n";
  cout << "\n";
  
  cout << "Does tree contains 1? " << tree.contains(1) << "\n";
  cout << "Does tree contains 15? " << tree.contains(15) << "\n";
  cout << "\n";
  cout << tree.root() << " is in the root of the tree\n";
  cout << "\n";
  
  cout << "The parent of 3 is " << tree.parent(3) << "\n";
  cout << "The parent of 7 is " << tree.parent(7) << "\n";
  //cout << "The parent of 6 is " << tree.parent(5) << "\n"; //should throw an exception: "No parent for root!"
  cout << "\n";
  
  cout << "The left offspring of 5 is " << tree.left(5) << "\n";
  cout << "The right offspring of 6 is " << tree.right(6) << "\n";
  cout << "The left offspring of 8 is " << tree.left(8) << "\n";
  //cout << "The left offspring of 7 is " << tree.left(7) << "\n"; //should throw an exception: "7 doesn't have a left child!"
  cout << "\n";
  
  cout << "Let's deconstruct the tree from its root:\n";
  int curr_size = tree.size();
  for (curr_size; curr_size > 1; curr_size--) {
    int r = tree.root();
    tree.remove(r);
    cout << "The current size is " << curr_size << "\n";
    cout << "Root to remove is " << tree.root() << "\n";
    cout << "New tree:\n";
    tree.print();
    cout << tree.root() << " is in a new root of the tree\n\n";
  }
  
  return 0;
} catch (string error) { 
  cerr << error << endl;
  return 1;
}
