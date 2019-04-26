 #include<malloc.h> 


typedef struct{
    int front;
    int rear;
    int *base;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue myCircularQueue = {0,0,(int *)malloc(k*sizeof(int))};
    (myCircularQueue).base=(int *)malloc(k*sizeof(int));
    (myCircularQueue).front = (myCircularQueue).rear = 0;
    return &myCircularQueue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
        if(((*obj).rear+1)%1000 == (*obj).front){
            return false;
        };
    
        (*obj).base[(*obj).rear]=value;
        (*obj).rear=((*obj).rear+1)%1000;
        return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if((*obj).front == (*obj).rear){
        // 队列为空
        return false;
    }
    (*obj).front = ((*obj).front+1)%1000;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    // 对列为空
    if((*obj).front == (*obj).rear){
        return -1;
    }
    return (*obj).front;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if((*obj).front == (*obj).rear){
        return -1;
    }
    return (*obj).rear;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if((*obj).front == (*obj).rear){
        return true;
    }
    return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(((*obj).rear+1)%1000 == (*obj).front){
        return true;
    };
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    (*obj).front = (*obj).rear = 0;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */
