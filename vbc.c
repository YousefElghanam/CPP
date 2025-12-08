#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

//...

// expr:	term ( "+" term )
// term:	factor ( "*" factor )
// factor:	NUMBER | "(" expr ")"

node    *parse_expr(char **s);
node	*parse_term(char **s);

node	*parse_factor(char **s)
{
	node *ret;
	node tmp;

	ret = NULL;
	if (isdigit(**s))
	{
		tmp.l = NULL;
		tmp.r = NULL;
		tmp.type = VAL;
		tmp.val = **s - '0';
        (*s)++;
		return(new_node(tmp));
	}
	else if (expect(s, '('))
	{
		ret = parse_expr(s);
		if (!expect(s, ')'))
			return (destroy_tree(ret), NULL);
        return (ret);
	}
    else if (**s == ')')
    {
        return (printf("Unexpected token ')'\n"), NULL);
    }
	return (ret);
}

node	*parse_term(char **s)
{
	node *left = parse_factor(s);
	if (!left)
		return (NULL);
	node tmp;

	while (accept(s, '*'))
	{
		tmp.l = left;
		tmp.r = parse_term(s);
		if (!tmp.r)
			return (destroy_tree(left), NULL);
		tmp.type = MULTI;
		// tmp.val = 1;
		return(new_node(tmp));
	}
	return (left);
}

// (2 + 3) * 5

node    *parse_expr(char **s)
{
	node *left = parse_term(s);
	if (!left)
		return (NULL);
	node tmp;

	while (accept(s, '+'))
	{
		tmp.l = left;
		tmp.r = parse_expr(s);
		if (!tmp.r)
			return (destroy_tree(left), NULL);
		tmp.type = ADD;
		// tmp.val = 0;
		return (new_node(tmp));
	}
    return (left);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(&argv[1]);
    if (*argv[1])
        return (printf("Unexpected token#2\n"), destroy_tree(tree), 1);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}