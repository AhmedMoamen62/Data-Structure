#include <iostream>
#include "Dynamicarray.h"
#include "Linkedlist.h"
using namespace std;

int binary_search(int,int*,int);
int find_max(int*,int);
int sum(int*,int);
void decimal2binary(int);
void print_even(int);
int factorial(int);
int fibbonaci(int);
template <typename T>
void swap(T&,T&);
template <typename T>
void bubbl_sort(int,T*);
int main()
{
    Linkedlist<int> x;
    x.push_back(8);
    x.push_back(-2);
    x.push_back(4);
    x.push_back(140);
    x.push_back(-10);
    x.push_back(30);
    x.print();
    x.bubble_sort();
    x.print();
    x.removeAt(3);
    x.print();
    x.removeAt(2);
    //    x[3]++;
    //    cout << x[3] << endl;
    //cout << x.indexOf(200) << endl;
    x.print();
    x.insertAt(2,18);
    //x.pop_front();
    x.print();
    cout << x.length() << endl;
    cout << x.contains(4) << endl;
    x.remove(-2);
    x.print(1);
    x.clear();
    x.print(1);
    //    int arr[5];
    //    arr[0] = -5;
    //    arr[1] = 100;
    //    arr[2] = 1;
    //    arr[3] = 7;
    //    arr[4] = 17;
    //    cout << binary_search(5,arr,17) << endl;
    //    Dynamicarray<int> x;
    //    x.setsize(5);
    //    x.setel(3,5);
    //    x[2]++;
    //    cout << x[2] << endl;
    //    cout << find_max(arr,5) << endl;
    //    cout << sum(arr,5) << endl;
    //    decimal2binary(7);
    //    cout << endl;
    //    print_even(10);
    //    cout << endl;
    //    cout << factorial(6) << endl;
    //    cout << fibbonaci(6) << endl;



    //    float * array;
    //    int arr_len;
    //    cin >> arr_len;
    //    array = new float [arr_len];

    //    float fact_i = 1;
    //    array[0] = 1;
    //    for(int i = 1 ; i < arr_len ; i++)
    //    {
    //        fact_i *= i;
    //        array[i] = 1.0/fact_i;
    //    }
    //    float sum = 0;
    //    for(int i = 0 ; i < arr_len ; i++)
    //    {
    //        sum += array[i];
    //    }
    //    cout << sum << endl;

    return 0;
}

template <typename T>
void swap(T& a,T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void bubbl_sort(int n,T* arr)
{
    for(int i = 0; i < n ; i++)
    {
        bool swapped = false;
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j],arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            return;
    }
}

int fibbonaci(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return fibbonaci(n - 1) + fibbonaci(n - 2);
}

int factorial(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }
    return n*factorial(n - 1);
}

void print_even(int n)
{
    if(n >= 0)
    {
        print_even(n - 2);
        cout << n << " ";
    }
}

void decimal2binary(int n)
{
    if(n > 0)
    {
        decimal2binary(n/2);
        cout << n%2;
    }
}

// O(n)
int sum(int* arr,int n)
{
    if(n == 1)
    {
        return arr[0];
    }
    return arr[n - 1] + sum(arr, n - 1);
}
// O(n)
int find_max(int* arr,int n)
{
    if(n == 1)
    {
        return arr[0];
    }
    return max(arr[n - 1],find_max(arr,n - 1));
}
// O(log n)
int binary_search(int n,int* arr,int value)
{
    int low = 0;
    int high = n-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else if (arr[mid] > value)
        {
            high = mid - 1;
        }
    }
    return -1;
}
