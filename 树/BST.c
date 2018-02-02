/* 二叉搜索树 */
/* 1、二叉搜索树的查找操作Find（尾递归法） */
Position Find(ElementType X,BinTree BST){
	if(!BST){
		return NULL;                     //查找失败
	}
	if(X>BST->Data){                     
		return Find(X,BST->Right);       //在右子树中继续查找
	}
	else if(X<BST->Data){
		return Find(X,BST->Left);        //在左子树中继续查找
	else                                 //X == BST->Data
		return BST;                      //查找成功，返回结点的找到结点的地址
	}  
}

/*2、二叉搜索树的查找操作ItemFind（迭代法） */
/* 非递归函数的执行效率高，查找效率取决于树的高度 */
Position itemFind(ElementType X,BinTree BST){
	while(BST){
		if(X>BST->Data){
			BST = BST->Right;  //向右子树中移动，继续查找
		}
		else if(X<BST->Data){
			BST = BST->Left;   //向左子树移动，继续查找
		}
		else{                  //X == BST->Data
			return BST;        //查找成功，返回结点的找到结点的地址
		}
		return NULL;           //查找失败
	}
}

/* 3、查找最大元素和最小元素 */
Position FindMax(BinTree BST){
	if(BST){
		while(BST->Right){
			BST = BST->Right;      //沿右分支继续查找，直到最右叶节点
		}
		return BST;
	}
}

Position FindMin(BinTree BST){
	if(BST){
		while(BST->Left){
			BST = BST->Left;      //沿左分支继续查找，直到最左叶节点
		}
		return BST;
	}
}













