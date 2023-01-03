#include "expander.h"

int	expander_eol(t_expander *expander)
{
	return (!(*(expander->cmd_ptr)));
}
