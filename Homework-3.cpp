#include "AverageList.h"
#include "Matrica.h"

template<typename T>
class MyContainer
{
    T* arr;
    int _n;

public:

    class Iterator;
    MyContainer(int n = 1) : _n{ n }
    {
        arr = new T[n];
    }

    T& operator[] (const int& n)
    {
        if (n >= 0 && n < _n)
            return arr[n];

        return arr[0];
    }

    Iterator begin() { return arr; }
    Iterator end() { return arr + _n; }

    friend std::ostream& operator << (std::ostream& os, const MyContainer<T>& arr);

    class Iterator
    {
        T* curr;

    public:

        Iterator(T* curr) : curr{ curr }
        { }

        T& operator + (int n) { return *(curr + n);  }
        T& operator - (int n) { return *(curr - n); }

        T& operator ++ (int) { return *curr++; }
        T& operator -- (int) { return *curr--; }
        T& operator ++ () { return *++curr; }
        T& operator -- () { return *--curr; }

        bool operator != (const Iterator& it) { return curr != it.curr; }
        bool operator == (const Iterator& it) { return curr == it.curr; }
        
        T& operator * () { return *curr; }
    };
};

template<typename T>
std::ostream& operator << (std::ostream& os, const MyContainer<T>& n)
{
    os << MyContainer<T>::arr[n];
    return os;
}

int main()
{
    system("chcp 1251");
    system("cls");

    /*
        1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.
    */
    std::cout << "Exercise 1:" << std::endl;

    AverageList av({0.1, 0.2, 0.3});

    std::cout << "Before: " << av << std::endl;
    av.addValue();
    std::cout << "After: " << av << std::endl;

    /*
        2. Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.
    */
    std::cout << std::endl;
    std::cout << "Exercise 2:" << std::endl;

    try
    {
        Matrica matrica(3);
        matrica.getDeterminant();
        std::cout << matrica << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    /*
        3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for-range-based.
    */
    std::cout << std::endl;
    std::cout << "Exercise 3:" << std::endl;

    MyContainer<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    for (auto v: arr)
    {
        std::cout << v << " ";
    }

    return 0;
}
