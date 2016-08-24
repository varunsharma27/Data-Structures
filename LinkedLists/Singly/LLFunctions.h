#ifndef __LLFUNCTIONS_H
#define __LLFUNCTIONS_H

// Return the Mth element from the end of Singly Linked List
struct List{
	struct List *next;
	int data;
};
List *findFromEnd(int m, List * head){
	List *found = NULL, *cursor = head;
	int x = 1;
	while(cursor){
		if(x == m){
			found = head;
		}
		else if (x > m){
			found = found->next;
		}
		x++;
		cursor = cursor->next;
	}
	return found;
}

// Flatten a doubly linked list with multiple levels (childs)

struct Node{
	struct Node *next;
	struct Node *prev;
	struct Node *child;
	int data;
};
Node *flatten(struct Node *head){
	struct Node *cursor, *break_point, *childTail, *prevCursor = NULL;
	cursor = head;
	while(cursor){
		prevCursor = cursor;
		if(cursor->child){
			break_point = cursor->next;
			cursor->next = cursor->child;
			childTail = flatten(cursor->child);
			childTail->next = break_point;
			break_point->prev = childTail;
		}
		cursor = cursor->next;
	}
	return prevCursor; //Tail (whose next is a NULL)
}
