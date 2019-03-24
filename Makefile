all:
	clang++-5.0 -std=c++17 TreeTest.cpp Tree.cpp
tree:	
	clang++-5.0 -std=c++17 MyTree.cpp Tree.cpp
demo:
	clang++-5.0 -std=c++17 TreeDemo.cpp -o TreeDemo.o

