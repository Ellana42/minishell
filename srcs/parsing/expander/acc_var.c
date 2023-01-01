#include "expander.h"

int	expander_is_empty_acc_var(t_expander *expander)
{
	return (acc_is_empty(expander->acc_var));
}

void	expander_reset_acc_var(t_expander *expander)
{
	acc_reset(expander->acc_var);
}

int	expander_accumulate_var(t_expander *expander)
{
	acc_accumulate(expander->acc_var, *(expander->cmd_ptr));
	expander_move_cursor(expander);
	return (0);
}
