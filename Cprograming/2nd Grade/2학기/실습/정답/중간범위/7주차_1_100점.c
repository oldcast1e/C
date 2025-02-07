#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
	struct Node* lchild;
	struct Node* rchild;
	struct Node* parent;
	int key
}node;


node * treeSearch(node * root, int k);
node * sibling(node* root, node *w);
node * inOrderSucc(node *p);
void getnode(node **p);
void reduceExternal(node **root, node *z);
void removeElement(node **root, int k);
void insertkey(node* root, int k);
void findElement(node* root, int k);
void print(node *root);

int isExternal(node * p);
void expandExternal(node*p);



int main()
{
	int * root;
	getnode(&root);
	int key;
	char order;

	while (1)
	{
		scanf("%c", &order);
		if (order == 'i') {
			scanf("%d", &key);
			getchar();
			insertkey(root, key);
		}
		else if (order == 'd') {
			scanf("%d", &key);
			getchar();
			removeElement(&root, key);
		}
		else if (order == 's') {
			scanf("%d", &key);
			getchar();
			findElement(root, key);
		}
		else if (order == 'p') {
			print(root);
			printf("\n");
		}
		else if (order == 'q')
			return;
	}
}

void getnode(node **p) {
	(*p) = (node*)malloc(sizeof(node));
	(*p)->lchild = NULL;
	(*p)->rchild = NULL;
	(*p)->parent = NULL;
}
void expandExternal(node*p) {
	node *lc, *rc;
	getnode(&lc);
	getnode(&rc);
	p->lchild = lc;
	p->rchild = rc;
	lc->parent = p;
	rc->parent = p;
}
void reduceExternal(node **root, node *z) {
	node *ext = z->parent;
	node *zs = sibling(*root, z);
	if (ext == *root) {
		zs->parent = NULL;
		*root = zs;
	}
	else {
		node *g = ext->parent;
		zs->parent = g;
		if (g->lchild == ext) g->lchild = zs;
		else g->rchild = zs;
	}
	free(z); free(ext);
}
void removeElement(node **root, int k) {
	node * ext = treeSearch(*root, k);
	if (isExternal(ext) == 1) {
		printf("X\n");
		return;
	}

	node *z = ext->lchild;
	if (isExternal(z) == 0)z = ext->rchild;
	if (isExternal(z) == 1) reduceExternal(root, z);
	else {
		node * y = inOrderSucc(ext);
		z = y->lchild;
		ext->key = y->key;
		reduceExternal(root, z);
	}
	printf("%d\n", k);
}
void findElement(node* root, int k) {
	node* ext = treeSearch(root, k);
	if (isExternal(ext) == 0) printf("%d\n", k);
	else printf("X\n");
}
void print(node *root) {
	if (isExternal(root) == 1) return;
	printf(" %d", root->key);
	print(root->lchild);
	print(root->rchild);
}

node * treeSearch(node * root, int k) {
	if (isExternal(root) == 1) return root;
	if (root->key == k) return root;
	else if (root->key > k) return treeSearch(root->lchild, k);
	else return treeSearch(root->rchild, k);
}

node * sibling(node* root, node *ext) {
	if (root == ext) return root;
	else if (ext->parent->lchild == ext) return ext->parent->rchild;
	else return ext->parent->lchild;
}
node * inOrderSucc(node *p) {
	node *ext = p->rchild;
	if (isExternal(ext) == 1) return ext;
	while (isExternal(ext->lchild) == 0) ext = ext->lchild;
	return ext;
}

int isExternal(node * p) {
	if (p->lchild == NULL && p->rchild == NULL)
		return 1;
	else return 0;
}

void insertkey(node* root, int k) {
	node *ext = treeSearch(root, k);
	if (isExternal(ext) == 0) return;
	ext->key = k;
	expandExternal(ext);
}