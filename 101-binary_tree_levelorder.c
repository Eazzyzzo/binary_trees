#include "binary_trees.h"
/**
 * binary_tree_height - To measure the height of a binary tree
 * @tree: tree
 * Return: Height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left > right) ? left : right);
	}
}
/**
 * binary_tree_depth - depth of Particular node from root
 * @tree: tree
 * Return: 0 or depth value
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - makes a linked list from depth level and node
 * @head: pointer to head of linked list
 * @tree: node
 * @level: depth
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *newnode, *temp;

	newnode = malloc(sizeof(link_t));
	if (newnode == NULL)
	{
		return;
	}
	newnode->n = level;
	newnode->node = tree;
	if (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		newnode->next = NULL;
		temp->next = newnode;
	}
}
/**
 * recursion - scans the tree and stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: Nothing
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: root node
 * @func: function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *temp;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			temp = head;
			while (temp != NULL)
			{
				if (count == temp->n)
				{
					func(temp->node->n);
				}
				temp = temp->next;
			}
			count++;
		}
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
	}
}
