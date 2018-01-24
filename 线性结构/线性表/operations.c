/*线性表顺序存储的实现
利用数组的连读空间顺序存放线性表的各元素
*/
//定义结构体
typedef struct LNode* List;
struct LNode{
	ElementType Data[MAXSIZE];//使用过程中用“elemtype”代表所有可能的数据类型，简单明了的概括了整体。在算法中，除特别说明外，规定ElemType的默认是int型。
	int Last;
};
struct LNode L;
List PtrL;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*1、初始化（建立空的顺序表）*/
List MakeEmpty(){
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;//因为Last代表最后一个元素，Last为0代表表里有一个元素放在第一个位置，没元素则为-1
	return PtrL;
};

/* -----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* 2、查找 */
int Find(ElementType X,List PtrL){
	int i = 0;
	while(i <= PtrL->Last && PtrL->Data[i]!= X){
	i++;}
	if(i>PtrL->Last){
	return -1;//如果没找到返回-1
	}
	else return i;//找到后返回的是存储位置
    
}

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 3、插入（第i(1<=i<=n+1)个位置上插入一个值为X的新元素） */
void Insert(ElementType X,int i,List PtrL){
	int j;
	if(PtrL->Last == MAXSIZE-1){  //表空间已满，不能插入
		printf("表满");
		return；
	}
	if(i < 1 || i > PtrL->Last + 2){ //检查插入位置合法性
		printf("位置不合法");
		return;		
	}
	for(j = PtrL->Last;j >= i-1;j--){
		PtrL->Data[j+1] = PtrL->Data[j]; //将ai~an倒序向后移动
	}
	PtrL->Data[i-1] = X;             //新元素插入
	PtrL->Last++;                    //Last仍指向最后元素
	return;
	
}

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 4、删除（删除表的第i(1<=i<=n)个位置上的元素） */
void Delete(int i,List PtrL){
     int j;
	 if(i < 1 || i > PtrL->Last + 1){
		printf("不存在第%d个元素",i)； //检查空表及删除位置的合法性
		return；
	 }
	 for(j = i;j <= PtrL->Last;j++){
		PtrL->Data[j-1] = PtrL->Data[j]; //将ai+1~an顺序向前移动
	 }
	 PtrL->Last--;                       //Last仍指向最后元素
	 return;
}


















