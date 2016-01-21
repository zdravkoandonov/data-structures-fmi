#include <iostream>
#include <functional>
#include <cstdlib>
#include <list>

using namespace std;

void reverseWithLambda(list<int> &l, void(*swap)(list<int>::iterator, list<int>::iterator))
{
    list<int>::iterator front = l.begin(), back = l.end();
    while (front != back)
    {
        swap(front, back);
        front++;
        back--;
    }
}

int main()
{
    list<int> l;
    for (int i = 0; i < 20; i++)
        l.push_back(rand() % 21);

    for (auto& i : l)
    {
        cout << i << endl;
    }

    reverseWithLambda(l, [] (list<int>::iterator front, list<int>::iterator back) { int tmp = *front; *front = *back; *back = tmp; });

    for (auto& i : l)
    {
        cout << i << endl;
    }

    return 0;
}
