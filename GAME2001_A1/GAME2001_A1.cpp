#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"

using namespace std;

int main()
{
    cout << "Ordered Array" << endl << endl;
    OrderedArray<int> orderedArray(3);

    orderedArray.push(15);
    orderedArray.push(10);
    orderedArray.push(6);
    orderedArray.push(32);
    orderedArray.push(13);
    orderedArray.push(3);
    orderedArray.push(1);
    orderedArray.push(50);
    orderedArray.push(8);

    for (int i = 0; i < orderedArray.GetSize(); i++)
    {
        cout << orderedArray[i] << " ";
    }
    cout << endl;

    orderedArray.pop();
    orderedArray.remove(4);
    orderedArray.remove(2);
    orderedArray.push(13);
    orderedArray.push(14);
    orderedArray.push(15);

    for (int i = 0; i < orderedArray.GetSize(); i++)
    {
        cout << orderedArray[i] << " ";
    }
    cout << endl;

    cout << "Number 6 is at index " << orderedArray.search(6) << endl;
    cout << "Number 8 is at index " << orderedArray.search(8) << endl;
    cout << "Number 13 is at index " << orderedArray.search(13) << endl;
    cout << endl;

    cout << "Unordered Array" << endl << endl;
    UnorderedArray<int> unorderedArray(3);

    unorderedArray.push(15);
    unorderedArray.push(10);
    unorderedArray.push(6);
    unorderedArray.push(32);
    unorderedArray.push(13);
    unorderedArray.push(3);
    unorderedArray.push(1);
    unorderedArray.push(50);
    unorderedArray.push(8);

    for (int i = 0; i < unorderedArray.GetSize(); i++)
    {
        cout << unorderedArray[i] << " ";
    }
    cout << endl;

    unorderedArray.pop();
    unorderedArray.remove(4);
    unorderedArray.remove(2);
    unorderedArray.push(13);
    unorderedArray.push(14);
    unorderedArray.push(15);

    for (int i = 0; i < unorderedArray.GetSize(); i++)
    {
        cout << unorderedArray[i] << " ";
    }
    cout << endl;

    cout << "Number 6 is at index " << unorderedArray.search(6) << endl;
    cout << "Number 8 is at index " << unorderedArray.search(8) << endl;
    cout << "Number 13 is at index " << unorderedArray.search(13) << endl;
}
