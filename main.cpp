#include <iostream>
#include <SFML/Graphics.hpp>
#include <set>
#include <random>

using namespace std;

sf::RenderWindow display(sf::VideoMode(1200,800),"Algorithms Visual");
sf::Event event;

void displayArray(vector<int> array);



//BUBBLE SORT
void bubbleSort(vector<int> arr)
{
    int n = arr.size();
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            displayArray(arr);
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}


// HEAP SORT
void heapify(vector<int> &arr, int N, int i)
{
    displayArray(arr);
    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
void heapSort(vector<int> &arr)
{
    int N = arr.size();
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


// INSERTION SORT
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            displayArray(arr);
        }
        arr[j + 1] = key;
    }
}


// SELECTION SORT
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
        displayArray(arr);
    }
}


// QUICK SORT
int partition(vector<int> &arr,int low,int high)
{
    //choose the pivot

    int pivot=arr[high];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i=(low-1);

    for(int j=low;j<=high;j++)
    {
        displayArray(arr);
        //If current element is smaller than the pivot
        if(arr[j]<pivot)
        {
            //Increment index of smaller element
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quickSort(vector<int> &arr,int low,int high)
{
    // when low is less than high
    if(low<high)
    {
        // pi is the partition return index of pivot
        displayArray(arr);
        int pi=partition(arr,low,high);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}


// MERGE SORT

void merge(vector<int> &array, int const left,
           int const mid, int const right)
{
    displayArray(array);
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[]
    // and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    // Initial index of first sub-array
    // Initial index of second sub-array
    auto indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;

    // Initial index of merged array
    int indexOfMergedArray = left;

    // Merge the temp arrays back into
    // array[left..right]
    while (indexOfSubArrayOne < subArrayOne &&
           indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <=
            rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] =
                    leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] =
                    rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] =
                leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] =
                rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector<int> &array,
               int const begin,
               int const end)
{
    // Returns recursively
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}





int main() {
    srand(time(NULL));
    display.setFramerateLimit(600);





    int n = 500;
    vector<int> array;
    for(int i=1; i<n+1; i++) array.push_back(i);

    unsigned seed=0;
    shuffle(array.begin(),array.end(),default_random_engine(seed));










//    int k, j;
//
//    bool swapped = true;

    while(display.isOpen())
    {
        while(display.pollEvent(event))
        {
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) display.close();
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) bubbleSort(array);
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) insertionSort(array);
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) selectionSort(array);
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) heapSort(array);
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) quickSort(array,0,n);
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) mergeSort(array,0,n);
            if(event.type == event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                shuffle(array.begin(),array.end(),default_random_engine(seed));
            }

        }


//        heapSort(array,array.size());
//        selectionSort(array);
//        insertionSort(array);




        displayArray(array);

    }



    return 0;
}




void displayArray(vector<int> array)
{
    int n = array.size();
    float szerokoscKolumny = float(display.getSize().x-100)/(n+1);
    float wysokoscKolumny = float(display.getSize().y-100)/(n+1);

    sf::RectangleShape kolumna(sf::Vector2f(szerokoscKolumny,wysokoscKolumny));
    kolumna.setOrigin(szerokoscKolumny/2,0);
    kolumna.setPosition(szerokoscKolumny/2,0);
//    kolumna.setOutlineThickness();
//    kolumna.setOutlineColor(sf::Color::Black);

    display.clear();
    for (int i = 0; i < n; i++) {
        kolumna.setSize(sf::Vector2f(szerokoscKolumny, array[i] * wysokoscKolumny));
        kolumna.setOrigin(szerokoscKolumny/2,0);
        kolumna.setPosition(50+szerokoscKolumny/2 + float(i) * (szerokoscKolumny), float(display.getSize().y-50)-array[i] * wysokoscKolumny);
        display.draw(kolumna);
    }
    display.display();
}