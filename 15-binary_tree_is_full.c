#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* A leaf node is a full tree */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If both left and right subtrees are not null, check recursively */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/*
	 * If one of the subtrees is null and the
	 * other is not, it's not a full tree
	 */
	return (0);
}
