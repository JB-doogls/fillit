

#include "../includes/fillit.h"

t_tetri	*lst_new_set()
{
	t_tetri *new;
	int i = 0;

	if (!(new = (t_tetri*)malloc(sizeof(t_tetri) * 1)))
		return (NULL);
	new->letter = '0';
	while (i < 8)
		new->shape[i++] = -1;
	new->next = NULL;
	return (new);
}


int 	main()
{
	t_tetri *node;
	t_tetri *head;
	int test_shapes[4][8] = {
		{0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 2, 0, 3, 0},
		{0, 0, 0, 1, 0, 2, 0, 3}, {0, 0, 0, 1, 1, 0, 2, 0}};
	int i = 0;
	int j = 0;

	if (!(node = lst_new_set()))
	{
		printf("Error creating list node #" "%d\n", j);
		return (-1);
	}
	head = node;
	printf("content node #" "%d\n", j);
	while (i < 8)
	{
		node->shape[i] = test_shapes[j][i];
		i++;
	}
	printf("\tnode->shape = {""%d,%d,%d,%d,%d,%d,%d,%d" "}\n", node->shape[0],
	node->shape[1], node->shape[2], node->shape[3], node->shape[4], node->shape[5],
	node->shape[6], node->shape[7]);

	node->letter = 'A' + j;
	printf("\tnode->letter = ""%c\n", node->letter);
	j += 1;
	while (j < 4)
	{
		if (!(node->next = lst_new_set()))
		{
			printf("Error creating list node #" "%d\n", j);
			return (-1);
		}
		node = node->next;
		i = 0;
		printf("\ncontent node #" "%d\n", j);
		while (i < 8)
		{
			node->shape[i] = test_shapes[j][i];
			i++;
		}
		printf("\tnode->shape = {""%d,%d,%d,%d,%d,%d,%d,%d" "}\n", node->shape[0],
		node->shape[1], node->shape[2], node->shape[3], node->shape[4], node->shape[5],
		node->shape[6], node->shape[7]);
		
		node->letter = 'A' + j;
		printf("\tnode->letter = ""%c\n", node->letter);
		j++;
	}
	if (!(head->letter == 'A' + 0))
	{
		printf("incorrect *head\n");
		return (-1);
	}
	printf("\ncheck head node\n");
	printf("\thead->shape = {""%d,%d,%d,%d,%d,%d,%d,%d" "}\n", head->shape[0],
	head->shape[1], head->shape[2], head->shape[3], head->shape[4], head->shape[5],
	head->shape[6], head->shape[7]);
	printf("\thead->letter = ""%c\n", head->letter);
	if ((head->next))
	{
		printf("\t->next(1)->letter = ""%c\n", (head->next)->letter);
		printf("\t->next(2)->letter = ""%c\n", (head->next->next)->letter);
		printf("\t->next(3)->letter = ""%c\n", (head->next->next->next)->letter);
	}
	return (0);
}


// 	if (ft_solving(node) == -1)
// 	{
// 		printf("Error solvation\n");
// 		return (-1);
// 	}





	// xx		0, 0, 0, 1, 1, 0, 1, 1
	// xx
	
	// x		0, 0, 1, 0, 2, 0, 3, 0
	// x
	// x
	// x			
	
	// xxxx		0, 0, 0, 1, 0, 2, 0, 3
	
	// xx		0, 0, 0, 1, 1, 0, 2, 0
	// x
	// x
