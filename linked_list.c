#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct node_c
{
	char c;
	node_c *next;
};

struct node_i
{
	int i;
	node_i *next;
};

struct node_f
{
	float f;
	node_f *next;
};

struct node_d
{
	double d;
	node_d *next;
};

int push_back_c(node_c **head, char value)
{
	//Goes to last node
	for(node_c *curr = head; curr != NULL; curr = curr->next);
	node_c *new_node;
	if(new_node = (node_c*)malloc(sizeof(*node_c)) == NULL)
	{
		perror("Couldn't allocate.");
		free(new_node);
		return -1;
	}
	curr->next = new_node;
	new_node->c = value;
	new_node->next = NULL;
	return 1;
}

int push_front_c(node_c **head, char value)
{
	node_c *new_node;
	if(new_node= (node*)malloc(sizeof(*new_node)) == NULL)
	{
		perror("Couldn't allocate.");
		free(new_node);
		return -1;
	}
	new_node->next = head;
	new_node->c = value;
	return 1;
}

void remove_node(node **nd)
{
	for(node *curr = nd; curr != nd; curr = curr->next);
	curr->next = nd->next;
	nd->next = NULL;
	free(nd);
}
