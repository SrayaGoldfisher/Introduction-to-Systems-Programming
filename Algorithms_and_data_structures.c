#include <math.h>
#include <stdio.h>
#include <stdlib.h>


//Insertion sort
void insertion (int arr[], int size) {
	int i, j, tmp;
	for (i = 1; i < size; i++) {
		j = i - 1;
		tmp = arr[i];
		while (j >= 0) {
			if (arr[j] > tmp) {
				arr[j + 1] = arr[j];
				j--;
			}
			else {
				break;
			}
		}
		arr[j + 1] = tmp;
	}
}

//Remove all value entries from the list
void pop_val_from_list (list **l, int val) {
/*	list *it = *l, *del;
	while (it) {
		if (it->val == val) {
			del = it;
			free(del);
			it->next = it->next->next;
		}
	}*/
}

//Reverse stack using a stack tmp
void reverse_stack (stack *s) {
	stack tmp;
	new_stack(&tmp, s->size);
	while (!is_empty_stack(*s)) {
		push_stack(&tmp, top_stack(*s));
		pop_stack(s);
	}
	free_stack(s);
	*s = tmp;
}

//Entering a value in a sorted queue
void push_to_sort_queue (queue *q, int val) {
	int tmp1, i = 0;
	if (is_full_queue(*q)) {
		return;
	}
	while ((val >= top_queue(*q)) && (i < count_queue_vals(*q)) && !is_empty_queue(*q)) {
		tmp1 = top_queue(*q);
		pop_queue(q);
		push_queue(q, tmp1);
		i++;
	}
	push_queue(q, val);
	tmp1 = top_queue(*q);
	while (i < count_queue_vals(*q)) {
		if (tmp1 > top_queue(*q)) {
			pop_queue(q);
			push_queue(q, tmp1);
			tmp1 = top_queue(*q);
		}
		i++;
	}
}

//Checking equality between trees
int is_equal_trees (tree *t1, tree *t2) {
	if (!t1 && !t2) {
		return 1;
	}
	if ((t1 && !t2) || (!t1 && t2)) {
		return 0;
	}
	return ((is_equal_trees(t1->left, t2->left)) && (is_equal_trees(t1->right, t2->right)) && (t1->val == t2->val));
}