/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:08 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 14:57:36 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "prototypes_push_swap.h"
#include "checker.h"

void	fn_error_exit(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	fn_execute_cmd(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		fn_error_exit("Error\n");
}

int	main(int argc, char **argv)
{
	char	*line;

	t_node	*stack_a;
	t_node	*stack_b;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a);
	ft_print_stack(stack_a, "A\n");

	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		fn_execute_cmd(line, &stack_a, &stack_b);
		ft_printf("\n");
		ft_print_stack(stack_a, "A");
		line = ft_get_next_line(STDIN_FILENO);
	}
	return (0);
}
