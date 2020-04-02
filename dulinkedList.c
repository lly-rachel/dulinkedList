#include "dulinkedList.h"
#define NULL 0

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {

	L = (DuLinkedList*)malloc(sizeof(DuLNode));
	if ((*L) == NULL) return ERROR;
	return SUCCESS;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {

	DuLinkedList p = NULL;
	while (*L) {
		p = (*L)->next;
		free(*L);
		*L = p;
	}

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {

	if (p == NULL || q == NULL) return ERROR;

	if (p->prior == NULL) {
		p->prior = q;
		q->next = p;
		q->prior = NULL;
	}
	else {
		p->prior->next = q;
		q->prior = p->prior;
		p->prior = q;
		q->next = p;		
	}
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {

	if (p == NULL || q == NULL) return ERROR;

	if (p->next == NULL) {
		p->next = q;
		q->prior = p;
		q->next = NULL;
	}
	else {
		p->next->prior = q;
		q->next = p->next;
		p->next = q;
		q->prior = p;
	}
	return SUCCESS;

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {

	if (p->next == NULL) return ERROR;
	DuLNode* after = p->next;

	*e = after->data;
	if (after->next == NULL) {
		p->next = NULL;
		return SUCCESS;
	}
	after->next->prior = p;
	p->next = after->next;

	free(after);
	return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {

	if (L == NULL) printf("List is null\n");
	DuLNode* p;
	p = L;
	while (p) {
		visit(p->data);
		p = p->next;
	}

}
