#ifndef HW2_202_HEAP_H
#define HW2_202_HEAP_H
#include <cstdio>


const int MAX_HEAPSPACE = 1000000;

class Heap {
public:
    Heap();
    bool isHeapEmpty() const;
    void insertToHeap(const int& newItem);
    void deleteFromHeap();
    void display();
    void findLeast5(_IO_FILE *inpFile) const;
    //void findLeast5() const;
    int getSize() const;

protected:
    void rebuildHeap(int root);
private:
    int heapArray[MAX_HEAPSPACE]{};
    int size;
    int leastArr[5];
    bool isInLeastArray(int value) const;
};

#endif //HW2_202_HEAP_H
