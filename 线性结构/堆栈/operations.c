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



























