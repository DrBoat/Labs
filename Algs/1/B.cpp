#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
vector <pair <int, int> > heap;
 
void up (int i)
{
    int parent = (i - 1) / 2;
    while (i > 0 && heap[parent].first > heap[i].first)
    {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}
 
void down (int i)
{
    int leftChild;
    int rightChild;
    int largestChild;
    while(true)
    {
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
        largestChild = i;
        if (leftChild < heap.size() && heap[leftChild].first < heap[largestChild].first) 
        {
            largestChild = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild].first < heap[largestChild].first)
        {
            largestChild = rightChild;
        }
        if (largestChild == i) 
        {
            break;
        }
        swap(heap[i], heap[largestChild]);
        i = largestChild;
    }
}
 
void  push(int value, int j)
{
    heap.push_back(make_pair(value, j));
    up(heap.size() - 1);
}
 
 void extract_min ()
{
    if (heap.size() == 0)
    {
        cout << "*\n";
        return;
    }
    int rtn = heap[0].first;
    heap[0] = heap[heap.size() - 1];
    heap.resize(heap.size() - 1);
    down(0);
    cout << rtn << '\n';
    return;
}
 
void decrease_key (int ind, int val)
{
    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i].second == ind)
        {
            heap[i].first = val;
            up(i);
            down(i);
            return;
        }
    }
}
 
int main()
{
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    string command;
    int i = 0;
    while (cin >> command)
    {
        i++;
        if (command == "push")
        {
            int val;
            cin >> val;
            push(val, i);
        }
        else if (command == "extract-min")
        {
            extract_min();
        }
        else
        {
            int ind, val;
            cin >> ind >> val;
            decrease_key(ind, val);
        }
    }
    return 0;
}