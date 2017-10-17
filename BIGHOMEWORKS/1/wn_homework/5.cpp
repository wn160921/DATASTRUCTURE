#define QUENU_INIT_SIZE 100
#define QUENUINCREMENT 10
typedef struct
{
    ElemType *queue;
    int front;
    int rear;
    int Count;
    int queuesize;
    int incrementsize;
} SqQueue;

//初始化操作
void InitQueue_Sq(SqQueue &Q,int maxsize=QUENU_INIT_SIZE,int incresize=QUENUINCREMENT)
{
    Q.queue=(ElemType*)malloc(maxsize*sizeof(ElemType));
    if(!Q.queue)
        exit(1);
    Q.front=Q.rear=Q.Count=0;
    Q.queuesize=maxsize;
    Q.incrementsize=incresize;
}

//进队操作
bool EnQueue_Sq(SqQueue &Q,ElemType e)
{
    //从队尾插入元素，成功则返回true
    if(Q.Count==Q.queuesize) //队满给顺序队列增补空间
    {
        cout<<"count="<<Q.Count<<endl;
        Q.queue=(ElemType*)realloc(Q.queue,(Q.queuesize+Q.incrementsize)*sizeof(ElemType));
        if(!Q.queue)
            return false;
        if(Q.front>=Q.rear)   //队首指针在队尾指针后面，重新确定位置
        {
            for(int i=Q.queuesize; i>=Q.front; i--)
            {
                Q.queue[i+Q.incrementsize]=Q.queue[i];
            }
            Q.front+=Q.incrementsize;
        }
        Q.queuesize+=Q.incrementsize;
    }
    Q.queue[Q.rear]=e;
    Q.rear=(Q.rear+1)%Q.queuesize;
    Q.Count++;
    return true;
}

//出队操作
bool DeQueue_Sq(SqQueue &Q,ElemType &e)
{
    if(Q.Count==0)
    {
        return false;
    }
    e=Q.queue[Q.front];
    Q.front=(Q.front+1)%Q.queuesize;
    Q.Count--;
    return true;
}
