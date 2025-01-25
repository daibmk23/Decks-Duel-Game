##########################
# Title: AVL Trees & Heap
# Author: Daib Malik
# Description : Makefile
###########################

SRCS = AVL.cpp Heap.cpp
HEADERS = AVL.h Heap.h TreeNode.h
.PHONY: all clean
all: game
game: game.cpp $(SRCS) $(HEADERS)
	g++ -o game game.cpp $(SRCS)
clean:
	rm -f game *.o

