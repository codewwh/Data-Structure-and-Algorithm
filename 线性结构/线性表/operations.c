/*线性表顺序存储的实现（顺序表）
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

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 线性表链式存储的实现（链表）
不要求逻辑上相邻的两个元素物理上也相邻；通过“链”建立起数据元素之间的逻辑关系 */
//定义结构体
typedef struct LNode* List;
struct LNode{
	ElementType Data;
	List Next;
};
struct LNode L;
List PtrL;

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 1、求表长 */
int Length(List PtrL){
	List p = PtrL; //p指向表的第一个结点
	int j = 0;
	while(p){ //循环条件p不等于null
		p = p->Next;
		j++;  //当前p指向的是第j个结点
	}
	return j;
}

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 2、查找 */
//第一种：按序号查找：FindKth
List FindKth(int K, List PtrL){
	List p = PtrL;
	int i = 1;
	while(p != NULL && i < K ){   //循环条件为表不空和一直要找到K
		p = p->Next;
		i++;
	}
	if(i == K){
	return p;     //找到第K个，返回其指针
	}
	else return NULL; //否则返回空
}

//第二种：按值查找：Find
List Find(ElementType X,List PtrL){
	List p = PtrL;  //p指向表的第一个结点
	while(p != NULL && p->Data != X ){  //循环条件为表不空和一直要找到X
		p = p->Next;
	return p;     //找到指定元素则返回其指针，否则返回空
	}
}

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 3、插入（在第i-1（1<=i<=n+1）个结点后插入一个值为X的新结点） */
/* 步骤：（1）先构造一个新结点，用s指向；
         （2）在找到链表的第i-1个结点，用p指向；
	     （3）然后修改指针，插入结点（p之后插入新结点时s） */
List Insert(ElementType X,int i,List PtrL){
	List p,s;
	if(i == 1){                                    //新结点插入在表头
		s = (List)malloc(sizeof(struct LNode));    //申请、填装结点
		s->Data = X;                   
		s->Next = PtrL;
		return s;                                  //此时整个链表头指针也发生了变化，返回新表头指针
	}
	p = FindKth(i-1,PtrL);                         //查找第i-1个结点，用p指向； 
	if(p == NULL){
		printf("参数i错");                         //第i-1个不存在，不能插入
		return NULL;
	}
	else{
		s = (List)malloc(sizeof(struct LNode));    //申请、填装结点
		s->Data = X;
		s->Next = p->Next;                         //新结点插入在第i-1个结点的后面
		p->Next = s;
		return PtrL;
}

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 4、删除（删除链表的第i(1<=i<=n)个位置上的结点）*/
/*步骤：（1）先找到链表的第i-1个结点，用p指向；
	  （2）再用指针s指向要被删除的结点（p的下一个结点）；
	  （3）然后修改指针，删除s所指结点；
	  （4）最后释放s所指结点的空间； */
List Delete(int i,List PtrL){
	List p,s;
	if(i == 1){                   //若要删除的是链表第一个结点
		s = PtrL;                 //s指向第一个结点
		if(PtrL!=NULL){           //PtrL头结点不空，则从链表中删除
		PtrL = PtrL->Next;
		}
		else return NULL;         //PtrL头结点为空，则从链表中删除
		free(s);                  //释放被删除结点
		return PtrL;
	}
	p = FindKth(i-1,PtrL);
	if(p == NULL){                        //若找不到第i-1个结点
		printf("第%d个结点不存在",i-1);
		return NULL;
	}
	else if(p->Next == NULL){             //若找不到第i个结点
		printf("第%d个结点不存在",i);
		return NULL;
	}
	else{
		s = p->Next;                      //s指向第i个结点
		p->Next = s->Next;                //从链表中删除
		free(s);                          //释放被删除结点
		return PtrL;
	}
}







