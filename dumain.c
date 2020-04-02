#include "DulinkedList.h"
#include <stdio.h>

void visit(ElemType e) {
	printf("-->%d", e);
}


void NewList(DuLinkedList* L) {

	DuLNode* p1 = NULL, * p2 = NULL;
	p1 = (DuLNode*)malloc(sizeof(DuLNode));
	p1->prior = NULL;
	*L = p1;
	if (p1 == NULL) return ERROR;
	else {
		printf("\nenter number(end at 0)[eg:8 9 100 0]：");
		while (1) {
			scanf("%d", &p1->data);
			if (p1->data == 0) break;
			p2 = p1;
			p1 = (DuLNode*)malloc(sizeof(DuLNode));
			p1->prior = p2;
			p2->next = p1;
		}
		p2->next = NULL;
		free(p1);
	}
}

int main() {
	int choice, i;
	DuLinkedList L = NULL;
	DuLNode* p = NULL, * q = NULL;
	ElemType e = 0;
	int count=0;

	printf("\n\t********************MENU********************\n");
	printf("\t\t1--Initialize Dulinked list\n");
	printf("\t\t2--Destroy\n");
	printf("\t\t3--Delete\n");
	printf("\t\t4--InsertAfterList\n");
	printf("\t\t5--InsertBeforeList\n");
	printf("\t\t6--TravelList\n");
	printf("\t\t7--Exit\n");
	printf("\t********************************************\n");

loop:

	printf("\nYour choice:");
	scanf("%d", &choice);

	switch (choice) {
	case 1:

		if (InitList_DuL(&L)) {
			printf("success\n");
		}
		else {
			printf("failed\n");
		}

		NewList(&L);  //创建数据链表
		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);

		break;

	case 2:

		DestroyList_DuL(&L);
		printf("List already destoryed\n");
		break;

	case 3:

		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);

		DuLNode* p = L;
		int select;
		for (count = 0;p;count++) {
			p = p->next;
		}

		printf("\nenter which node after this node you want to delete(1-%d):\n",count-1);
		scanf("%d", &select);
		p = L;
		for (int i=1; i<select; i++) {
			p = p->next;
		}

		DeleteList_DuL(p, &e);
		printf("\n-->%d\n", e);

		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);

		break;

	case 4:

		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);

		for (count = 0,p=L; p; count++) {
			p = p->next;
		}

		printf("\nenter which node after this node you want to insert(1-%d):\n", count);
		scanf("%d", &select);
		if (select <= 0 || select > count) {
			printf("data error\n");
			break;
		}

		p = L;
		for (int i = 1; i < select; i++) {
			p = p->next;
		}

		q=(DuLNode*)malloc(sizeof(DuLNode));
		printf("enter the data:");
		scanf("%d", &q->data);
		q->prior = NULL;
		q->next = NULL;

		InsertAfterList_DuL(p, q);
		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);
		break;


	case 5:

		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);

		for (count = 0,p=L; p; count++) {
			p = p->next;
		}

		printf("\nenter which node before this node you want to insert(1-%d):\n", count);
		scanf("%d", &select);
		if (select <= 0 || select > count) {
			printf("data error\n");
			break;
		}

		p = L;
		for (int i = 1; i < select; i++) {
			p = p->next;
		}

		q = (DuLNode*)malloc(sizeof(DuLNode));
		printf("enter the data:");
		scanf("%d", &q->data);
		q->prior = NULL;
		q->next = NULL;

		InsertBeforeList_DuL(p, q);
		if(q->prior==NULL) L = q;
		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);
		break;

	case 6:
		printf("\nNow the list is:\n");
		TraverseList_DuL(L, visit);
		break;

	case 7:	return 0;

	default:printf("data error!\n");
	}

	do {
		printf("\ncontinue to use the menu or stop(enter 1 or 0):");
		scanf("%d", &i);
		if (i == 1) goto loop;
		if (i != 1 && i != 0) printf("data error!");
	} while (i != 1 && i != 0);

	return 0;
}