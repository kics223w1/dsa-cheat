int binarySearch(int arr[], int left, int right, int x)
{
    if(right < left) {
        return -1;
    }
    
    int m = floor((right+left)/2) ;
   
    if(arr[m] == x) {
         cout << "We traverse on index: " << m << '\n';
        return m;
    }
    
    if(arr[m] > x) {
        cout << "We traverse on index: " << m << '\n';
        return binarySearch(arr, left , m -1, x);
    }

    
    cout << "We traverse on index: " << m << '\n';
    return binarySearch(arr, m + 1, right , x);
    
    
}