template<class T>
int Heap<T>::getItem(T item) {
    for (int i = 0; i < count; ++i) {
        if (elements[i] == item) {
            return i; 
        }
    }
    return -1; 
}

template<class T>
void Heap<T>::remove(T item) {
    int index = getItem(item);

    if (index == -1) {
        return; 
    }

    elements[index] = elements[count - 1];
    count--;

    reheapDown(index);
}

template<class T>
void Heap<T>::clear() {
    count = 0;

    delete[] elements;
    capacity = 10;
    elements = new T[capacity];
}
