#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
using namespace std;

int binary_search(int,int*,int);
int find_max(int*,int);
int sum(int*,int);
void decimal2binary(int);
void print_even(int);
int factorial(int);
int fibbonaci(int);
template <typename T>
void swapel(T&,T&);
template <typename T>
void bubbl_sort(int,T*);


template <typename T>
void swapel(T& a,T& b)
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

#endif // ALGORITHMS_H
