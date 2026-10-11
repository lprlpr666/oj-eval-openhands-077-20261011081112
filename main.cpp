#include "solution.hpp"
#include <iostream>

int main() {
    // Simple test to verify compilation
    sjtu::CrossArray ca(5);
    
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    
    ca.InsertArrays(arr1, 3);
    ca.InsertArrays(arr2, 2);
    
    // Test element access
    std::cout << "Element at (0,0): " << ca.At(0, 0) << std::endl;
    std::cout << "Element at (0,1): " << ca.At(0, 1) << std::endl;
    std::cout << "Element at (1,0): " << ca.At(1, 0) << std::endl;
    
    // Test array access
    const int* arr = ca.AtArray(0);
    if (arr != nullptr) {
        std::cout << "First array elements: " << arr[0] << ", " << arr[1] << ", " << arr[2] << std::endl;
    }
    
    // Test append
    int appendArr[] = {6, 7, 8};
    ca.AppendArrays(appendArr, 0, 3);
    std::cout << "After append, element at (0,3): " << ca.At(0, 3) << std::endl;
    
    // Test copy constructor
    sjtu::CrossArray ca2(ca);
    std::cout << "Copied array element at (0,0): " << ca2.At(0, 0) << std::endl;
    std::cout << "Is same? " << (ca.IsSame(ca2) ? "true" : "false") << std::endl;
    
    // Test WhichGreater
    sjtu::CrossArray & greater = ca.WhichGreater(ca2);
    std::cout << "WhichGreater returned: " << (&greater == &ca ? "ca" : "ca2") << std::endl;
    
    // Test DoubleCrossLength
    ca.DoubleCrossLength();
    std::cout << "Capacity doubled successfully" << std::endl;
    
    return 0;
}