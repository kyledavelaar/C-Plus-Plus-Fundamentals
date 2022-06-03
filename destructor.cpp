#include <iostream>

/*
    - if have dynamically allocated memory variables or file/db handle, you need to add a destructor to your class to clean up
    - can only have one destructor per class
    - destructors called once when the object destroyed
    - if you use the exit() function the destructor will not be called
*/

class IntArray {
    private:
        // dynamically allocating size
        int* m_arr{};
        int m_length{};

    public:
        IntArray(int len) {
            m_arr = new int[static_cast<std::size_t>(len)]{};
            m_length = len;
        }

        // Destructor
        ~IntArray() {
            // clean up by deleting the array with dynamically allocated memory
            delete[] m_arr;
            std::cout << "destructor executed" << '\n';
        }

        void set(int index, int value) {
            m_arr[index] = value;
        }

        int get(int index) {
            return m_arr[index];
        }

        int length() {
            return m_length;
        }
};

int main() {
    IntArray myArr(5);
    myArr.set(0, 99);
    myArr.set(1, 100);

    for (int i = 0; i < myArr.length(); i++) {
        std::cout << "item " << myArr.get(i) << '\n';
    }


    return 0;
}
// destructor called here b/c myArr is no longer in scope