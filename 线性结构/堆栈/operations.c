/* 栈的顺序存储实现
栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成。 */
/* 初始化 */
#define MAXSIZE
typedef struct SNode* Stack;
struct SNode{
	ElementType Data[MAXSIZE];
	int Top;
};

/* -------------------------------------------------------------------------------------------------------------- */

/* 1、入栈 */
void Push(Stack PtrS,ElementType item){
	if(PtrS->Top == MAXSIZE-1){
		printf("堆栈满");
		return;
	}else{
		PtrS->Data[++(PtrS->Top)] = item;   //这一步操作可以分解为两步：(PtrS->Top)++; PtrS->Data[PtrS->Top]=item;
		return;
	}
}

/* -------------------------------------------------------------------------------------------------------------- */

/* 2、出栈 */
ElementType Pop(Stack PtrS){
	if(PtrS->Top == -1){
		printf("堆栈空");
		return ERROR;         //ERROR是ElementType的特殊值，标志错误
	}else{
		return (PtrS->Data[(PtrS->Top)--]);
	}
}

/* -------------------------------------------------------------------------------------------------------------- */

/* 用一个数组实现两个堆栈，要求最大地利用数组空间，使数组只要有空间入栈操作就可以成功。
分析：使这两个栈分别从数组的两头开始向中间生长，当两个栈的栈顶指针相遇时，表示两个栈都满了 */
/* 初始化 */
#define MAXSIZE
struct DStack{
	ElementType Data[MAXSIZE];
	int Top1;                   //堆栈1的栈顶指针
	int Top2;                   //堆栈2的栈顶指针
}S;

/* 判断堆栈为空 */
S.Top1 = -1;
S.Top2 = MAXSIZE;

/* -------------------------------------------------------------------------------------------------------------- */

/* 1、入栈 */
void DPush(struct DStack* PtrS,ElementType item,int Tag){  //Tag作为区分两个堆栈的标志，取值为1和2
	if(PtrS->Top2 - PtrS->Top1 == 1){     //堆栈满
	printf("堆栈满");
	return;		
	}
	if(Tag == 1){
		PtrS->Data[++(PtrS->Top1)] = item;
	}else{
		PtrS->Data[--(PtrS->Top2)] = item;
	}
}

/* -------------------------------------------------------------------------------------------------------------- */

/* 2、出栈 */
void DPop(struct DStack* PtrS,int Tag){          //Tag作为区分两个堆栈的标志，取值为1和2
	if(Tag == 1){
		if(PtrS->Top1 == -1){                    //堆栈1空
			printf("堆栈1空")；
			return NULL；
		}else{
			return PtrS->Data[(PtrS->Top1)--];
		}else{
			if(PtrS->Top2 == MAXSIZE){           //堆栈2空
				printf("堆栈2空");
				return NULL;
			}else{
				return PtrS->Data[(PtrS->Top2)++];
			}
				
		}
	}
}

/* -------------------------------------------------------------------------------------------------------------- */

/* 堆栈的链式存储实现
栈的链式存储结构实际上就是一个单链表，叫做链栈。插入和删除操作只能在链栈的栈顶进行。栈顶指针Top只能在链表的头部，不能再尾部 */
/* 初始化 */
typedef struct LSNode* LStack
struct LSNode{
	ElementType Data;
	struct SLNode* Next;	
};

LStack CreateStack(){      //构建一个堆栈的头结点，返回指针。注：此头结点不代表任何一个元素，只是为了能够通过使用该头结点能够方便操作堆栈。
	LStack S;
	S = (LStack)malloc(sizeof(struct LSNode));
	S->Next = NULL;
	return S;
}

/* 判断堆栈为空 */
int IsEmpty(Stack S){          //判断堆栈S是否为空，若为空函数返回整数1，否则返回0
	return (S->Next == NULL);
}

/* -------------------------------------------------------------------------------------------------------------- */

/* 1、入栈 */
void Push(ElementType item,LStack S){
	struct LSNode* TmpCell;
	TmpCell = (struct LSNode*)malloc(sizeof(struct LSNode));
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
    return;
}

/* -------------------------------------------------------------------------------------------------------------- */

ElementType Pop(LStack S){
	struct SLNode* FirstCell;          //删除并返回堆栈S的栈顶元素
	ElementType TopElem;
	if(IsEmpty(s)){
		printf("堆栈空");
		return NULL;
	}else{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		TopElem = FirstCell->Data;
		free(FirstCell);
		return TopElem;
	}
}




















