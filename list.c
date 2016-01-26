#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	list_t* editor = head;
	list_t* lastword = NULL;
	//If new_element should be first
	if (head->index > new_element->index){
		new_element->next = head;
		return new_element;
	}
	//Find when new_element should be placed
	while((editor->index < new_element->index) && (editor != NULL)){
		lastword = editor;
		editor = editor->next;
	}
	
	lastword->next = new_element;
	new_element->next = editor;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	//Initialize lists
	list_t * a = head;
	list_t * b = NULL;
	list_t * c = NULL;
	while (a != NULL) {
		c = a->next;		//Hold location of next list
		a->next=b;		//Change the next
		b = a;			//Move location of previous location (next branch)
		a = c;			//move a to old next
	}
	return b;
}
