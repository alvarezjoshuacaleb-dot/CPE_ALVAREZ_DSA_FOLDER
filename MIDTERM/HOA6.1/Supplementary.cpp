#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Linear search for array
int linearSearchArray(int arr[], int size, int key) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            return comparisons;
        }
    }
    return comparisons;
}

// Linear search for linked list
int linearSearchLinkedList(Node* head, int key) {
    int comparisons = 0;
    Node* current = head;

    while (current != NULL) {
        comparisons++;
        if (current->data == key) {
            return comparisons;
        }
        current = current->next;
    }

    return comparisons;
}

// PROBLEM 2 - COUNT REPEATING INSTANCES IN ARRAY
int countRepeatingArray(int arr[], int size, int key) {

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++;
        }
    }

    return count;
}


// PROBLEM 2 - COUNT REPEATING INSTANCES IN LINKED LIST
int countRepeatingLinkedList(Node* head, int key) {

    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}


// PROBLEM 3 - BINARY SEARCH
int binarySearch(int arr[], int size, int key) {

    int low = 0;
    int up = size - 1;
    int comparisons = 0;
    while (low <= up) {
        int mid = (low + up) / 2;

        comparisons++;

        std::cout << "Iteration " << comparisons<< ": low = " << low<< ", mid = " << mid
                  << ", up = " << up<< ", value = " << arr[mid]<< std::endl;
        if (arr[mid] == key) {

            std::cout << "Search element is found!"<< std::endl;
            std::cout << "Element found at index: "<< mid<< std::endl;
            return mid;
        }
        else if (key < arr[mid]) {
            up = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    std::cout << "Search element is not found"<< std::endl;
    return -1;
}


// PROBLEM 4 - RECURSIVE BINARY SEARCH
int recursiveBinarySearch(int arr[], int low, int up, int key) {

    if (low > up) {
        std::cout << "Search element is not found"<< std::endl;
        return -1;
    }

    int mid = (low + up) / 2;
    std::cout << "Recursive search: low = "<< low<< ", mid = "<< mid
              << ", up = "<< up<< ", value = "<< arr[mid]<< std::endl;
    if (arr[mid] == key) {
        std::cout << "Search element is found!"<< std::endl;
        std::cout << "Element found at index: "<< mid<< std::endl;
        return mid;
    }

    else if (key < arr[mid]) {
        return recursiveBinarySearch( arr,low,mid - 1,key
        );
    }
    else {
        return recursiveBinarySearch(arr,mid + 1,up,key);
    }
}


int main() {

    // PROBLEM 1
    // Given list
    int arr[10] = {
        15, 18, 2, 19, 18,0, 8, 14, 19, 14
    };

    int size = 10;
    int key = 18;

    // ARRAY SEARCH
    int arrayComparisons =
        linearSearchArray(arr, size, key);


    // CREATE LINKED LIST
    Node* head = new Node{15, NULL};
    head->next = new Node{18, NULL};
    head->next->next = new Node{2, NULL};
    head->next->next->next = new Node{19, NULL};
    head->next->next->next->next = new Node{18, NULL};
    head->next->next->next->next->next = new Node{0, NULL};
    head->next->next->next->next->next->next = new Node{8, NULL};
    head->next->next->next->next->next->next->next = new Node{14, NULL};
    head->next->next->next->next->next->next->next->next = new Node{19, NULL};
    head->next->next->next->next->next->next->next->next->next = new Node{14, NULL};

    // LINKED LIST SEARCH
    int linkedComparisons =
        linearSearchLinkedList(head, key);

    // DISPLAY RESULTS
    std::cout << "====================================" << std::endl;
    std::cout << "       SUPPLEMENTARY PROBLEM 1" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Array comparisons: "<< arrayComparisons << std::endl;
    std::cout << "Linked list comparisons: "<< linkedComparisons << std::endl;


    // PROBLEM 2

    int arrayCount =
        countRepeatingArray(arr, size, key);
    int linkedListCount =
        countRepeatingLinkedList(head, key);

    // DISPLAY RESULTS
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "       SUPPLEMENTARY PROBLEM 2" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Search element: " << key << std::endl;
    std::cout << "Repeating instances in array: "<< arrayCount << std::endl;
    std::cout << "Repeating instances in linked list: "<< linkedListCount << std::endl;


    // PROBLEM 3

    int sortedArray[10] = {3, 5, 6, 8, 11,12, 14, 15, 17, 18};
    int binaryKey = 8;
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "       SUPPLEMENTARY PROBLEM 3" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Sorted list: ";

    for (int i = 0; i < 10; i++) {
        std::cout << sortedArray[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Searching for: "<< binaryKey<< std::endl;

    binarySearch(
        sortedArray,10,binaryKey
    );


    // PROBLEM 4

    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "       SUPPLEMENTARY PROBLEM 4" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Sorted list: ";

    for (int i = 0; i < 10; i++) {
        std::cout << sortedArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Searching for: "<< binaryKey<< std::endl;
    recursiveBinarySearch(sortedArray,0,9,binaryKey);
    return 0;
}