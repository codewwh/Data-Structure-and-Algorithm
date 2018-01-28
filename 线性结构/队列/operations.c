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