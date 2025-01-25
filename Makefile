##########################
# Title: AVL Trees & Heap
# Author: Daib Malik
# ID: 22201013
# Section : 1
# Homework: 2
# Description : Makefile
###########################

SRCS = AVL.cpp Heap.cpp
HEADERS = AVL.h Heap.h TreeNode.h
.PHONY: all clean
all: game least5 prefixsubarray subarray
game: game.cpp $(SRCS) $(HEADERS)
	g++ -o game game.cpp $(SRCS)
least5: least5.cpp $(SRCS) $(HEADERS)
	g++ -o least5 least5.cpp $(SRCS)
prefixsubarray: prefixsubarray.cpp $(SRCS) $(HEADERS)
	g++ -o prefixsubarray prefixsubarray.cpp $(SRCS)
subarray: subarray.cpp $(SRCS) $(HEADERS)
	g++ -o subarray subarray.cpp $(SRCS)
clean:
	rm -f game least5 prefixsubarray *.o

