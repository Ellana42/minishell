#include "exit.h"

int	increment_neg(char next_char, long long *out)
{
	long long	new_digit;

	new_digit = next_char - 48;
	if (*out < LLONG_MIN / 10)
		return (1);
	*out *= 10;
	if (*out < LLONG_MIN + new_digit)
		return (1);
	*out -= new_digit;
	return (0);
}

int	increment(char next_char, long long *out, int sign)
{
	long long	new_digit;

	if (sign < 0)
		return (increment_neg(next_char, out));
	new_digit = next_char - 48;
	if (*out > LLONG_MAX / 10)
		return (1);
	*out *= 10;
	if (*out > LLONG_MAX - new_digit)
		return (1);
	*out += new_digit;
	return (0);
}

int	long_long_atoi(const char *str, long long *result)
{
	int			sign;
	int			i;

	i = 0;
	*result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (increment(str[i], result, sign))
			return (1);
		i++;
	}
	return (0);
}
