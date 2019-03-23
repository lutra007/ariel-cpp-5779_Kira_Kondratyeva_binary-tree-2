all:
	clang++-5.0 -std=c++17 TreeTest.cpp Tree.cpp
tree:	
	clang++-5.0 -std=c++17 Tree.cpp
test:
	clang++-5.0 -std=c++17 TreeTest.cpp
demo:
	clang++-5.0 -std=c++17 TreeDemo.cpp -o TreeDemo.o

