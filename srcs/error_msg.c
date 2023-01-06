#include "error.h"

int	error_msg3(char *msg, int err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (err);
}

int	error_msg(char *cmd, char *issue, int err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(issue, 2);
	ft_putstr_fd("\n", 2);
	return (err);
}

int	error_msg2(char *cmd, char *cmd2, char *issue, int err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd2, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(issue, 2);
	ft_putstr_fd("\n", 2);
	return (err);
}
