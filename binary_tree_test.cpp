#include <stdio.h>
#include <stdlib.h>

struct tree{
	int val;
	tree *leftNode;
	tree *rightNode;
	tree *upNode;
};

void init(tree **l){
	*l=NULL;
}

void insertFt(tree **l, int x){
	tree *n;
	n = ((tree*) malloc (sizeof(tree)));
	n->upNode=NULL;
	n->rightNode=NULL;
	n->leftNode=NULL;
	n->val=x;
	*l=n;
}

void preOrder (tree *l){
	if (l != NULL){
		printf("%d ",l->val);
      	preOrder(l->leftNode);
      	preOrder(l->rightNode);
	}
}

void order (tree *l){		
	if(l !=NULL){
		order(l->leftNode);
      	printf("%d ",l->val);          
      	order(l->rightNode);
	}		
}

void postOrder (tree *l){		
	if(l != NULL) {
      postOrder(l->leftNode);
      postOrder(l->rightNode);
      printf("%d ", l->val);
	}
}

void insert(tree **l, int x){
	while(1){
		if((*l)->upNode!=NULL){
			*l=(*l)->upNode;
		}else{
			break;
		}
	}	
	tree *n;	
	n = ((tree*) malloc (sizeof(tree)));	
	while(1){
		if(((*l)->val>x)&&((*l)->leftNode==NULL)){
			(*l)->leftNode=n;
			break;
		}else if(((*l)->val<x)&&((*l)->rightNode==NULL)){
			(*l)->rightNode=n;
			break;
		}else if((*l)->val>x){
			*l=(*l)->leftNode;
		}else if((*l)->val<x){
			*l=(*l)->rightNode;
		}
	}	
	n->upNode = *l;
	n->rightNode=NULL;
	n->leftNode=NULL;
	n->val=x;
	*l=n;
}

void del(tree **l, int x){
	tree *n;
	int flag=0;
	
	if(((*l)->upNode==NULL)&&((*l)->rightNode==NULL)&&((*l)->leftNode==NULL)){
		free(*l);
		*l = NULL;
	}else if(((*l)->rightNode==NULL)&&((*l)->leftNode==NULL)){
		if((*l)->upNode->rightNode!=NULL){
			if((*l)->upNode->rightNode->val==(*l)->val){
				(*l)->upNode->rightNode=NULL;
			}
		}else if((*l)->upNode->leftNode!=NULL){
			if(((*l)->upNode->leftNode->val)==((*l)->val)){
				(*l)->upNode->leftNode=NULL;			
			}
		}		
		n = (*l)->upNode;
		free(*l);
		*l=n;
	}else if(((*l)->rightNode!=NULL)||((*l)->leftNode!=NULL)){
		if((*l)->rightNode!=NULL){
			n=(*l)->rightNode;
			
			while(1){
				if(n->leftNode!=NULL){
					n=n->leftNode;
					flag=1;
				}else{
					break;
				}	
			}
			(*l)->val=n->val;
				if(flag==1){
					n->upNode->leftNode=n->rightNode;
					if(n->rightNode!=NULL){					
						n->rightNode->upNode=n->upNode;
					}
					flag=0;			
				}else{
					(*l)->rightNode=n->rightNode;
					if(n->rightNode!=NULL){
						n->rightNode->upNode=*l;
					}
				}					
		}else{
			n=(*l)->leftNode;
			
			while(1){
				if(n->rightNode!=NULL){
					n=n->rightNode;
					flag=1;
				}else{
					break;
				}	
			}
			(*l)->val=n->val;
				if(flag==1){
					n->upNode->rightNode=n->leftNode;
					if(n->leftNode!=NULL){
						n->leftNode->upNode=n->upNode;
					}
					flag=0;			
				}else{
					(*l)->leftNode=n->leftNode;
					if(n->leftNode!=NULL){
						n->leftNode->upNode=*l;
					}
				}	
		}
		free(n);
	}
}

int depth(tree *l){
int depthLeft=0;
int depthRight=0;

if(l==NULL){
	return-1;
}else{
	if(l->leftNode!=NULL){
		depthLeft = depth (l->leftNode);
	}
	if(l->rightNode!=NULL){
		depthRight = depth (l->rightNode);
	}	
    
	if (depthLeft>depthRight){
    	return depthLeft+1;
	} 
    else{
    	return depthRight+1;
	} 
}
}

main(){
	struct tree *tree;
	int x;
	int opt;
	int root;	
	init(&tree);
	
	while(1){
		system("cls");
		if(tree!=NULL){
		printf("Current value: %d \n=================\n", tree->val);
		}else{
			printf("The tree is empty!\n=================\n");
		}
		printf("Choose one option:"
			   "\n=================="
				"\n1-Insert"
				"\n2-Right"
				"\n3-Left"
				"\n4-Up"
				"\n5-Delete"
				"\n6-Max. Depth"
				"\n7-Pre Order"
				"\n8-In Order"
				"\n9-Post Ordem"
				"\n10-Exit"
				"\nOption: ");
		scanf("%d", &opt);
		if((opt==1)&&(tree==NULL)){
			system("cls");
			printf("Insert the root value: ");
			scanf("%d", &x);
			root=x;
			insertFt(&tree, x);
		}else if((opt==1)&&(tree!=NULL)){
			system("cls");
			printf("Insert a value: ");
			scanf("%d", &x);
			insert(&tree, x);
		}else if((opt==2)&&(tree!=NULL)&&(tree->rightNode!=NULL)){
			tree=tree->rightNode;
		}else if((opt==3)&&(tree!=NULL)&&(tree->leftNode!=NULL)){
			tree=tree->leftNode;
		}else if((opt==4)&&(tree!=NULL)&&(tree->upNode!=NULL)){
			tree=tree->upNode;
		}else if((opt==5)&&(tree!=NULL)){
			del(&tree, root);
		}else if((opt==6)&&(tree!=NULL)){
			while(1){
				if (tree->upNode!=NULL){
					tree=tree->upNode;
				}else{
					break;
				}
			}
				system("cls");				
				printf("The tree Max. Depth is: %d\n\n", depth(tree)-1);
				system("pause");
		}else if((opt==7)&&(tree!=NULL)){
			while(1){
				if (tree->upNode!=NULL){
					tree=tree->upNode;
				}else{
					break;
				}
			}
			system("cls");
			printf("Pre order tree: ");
			preOrder(tree);
			printf("\n");
			system("pause");
		}else if((opt==8)&&(tree!=NULL)){
			while(1){
				if (tree->upNode!=NULL){
					tree=tree->upNode;
				}else{
					break;
				}
			}
				system("cls");
				printf("In order tree: ");
				order(tree);
				printf("\n\n");
				system("pause");
		}else if((opt==9)&&(tree!=NULL)){
			while(1){
				if (tree->upNode!=NULL){
					tree=tree->upNode;
				}else{
					break;
				}
			}
				system("cls");
				printf("Post order tree: ");
				postOrder(tree);
				printf("\n\n");
				system("pause");
		}else if(opt==10){
			return 0;
		}
	
	}
}
