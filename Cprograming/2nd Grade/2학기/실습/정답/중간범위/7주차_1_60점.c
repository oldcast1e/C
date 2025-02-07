#include<stdio.h>

#include<stdlib.h>

struct node{

	int key;

	struct node *parent;

	struct node *lChild;

	struct node *rChild;

};



int isExternal(struct node *w) {

	if ((w->lChild == NULL) && (w->rChild == NULL)) {

		return 1;

	}

	else {

		return 0;

	}

}



int isInternal(struct node *w) {

	if ((w->lChild != NULL) && (w->rChild != NULL)) {

		return 1;

	}

	else {

		return 0;

	}

}



struct node* sibling(struct node *w) {

	if (w->parent == NULL) {

		return;

	}

	if (w->parent->lChild == w) {

		return w->parent->rChild;

	}

	else {

		return w->parent->lChild;

	}

}



struct node* inOrderSucc(struct node *w) {

	w = w->rChild;

	if (isExternal(w)) {

		return;

	}

	while (isInternal(w->lChild)) {

		w = w->lChild;

	}

	return w;

}



void reduceExternal(struct node *root, struct node *z) {

	struct node *w, *zs, *g;

	w = z->parent;

	zs = sibling(z);

	if (w->parent == NULL) {

		root->lChild = zs->lChild;

		root->rChild = zs->rChild;

		root->lChild->parent = zs;

		root->rChild->parent = zs;

		zs->parent = NULL;

	}

	else {

		g = w->parent;

		zs->parent = g;

		if (w == g->lChild) {

			g->lChild = zs;

		}

		else if (w == g->rChild) {

			g->rChild = zs;

		}

	}

	free(z);

	free(w);

	return zs;

}



struct node* treeSearch(struct node *w, int k) {

	if (isExternal(w)) {

		return w;

	}

	if (w->key == k) {

		return w;

	}

	else if (w->key > k) {

		return treeSearch(w->lChild, k);

	}

	else {

		return treeSearch(w->rChild, k);

	}

}



void insertItem(struct node *w, int k) {

	struct node *lChildNode = (struct node*)malloc(sizeof(struct node));

	struct node *rightChildNode = (struct node*)malloc(sizeof(struct node));

	struct node *p = treeSearch(w, k);

	p->key = k;

	p->lChild = lChildNode;

	p->rChild = rightChildNode;

	lChildNode->parent = p;

	rightChildNode->parent = p;

	lChildNode->lChild = NULL;

	lChildNode->rChild = NULL;

	rightChildNode->lChild = NULL;

	rightChildNode->rChild = NULL;

}



int removeElement(struct node *w, int k) {

	struct node *p = treeSearch(w, k);

	struct node *z, *y;

	int e;

	if (isExternal(p))

		return -1;

	e = p->key;

	z = p->lChild;

	if (!isExternal(z))

		z = p->rChild;

	if (isExternal(z))

		reduceExternal(p, z);

	else {

		y = inOrderSucc(p);

		z = y->lChild;

		p->key = y->key;

		reduceExternal(p,z);

	}

	return e;

}



void printTree(struct node *w) {

	if (isExternal(w)) {

		return;

	}

	else {

		printf(" %d", w->key);

		printTree(w->lChild);

		printTree(w->rChild);

	}

}



void freeTree(struct node *w) {

	if (isExternal(w)) {

		return;

	}

	else {

		freeTree(w->lChild);

		freeTree(w->rChild);

		free(w);

	}

}



void main() {

	char text;

	int key, value;

	struct node *w = (struct node*)malloc(sizeof(struct node));

	w->parent = NULL;

	w->lChild = NULL;

	w->rChild = NULL;

	while (1) {

		scanf("%c", &text);

		if (text == 'i') {

			scanf("%d", &key);

			insertItem(w, key);

			getchar();

		}

		else if (text == 'd') {

			scanf("%d", &key);

			value = removeElement(w, key);

			if (value == -1) {

				printf("X\n");

			}

			else {

				printf("%d\n", value);

			}

			getchar();

		}

		else if (text == 's') {

			scanf("%d", &key);

			if (treeSearch(w, key)->key != key) {

				printf("X\n");

			}

			else {

				printf("%d\n", treeSearch(w, key)->key);

			}

			getchar();

		}

		else if (text == 'p') {

			printTree(w);

			printf("\n");

		}

		else if (text == 'q') {

			break;

		}

	}

	freeTree(w);

}