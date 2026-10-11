#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;           // Array of pointers to int arrays
        int* sizes;            // Array to store size of each 1D array
        int capacity;          // Maximum number of parallel arrays
        int count;             // Current number of inserted arrays
        
    public:
        explicit CrossArray(int lines);
        CrossArray(const CrossArray & o);
        CrossArray & WhichGreater(CrossArray & o);
        bool IsSame(const CrossArray & o);
        bool InsertArrays(const int * Input, int size);
        void AppendArrays(const int * Input, int Line, int size);
        void DoubleCrossLength();
        const int * AtArray(int i);
        int & At(int i, int j);
        ~CrossArray();
    };
}

#endif