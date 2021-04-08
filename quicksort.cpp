#include <iostream>

template<class T>
void swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
 
int c=1;
template<class T>
int partition (T* array, int start, int end)
{   
    c++;
    // pivot is the last element
    T pivot = array[end];
    // i is the most left, j is the most right index
    int i = start, j = end-1;

    // condition: i < j
    while(i<j){
        // compare the left value with pivot
        // increment until find greater value
        while(array[i]<=pivot){
            i++;
        }
        // i could have been incremented
        while(pivot<array[j] && i<j){
            j--;
        }
        // i != j swap still should happen
        if(i<j){
            swap(&array[i], &array[j]);

        }
    }
    // i = j can happen for multiple reasons
    // 1. i < pi and pi < j, pass the test, then i and j meet in the middle
    if(i<=j && array[j] > array[end])
        swap(&array[j], &array[end]);



    return j;

        
}
 


template<class T>
void quickSort(T* array, int start, int end)
{
    if (start < end){
        int pi = partition(array, start, end);
        quickSort(array, start, pi - 1);
        quickSort(array, pi + 1, end);
    }
}


int main() {
    int size = 10;
    int array[size];
    int randomVal;
    srand(time(0));

    std::cout << "|Before Sort|" << std::endl;


    for(int i; i<size; i++){
        randomVal = rand() % 100;
        array[i] = randomVal;
        std:: cout << array[i] << " ";
    }

    std::cout << "\n|After Sort|" << std::endl;
    quickSort(array, 0, size-1);

    // print array
    for(int i: array){
        std::cout << i << " "; 
    }

    std::cout << "\nCompelete" << std::endl;
}