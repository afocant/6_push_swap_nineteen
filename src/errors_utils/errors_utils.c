#include "push_swap.h"

void	ft_print_error(char *str)
{
	ssize_t	len;
	char	nl;

	len = ft_strlen(str);
	nl = '\n';
	if (write(2, str, len) != len)
		printf("Error writing on stderr");
	if (write(2, &nl, 1) != 1)
		printf("Error writing on stderr");

}

void	ft_error_and_exit(char *msg, int nb_error)
{
	ft_print_error(msg);
	exit(nb_error);
}

int		ft_is_str_nbr(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_non_integers(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_is_str_nbr(argv[i]))
			ft_error_and_exit("Arg is not a number", 2);
		if (ft_atol(argv[i]) > (long) INT_MAX)
			ft_error_and_exit("Arg is too big to be an int", 3);
		if (ft_atol(argv[i]) < (long) INT_MIN)
			ft_error_and_exit("Arg is too small to be an int", 4);
		i++;
	}
	return (1);
}

void	ft_check_arg_errors(int argc, char **argv)
{
	if (argc < 2)
		ft_error_and_exit("Not enough arguments", 1);

	// if just one digit, it is sorted already
	// otherwise if a string
	// split the string

	ft_check_non_integers(argv);
	//ft_check_duplicates(argv);
}
