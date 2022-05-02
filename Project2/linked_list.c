#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* consw_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p1,*p2,*p3,*p4;
		p1 = head1;
		p2 = head2;

		while (p1->link || p2->link != NULL) {
			p3 = p1->link;
			p1->link = p2->link;
			p4 = p2->link;
			p2->link = p3;
			p1 = p1->link;
			p1->link = p4;
		}
		return head1;
	}
}

ListNode* reserse(ListNode* head) {
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;

		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int main() {
	//ListNode* head = NULL;
	//element data;
	//head = insert_first(head, 10);
	//print_list(head);
	//head = insert_first(head, 20);
	//print_list(head);
	//head = insert_first(head, 30);
	//print_list(head);
	//if (search_list(head, 30) != NULL)
	//	printf("리스트에서 30을 찾았습니다. \n");
	//else
	//	printf("리스트에서 30을 찾지 못했습니다. \n");

	//ListNode* head1 = NULL;
	//ListNode* head2 = NULL;
	//head1 = insert_first(head1, 10);
	//head1 = insert_first(head1, 20);
	//head1 = insert_first(head1, 30);
	//print_list(head1);
	//head2 = insert_first(head2, 40);
	//head2 = insert_first(head2, 50);
	//print_list(head2);
	//ListNode* total = concat_list(head1, head2);
	//print_list(total);

	//ListNode* head1 = NULL;
	//ListNode* head2 = NULL;
	//head1 = insert_first(head1, 10);
	//head1 = insert_first(head1, 20);
	//head1 = insert_first(head1, 30);
	//print_list(head1);
	//head2 = reverse(head1);
	//print_list(head2);

	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);
	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);
	ListNode* result = consw_list(head1, head2);
	print_list(result);
	return 0;
}