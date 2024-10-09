#include "Array.hpp"
#define MAX_VAL 750

int main() {
    {
    try {
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;

        Array<int> arr3 = arr2;
        std::cout << "Size of arr3 (copy of arr2): " << arr3.size() << std::endl;

        arr2[0] = 10;
        std::cout << "arr2[0]: " << arr2[0] << std::endl;
        std::cout << "arr3[0] (should be unchanged): " << arr3[0] << std::endl;

        try {
            std::cout << arr2[10] << std::endl; // This should throw an exception
        } catch (const std::out_of_range& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        for (unsigned int i = 0; i < arr2.size(); ++i) {
            arr2[i] = i + 1;
            std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "An exception occurred: " << e.what() << std::endl;
    }
    }
    {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    }
    return 0;
}
