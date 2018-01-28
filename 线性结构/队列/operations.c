/* 队列的顺序存储实现
队列的顺序存储结构通常由一个一维数组和一个记录队列头元素位置的变量front以及一个记录队尾元素位置的变量rear */
/* 1、初始化 */
#define MAXSIZE
struct QNode{
	ElementType Data[MAXSIZE];
	int rear;
	int front;
};
typedef struct QNode* Queue;

/* -------------------------------------------------------------------------------------------------------------- */

/* 2、入队列 */
void AddQ(Queue PtrQ,ElementType item){
	if((PtrQ->rear+1)%MAXSIZE == PtrQ->front){
		printf("队列满");
		return;
	}else{
		PtrQ->rear = (PtrQ->rear+1)%MAXSIZE;
		PtrQ->Data[PtrQ->rear] = item;
    }
}
/* -------------------------------------------------------------------------------------------------------------- */

/* 3、出队列 */

ElementType DeleteQ(Queue PtrQ){
	if(PtrQ->front == PtrQ->rear){
		printf("队列空");
		return ERROR;
	}else{
		PtrQ->front = (PtrQ->front+1)%MAXSIZE;
		return PtrQ->Data[PtrQ->front];
	}
}

/* -------------------------------------------------------------------------------------------------------------- */

/* 队列的链式存储实现
队列的链式存储结构也可以用一个单链表实现。插入和删除操作分别在链表的两头进行；队列指针front做删除操作，rear做插入操作。front只能指向链表的头。*/
/* 1、初始化 */
struct Node{
	ElementType Data;
	struct Node* Next;
};
struct QNode{             //链队列结构
	struct Node* rear;    //指向队尾结点
	struct Node* front;   //指向队头结点
};
typedef struct QNode* Queue;
Queue PtrQ;

/* -------------------------------------------------------------------------------------------------------------- */
/* 2、（不带头结点的）链式队列入队操作 */
void AddQ(Queue PtrQ,ElementType item){
	struct Node* p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->Data = item;
	p->Next=NULL;
	if(PtrQ->rear == NULL){   //若队列为空，则新结点时队首结点，也是队尾结点
		PtrQ->front = PtrQ->rear = p;
	}else{
		PtrQ->rear->Next = p;        //将新结点链接到队尾，并用rear指向它
		PtrQ-> = p;
	}
}

/* -------------------------------------------------------------------------------------------------------------- */

/* 3、（不带头结点的）链式队列出队操作 */
ElementType DeleteQ(Queue PtrQ){
	struct Node* FrontCell;          //队列中即将出队的首个元素
	ElementType FrontElem;           //存储队列所出队元素的变量
	
	if(PtrQ->front == NULL){
		printf("队列空")；
		return ERROR;
	}
	FrontCell = PtrQ->front;
	if(PtrQ->front == PtrQ->rear){        //若队列只有一个元素
		PtrQ->front = PtrQ->rear = NULL;  //删除后队列置为空
	}else{
		PtrQ->front = PtrQ->front->Next;
		FrontElem = FrontCell->Data;
		free(FrontCell);                  //释放被删除结点空间
		return FrontElem;
	}
}






















