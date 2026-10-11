#ifndef SRC_HPP
#define SRC_HPP
// CrossArray implementation for problem 1410

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;           // Array of pointers to int arrays
        int* sizes;            // Array to store size of each 1D array
        int capacity;          // Maximum number of parallel arrays
        int count;             // Current number of inserted arrays
        
    public:
        explicit CrossArray(int lines) {
            capacity = lines;
            count = 0;
            arrays = new int*[capacity];
            sizes = new int[capacity];
            
            // Initialize all arrays to nullptr and sizes to 0
            for (int i = 0; i < capacity; i++) {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }

        CrossArray(const CrossArray & o) {
            capacity = o.capacity;
            count = o.count;
            arrays = new int*[capacity];
            sizes = new int[capacity];
            
            for (int i = 0; i < capacity; i++) {
                if (o.arrays[i] != nullptr) {
                    sizes[i] = o.sizes[i];
                    arrays[i] = new int[sizes[i]];
                    // Deep copy the elements
                    for (int j = 0; j < sizes[i]; j++) {
                        arrays[i][j] = o.arrays[i][j];
                    }
                } else {
                    arrays[i] = nullptr;
                    sizes[i] = 0;
                }
            }
        }

        ~CrossArray() {
            // Delete all allocated arrays
            for (int i = 0; i < capacity; i++) {
                if (arrays[i] != nullptr) {
                    delete[] arrays[i];
                    arrays[i] = nullptr;
                }
            }
            delete[] arrays;
            delete[] sizes;
        }

        bool InsertArrays(const int * Input, int size) {
            if (count >= capacity) {
                return false;  // Cannot insert more arrays than capacity
            }
            
            // Allocate new array and copy elements
            arrays[count] = new int[size];
            sizes[count] = size;
            
            for (int i = 0; i < size; i++) {
                arrays[count][i] = Input[i];
            }
            
            count++;
            return true;
        }

        void AppendArrays(const int * Input, int Line, int size) {
            // Line is guaranteed to be valid and array is already inserted
            int oldSize = sizes[Line];
            int newSize = oldSize + size;
            
            // Create new array with increased size
            int* newArray = new int[newSize];
            
            // Copy old elements
            for (int i = 0; i < oldSize; i++) {
                newArray[i] = arrays[Line][i];
            }
            
            // Copy new elements
            for (int i = 0; i < size; i++) {
                newArray[oldSize + i] = Input[i];
            }
            
            // Delete old array and update pointer
            delete[] arrays[Line];
            arrays[Line] = newArray;
            sizes[Line] = newSize;
        }

        CrossArray & WhichGreater(CrossArray & o) {
            int totalElements1 = 0;
            int totalElements2 = 0;
            
            // Count elements in this array
            for (int i = 0; i < count; i++) {
                totalElements1 += sizes[i];
            }
            
            // Count elements in other array
            for (int i = 0; i < o.count; i++) {
                totalElements2 += o.sizes[i];
            }
            
            if (totalElements1 >= totalElements2) {
                return *this;
            } else {
                return o;
            }
        }

        bool IsSame(const CrossArray & o) {
            // Check if they refer to the same memory space
            return (this == &o);
        }

        void DoubleCrossLength() {
            int newCapacity = capacity * 2;
            
            // Create new arrays with doubled capacity
            int** newArrays = new int*[newCapacity];
            int* newSizes = new int[newCapacity];
            
            // Copy existing arrays and sizes
            for (int i = 0; i < capacity; i++) {
                newArrays[i] = arrays[i];
                newSizes[i] = sizes[i];
            }
            
            // Initialize new positions to nullptr and 0
            for (int i = capacity; i < newCapacity; i++) {
                newArrays[i] = nullptr;
                newSizes[i] = 0;
            }
            
            // Delete old arrays and update
            delete[] arrays;
            delete[] sizes;
            arrays = newArrays;
            sizes = newSizes;
            capacity = newCapacity;
        }

        const int * AtArray(int i) {
            if (i >= 0 && i < capacity) {
                return arrays[i];
            }
            return nullptr;
        }

        int & At(int i, int j) {
            return arrays[i][j];
        }
    };
}

#endif