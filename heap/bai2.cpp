template<class T>
void Heap<T>::push(T item) {
    if (count == capacity) {
        ensureCapacity(capacity * 2); // Double the capacity if needed
    }
    elements[count] = item;
    count++;
    reheapUp(count - 1); // Reheap up from the last position
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity) {
    if (minCapacity > capacity) {
        int newCapacity = std::max(capacity * 2, minCapacity);
        T* newElements = new T[newCapacity];
        std::copy(elements, elements + count, newElements);
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position) {
    int parent = (position - 1) / 2;
    while (position > 0 && elements[position] > elements[parent]) {
        std::swap(elements[position], elements[parent]);
        position = parent;
        parent = (position - 1) / 2;
    }
}
