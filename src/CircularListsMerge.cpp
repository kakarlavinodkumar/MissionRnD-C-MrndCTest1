/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
void convert_to_single_list(struct node **head)
{ 
	struct node *temp;
	int count = 0;
	for (temp = *head; temp->next != *head;)
	{
		count++;
		temp = temp->next;
	}
	temp->next = NULL;
	//return count;
}
void merge(struct node *start1, struct node *start2,struct node **head1)
{
	struct node *res_start=NULL,*temp1,*temp2,*newnode,*current=NULL;
	for (temp1 = start1, temp2 = start2; temp1 != NULL&&temp2 != NULL;)
	{
		if (temp1->data < temp2->data)
		{
			newnode = temp1;
			temp1 = temp1->next;
		}
		else
		{
			newnode = temp2;
			temp2 = temp2->next;
		}
		if (res_start == NULL)
			res_start = newnode;
		else
			current->next = newnode;
		current = newnode;
	}
	if (temp1 == NULL)
		current->next = temp2;
	else
		current->next = temp1;
	for (; current->next != NULL;)
		current = current->next;
	current->next = *head1;
	//return res_start;
}
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	struct node *temp1, *temp2,*temp;
	int count;
	if (head1==NULL||head2==NULL)
	return -1;
	for (count = 1, temp = *head1; temp->next != *head1; temp = temp->next)
		count++;
	for(temp2=*head2; temp2->next!= *head2; temp2 = temp2->next)
		count++;
	convert_to_single_list(head1);
	convert_to_single_list(head2);
	temp1 = *head1;
	temp2 = *head2;
	if ((*head2)->data < (*head1)->data)
		head1 = head2;
	merge(temp1, temp2, head1);
	return count;

}