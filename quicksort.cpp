#include <iostream>

template<class T>
void swap(T& a, T& b) {  
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
int partition (T* arr, int start, int end) {
    // set pivot at the end
    int pivot = arr[end];
    int i = (start - 1);
 
    for (int j = start; j <= end - 1; j++) {
        // element < pivot
        if (arr[j] < pivot){
            // increment i(smaller) and swap with j
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // place pivot
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

template<class T>
void quickSort(T* arr, int start, int end) {   
    if (start < end){
        // index of pivot
        int index = partition(arr, start, end);
        // quicksort upperhalf
        quickSort(arr, start, index-1);
        // quicksort lowerhalf
        quickSort(arr, index+1, end);
    }
}


int main() {
    int size = 10;
    int arr[size];
    int randomVal;
    srand(time(0));

    std::cout << "|Before Sort|" << std::endl;


    for(int i; i<size; i++) {
        randomVal = rand() % 100;
        arr[i] = randomVal;
        std:: cout << arr[i] << " ";
    }

    std::cout << "\n|After Sort|" << std::endl;
    quickSort(arr, 0, size-1);

    // print array
    for(int i: arr) {
        std::cout << i << " "; 
    }

    std::cout << "\nCompelete" << std::endl;
}