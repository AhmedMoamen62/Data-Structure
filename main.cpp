#include <iostream>
#include "Algorithms.h"
#include "Dynamicarray.h"
#include "Linkedlist.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "UnionFind.h"
#include "HashTable.h"
using namespace std;

int main()
{
    HashTable<string,int> x;
    x.insert("ahmed",3);
    // x.insert("mohamed",5);
    // x.insert("ahmed",6);
    x.insert("mohamed",5);
    // x.remove("ahmed");
    x.insert("ali",-10);
    x.insert("ayman",3);
    x.insert("shreef",41);
    x.insert("raye2",14);
    x["ali"] = 20;
    // x.clear();
    x.keys().print();
    x.values().print();
    cout << x.containsKey("ahmed") <<endl;
    cout << x.containsKey("amr") << endl;

    //    BinaryTree<int> x(3);
    //    x.remove(3);
    //    x.insert(2);
    //    x.insert(6);
    //    x.insert(5);
    //    x.insert(8);
    //    x.insert(6);
    //    cout << "Height : " << x.height() << endl;
    //    cout << "Leaves : " << x.number_of_leaves() << endl;
    //    x.insert(1);
    //    cout << x.is_balanced() << endl;
    //    x.print_postorder();
    //    x.insert(9);
    //    cout << "Height : " << x.height() << endl;
    //    cout << "Leaves : " << x.number_of_leaves() << endl;
    //    x.print_inorder();
    //    cout << x.find(6) << " " << x.find(8) << endl;
    //    x.remove(6);
    //    cout << "Height : " << x.height() << endl;
    //    cout << "Leaves : " << x.number_of_leaves() << endl;
    //    x.print_preorder();
    //    x.clear();
    //    x.print_inorder();

    //    Linkedlist<int> y;
    //    y.push_back(5);
    //    y.push_back(-2);
    //    y.push_back(1);
    //    y.pop_back();
    //    y.print();


    //    char y[5];
    //    y[0] = 'A';
    //    y[1] = 'B';
    //    y[2] = 'C';
    //    y[3] = 'D';
    //    y[4] = 'E';

    //    UnionFind<char> x(5,y);
    //    x.unify('A','B');
    //    x.unify('B','C');
    //    x.unify('C','D');

    //    Binary_Tree<string> x;
    //    x.initial();
    //    cout << number_of_leaves(x.tree_root()) << endl;
    //    cout << evaluate(x.tree_root()) << endl;
    //    cout << height_of_tree(x.tree_root()) << endl;

    //    int y[5];
    //    y[0] = -2;
    //    y[1] = 13;
    //    y[2] = 5;
    //    y[3] = 3;
    //    y[4] = 1;

    //    quick_sort(y,0,4);
    //    selection_sort(5,y);
    //    for(int i = 0 ; i < 5 ; i++)
    //        cout << y[i] << " ";
    //    cout << endl;

    //    Queue<int> x;
    //    x.push(13);
    //    x.push(6);
    //    x.job_statistics();
    //    x.pop();
    //    x.push(-6);
    //    x.print();

    //    Stack<int> x;
    //    x.push(10);
    //    x.push(20);
    //    x.print();
    //    x.clear();
    //    x.print();

    //    int y[5];
    //    y[0] = -2;
    //    y[1] = 13;
    //    y[2] = 5;
    //    y[3] = 3;
    //    y[4] = 1;
    //    int z[5];
    //    merge_sort(y,z,5);
    //    for(int i = 0 ; i < 5 ; i++)
    //        cout << z[i] << " ";
    //    cout << endl;

    //    Linkedlist<int> x;
    //    x.push_back(8);
    //    x.push_back(-2);
    //    x.push_back(4);
    //    x.push_back(140);
    //    x.push_back(-10);
    //    x.push_back(30);
    //    x.selection_sort();
    //    x.print();
    //    x.bubble_sort();
    //    x.print();
    //    x.removeAt(3);
    //    x.print();
    //    x.removeAt(2);
    //    //    x[3]++;
    //    //    cout << x[3] << endl;
    //    //cout << x.indexOf(200) << endl;
    //    x.print();
    //    x.insertAt(2,18);
    //    //x.pop_front();
    //    x.print();
    //    cout << x.length() << endl;
    //    cout << x.contains(4) << endl;
    //    x.remove(-2);
    //    x.print(1);
    //    x.clear();
    //    x.print(1);

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


