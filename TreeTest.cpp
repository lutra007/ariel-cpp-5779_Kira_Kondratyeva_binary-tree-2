/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */
#include <vector>
#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  ariel::Tree mytree;

  vector <int> my_data {5,3,6,4,2,1,8,7,9};
  for (int i=0; i < my_data.size(); i++) {
    int curr = my_data[i];
    mytree.insert(curr);
  }

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)

  .CHECK_THROWS(emptytree.root()) //should throw an exception: "Empty tree!"

  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (mytree.size(), 9)
  .CHECK_EQUAL (mytree.root(), 5)
  .CHECK_EQUAL (mytree.contains(1), true)
  .CHECK_EQUAL (mytree.contains(15), false)

  .CHECK_OK    (mytree.insert(10))
  .CHECK_THROWS(mytree.insert(7)) // should throw an exception: "7 already exists"
  .CHECK_THROWS(mytree.remove(11)) // should throw an exception: "11 doesn't exist"

  .CHECK_EQUAL (mytree.parent(3), 5)
  .CHECK_EQUAL (mytree.parent(9), 8)
  .CHECK_THROWS(mytree.parent(5)) //should throw an exception: "No parent for root!"

  .CHECK_EQUAL (mytree.left(5), 3)
  .CHECK_EQUAL (mytree.right(6), 8)
  .CHECK_THROWS(mytree.left(6)) //should throw an exception: "6 doesn't have a left child!"
  .CHECK_THROWS(mytree.right(4)) //should throw an exception: "4 doesn't have a right child!"

  .CHECK_OK    (mytree.print())

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
