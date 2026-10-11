#ifndef SRC_HPP
#define SRC_HPP

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;
        int* sizes;
        int capacity;
        int count;
        
    public:
        explicit CrossArray(int lines) {
            capacity = lines;
            count = 0;
            arrays = new int*[capacity];
            sizes = new int[capacity];
            
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
                return false;
            }
            
            arrays[count] = new int[size];
            sizes[count] = size;
            
            for (int i = 0; i < size; i++) {
                arrays[count][i] = Input[i];
            }
            
            count++;
            return true;
        }

        void AppendArrays(const int * Input, int Line, int size) {
            int oldSize = sizes[Line];
            int newSize = oldSize + size;
            
            int* newArray = new int[newSize];
            
            for (int i = 0; i < oldSize; i++) {
                newArray[i] = arrays[Line][i];
            }
            
            for (int i = 0; i < size; i++) {
                newArray[oldSize + i] = Input[i];
            }
            
            delete[] arrays[Line];
            arrays[Line] = newArray;
            sizes[Line] = newSize;
        }

        CrossArray & WhichGreater(CrossArray & o) {
            int totalElements1 = 0;
            int totalElements2 = 0;
            
            for (int i = 0; i < count; i++) {
                totalElements1 += sizes[i];
            }
            
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
            return (this == &o);
        }

        void DoubleCrossLength() {
            int newCapacity = capacity * 2;
            
            int** newArrays = new int*[newCapacity];
            int* newSizes = new int[newCapacity];
            
            for (int i = 0; i < capacity; i++) {
                newArrays[i] = arrays[i];
                newSizes[i] = sizes[i];
            }
            
            for (int i = capacity; i < newCapacity; i++) {
                newArrays[i] = nullptr;
                newSizes[i] = 0;
            }
            
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