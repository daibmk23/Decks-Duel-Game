#include "Heap.h"
#include "iostream"
using namespace std;

Heap::Heap() {
    size = 0;
}

bool Heap::isHeapEmpty() const {
    if (size == 0){
        return true;
    }
    return false;
}

void Heap::insertToHeap(const int &newItem) {
    if (size >= MAX_HEAPSPACE) {
        cout << "Heap full" << endl;
        return;
    }

    heapArray[size] = newItem;
    int place = size;
    int parent = (place - 1) / 2;
    while ( (place > 0) && (heapArray[place] < heapArray[parent]) ) {
        int temp = heapArray[parent];
        heapArray[parent] = heapArray[place];
        heapArray[place] = temp;
        place = parent;
        parent = (place - 1) / 2;
    }
    size++;
}

void Heap::deleteFromHeap() {
    if (isHeapEmpty()) {
        cout << "Heap is empty." << endl;
        return;
    }
    int heapRoot = heapArray[0];
    int size2 = size - 1;
    heapArray[0] = heapArray[size2];
    rebuildHeap(0);
    size--;
}

void Heap::rebuildHeap(int root) {
    int child = (2*root) + 1;  //child = leftChild

    if (child < size) {
        int rightChild = child + 1;

        if (rightChild < size && (heapArray[rightChild] < heapArray[child])) {
            child = rightChild;
        }
        //child is smaller of right and left
        //for min heap, if root item is greater than the child, swap

        if (heapArray[root] > heapArray[child]) {
            int temp = heapArray[root];
            heapArray[root] = heapArray[child];
            heapArray[child] = temp;
            rebuildHeap(child);
        }
    }
}

bool Heap::isInLeastArray(int value) const {
    for (int i = 0; i < 5; i++) {
        if (leastArr[i] == value) {
            return true;
        }
    }
    return false;
}

int Heap::getSize() const{
    return size;
}

void Heap::display() {
    for (int i = 0; i < size; i++){
        cout<<heapArray[i]<<" ";
    }
    cout << endl;
}

void Heap::findLeast5(_IO_FILE *pFile) const {
    if (size < 5) {
        fprintf(pFile, "-1\n");
        return;
    }

    int least5[5];
    int currentChildren[5];
    int candidateCount = 0;

    least5[0] = heapArray[0];
    currentChildren[0] = 1;
    currentChildren[1] = 2;
    candidateCount = 2;

    int leastCount = 1;

    while (leastCount < 5) {
        int minIndex = -1;
        int minValue = 1000000;

        for (int i = 0; i < candidateCount; i++) {
            int indexChild = currentChildren[i];
            if (indexChild < size && heapArray[indexChild] < minValue) {
                minValue = heapArray[indexChild];
                minIndex = i;
            }
        }

        least5[leastCount] = minValue;
        leastCount++;

        int chosenIdx = currentChildren[minIndex];
        int leftChild = 2 * chosenIdx + 1;
        int rightChild = 2 * chosenIdx + 2;

        currentChildren[minIndex] = leftChild;
        if (candidateCount < 5 && rightChild < size) {
            currentChildren[candidateCount++] = rightChild;
        }
    }

    for (int i = 0; i < 5; i++) {
        fprintf(pFile, "%d\n", least5[i]);
    }
}
