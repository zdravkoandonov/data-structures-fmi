#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

struct IterAndSize
{
    list<int>::iterator iter;
    int size;
};

void printSubarr(IterAndSize arr)
{
    for (; arr.size > 0; arr.iter++, arr.size--)
        cout << *(arr.iter) << " ";
    cout << endl;
}

void merge(list<int> &arr, pair<IterAndSize, IterAndSize> lists)
{
    printSubarr(lists.first);
    printSubarr(lists.second);
    list<int>::iterator beginning = lists.first.iter;
    while (lists.first.size > 0 && lists.second.size > 0)
        if (lists.first.size == 0 || *(lists.first.iter) > *(lists.second.iter))
        {
            arr.splice(beginning, arr, lists.second.iter++);
            lists.second.size--;
        }
        else
        {
            arr.splice(beginning, arr, lists.first.iter++);
            lists.first.size--;
        }
}

pair<IterAndSize, IterAndSize> split(IterAndSize subarr)
{
    int size = subarr.size;
    pair<IterAndSize, IterAndSize> lists;
    lists.first.size = size / 2;
    lists.first.iter = subarr.iter;
    lists.second.size = size - lists.first.size;
    lists.second.iter = subarr.iter;
    advance(lists.second.iter, lists.first.size);

    return lists;
}

void sort(list<int> &arr, IterAndSize subarr)
{
    if (subarr.size > 1)
    {
        pair<IterAndSize, IterAndSize> lists = split(subarr);
        sort(arr, lists.first);
        sort(arr, lists.second);
        merge(arr, lists);
    }
}

void mergesort(list<int> &arr)
{
    IterAndSize subarr;
    subarr.size = arr.size();
    subarr.iter = arr.begin();
    sort(arr, subarr);
}

int main()
{
    list<int> arr;
    for (int i = 0; i < 25; i++)
        arr.push_back(rand() % 20);

    list<int>::iterator iter = arr.begin();
    for (; iter != arr.end(); iter++)
        cout << *iter << "\n";

    mergesort(arr);

    cout << "\n";
    iter = arr.begin();
    for (; iter != arr.end(); iter++)
        cout << *iter << "\n";

    return 0;
}
