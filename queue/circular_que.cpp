#include <iostream>

using namespace std;

class cirque
{
    int front;
    int rear;

    int size;
    int *arr;

public:
    cirque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = 0;
    }
    ~cirque()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
            return true;
        return false;
    }

    void enque(int n)
    {
        if (this->isFull())
        {
            printf("Queue Overflow!\n");
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = n;
    }

    void deque()
    {
        if (this->isEmpty())
        {
            printf("Queue Underflow!\n");
            return;
        }
        front = (front + 1) % size;
    }

    int ftnt()
    {
        if (this->isEmpty())
        {
            printf("Queue is Empty!\n");
            return -1;
        }
        return arr[(front + 1) % size];
    }

    void print()
    {
        if (this->isEmpty())
            return;
        for (int i = (front + 1) % size; i < rear; i = (i + 1) % size)
        {
            printf("%d ", arr[i]);
        }
        cout << arr[rear];
    }
};

int
main()
{
    cirque q(5);

    q.enque(11);
    q.enque(11);
    q.enque(11);
    q.enque(11);
    q.enque(11);
    q.enque(11);

    q.print();

    // q.deque();

    // q.deque();
    // q.enque(123);

    // q.print();

    return 0;
}