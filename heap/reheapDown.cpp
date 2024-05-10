void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < numberOfElements && maxHeap[leftChild] > maxHeap[largest]) {
        largest = leftChild;
    }

    if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(maxHeap[index], maxHeap[largest]);
        reheapDown(maxHeap, numberOfElements, largest);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && maxHeap[index] > maxHeap[parent]) {
        swap(maxHeap[index], maxHeap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}