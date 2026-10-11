#include "CrossArray.hpp"
#include <iostream>

void testBasicFunctionality() {
    std::cout << "=== Testing Basic Functionality ===" << std::endl;
    
    sjtu::CrossArray ca(3);
    
    // Test insertion
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {6, 7, 8, 9};
    
    bool result1 = ca.InsertArrays(arr1, 3);
    bool result2 = ca.InsertArrays(arr2, 2);
    bool result3 = ca.InsertArrays(arr3, 4);
    bool result4 = ca.InsertArrays(arr1, 1); // Should fail - capacity exceeded
    
    std::cout << "Insert 1: " << (result1 ? "success" : "failed") << std::endl;
    std::cout << "Insert 2: " << (result2 ? "success" : "failed") << std::endl;
    std::cout << "Insert 3: " << (result3 ? "success" : "failed") << std::endl;
    std::cout << "Insert 4 (should fail): " << (result4 ? "success" : "failed") << std::endl;
    
    // Test element access
    std::cout << "Element (0,0): " << ca.At(0, 0) << std::endl;
    std::cout << "Element (0,2): " << ca.At(0, 2) << std::endl;
    std::cout << "Element (1,1): " << ca.At(1, 1) << std::endl;
    std::cout << "Element (2,3): " << ca.At(2, 3) << std::endl;
    
    std::cout << std::endl;
}

void testCopyConstructor() {
    std::cout << "=== Testing Copy Constructor ===" << std::endl;
    
    sjtu::CrossArray ca1(2);
    int arr[] = {10, 20, 30};
    ca1.InsertArrays(arr, 3);
    
    sjtu::CrossArray ca2(ca1);
    
    // Modify original
    ca1.At(0, 0) = 99;
    
    // Check that copy is not affected
    std::cout << "Original (0,0): " << ca1.At(0, 0) << std::endl;
    std::cout << "Copy (0,0): " << ca2.At(0, 0) << std::endl;
    std::cout << "Is same? " << (ca1.IsSame(ca2) ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
}

void testAppend() {
    std::cout << "=== Testing Append ===" << std::endl;
    
    sjtu::CrossArray ca(2);
    int arr1[] = {1, 2};
    int arr2[] = {3, 4, 5};
    
    ca.InsertArrays(arr1, 2);
    std::cout << "Before append - (0,1): " << ca.At(0, 1) << std::endl;
    
    ca.AppendArrays(arr2, 0, 3);
    std::cout << "After append - (0,1): " << ca.At(0, 1) << std::endl;
    std::cout << "After append - (0,2): " << ca.At(0, 2) << std::endl;
    std::cout << "After append - (0,4): " << ca.At(0, 4) << std::endl;
    
    std::cout << std::endl;
}

void testDoubleCapacity() {
    std::cout << "=== Testing Double Capacity ===" << std::endl;
    
    sjtu::CrossArray ca(2);
    int arr[] = {1, 2};
    ca.InsertArrays(arr, 2);
    
    std::cout << "Before double - (0,0): " << ca.At(0, 0) << std::endl;
    
    ca.DoubleCrossLength();
    
    // Should still work after doubling
    std::cout << "After double - (0,0): " << ca.At(0, 0) << std::endl;
    
    // Should be able to insert more arrays now
    int arr2[] = {3, 4, 5};
    bool result = ca.InsertArrays(arr2, 3);
    std::cout << "Insert after double: " << (result ? "success" : "failed") << std::endl;
    std::cout << "New array (1,0): " << ca.At(1, 0) << std::endl;
    
    std::cout << std::endl;
}

void testWhichGreater() {
    std::cout << "=== Testing WhichGreater ===" << std::endl;
    
    sjtu::CrossArray ca1(3);
    sjtu::CrossArray ca2(3);
    
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    
    ca1.InsertArrays(arr1, 3);  // 3 elements
    ca2.InsertArrays(arr2, 2);  // 2 elements
    
    sjtu::CrossArray & greater1 = ca1.WhichGreater(ca2);
    std::cout << "Greater (3 vs 2): " << (&greater1 == &ca1 ? "ca1" : "ca2") << std::endl;
    
    ca2.InsertArrays(arr1, 3);  // ca2 now has 5 elements total
    sjtu::CrossArray & greater2 = ca1.WhichGreater(ca2);
    std::cout << "Greater (3 vs 5): " << (&greater2 == &ca1 ? "ca1" : "ca2") << std::endl;
    
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testCopyConstructor();
    testAppend();
    testDoubleCapacity();
    testWhichGreater();
    
    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}