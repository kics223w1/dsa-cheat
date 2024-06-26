/* Function to print an array */
    //Helping functions go here
	static void swap(T &a, T &b) {
		int temp = a;
		a = b;
		b = temp;
	}

    static void heapify(T* start, T* end, int index)
	{
		int size = end - start;
		int largest = index; 
		int l = 2 * index + 1; 
		int r = 2 * index + 2; 

		if (l < size && start[l] > start[largest])
			largest = l;

		if (r < size && start[r] > start[largest])
			largest = r;
	
		if (largest != index) {
			swap(start[index], start[largest]);
			heapify(start, end, largest);
		}
	}

	static void heapSort(T* start, T* end)
	{
        // TODO
		int size = end - start;
		for (int i = size / 2 - 1; i >= 0; i--)
			heapify(start, end, i);
	
		for (int i = size - 1; i > 0; i--) {
			swap(start[0], start[i]);
			heapify(start, start + i, 0);
		}
		Sorting<T>::printArray(start, end);
	}