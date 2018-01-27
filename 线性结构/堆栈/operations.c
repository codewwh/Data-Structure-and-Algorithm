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