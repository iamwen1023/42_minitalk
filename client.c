#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (sign < 0 && result > 2147483648)
			return (0);
		if (sign > 0 && result > 2147483647)
			return (-1);
	}
	return (((int)result) * sign);
}
int	ft_atobi(const char *str)
{
	int		sign;
	long	result;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	if (*str == '-' || *str == '+')
		return (0);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (sign < 0 && result > 2147483648)
			return (0);
		if (sign > 0 && result > 2147483647)
			return (-1);
	}
	return (((int)result) * sign);
}

void	handler(int sigtype)
{
	printf(" I AM HERE \n");
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int id;
	char *message;
	int i;

	id = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		i = 0;
		while( i < 8)
		{
			if ((*message) & (0x80))
			{
				kill(id, SIGUSR1);
				printf("1");
			}
			else
			{
				kill(id, SIGUSR2);
				printf("0");
			}
			*message = *message << 1;
			++i;
		}
		// printf("%i ", *message & 0x80);
		// printf("%i ", (*message = *message << 1) & 0x80);
		// printf("%i ", (*message = *message << 1) & 0x80);
		// printf("%i ", (*message = *message << 1) & 0x80);
		// printf("%i ", (*message = *message << 1) & 0x80);
		// printf("%i ", (*message = *message << 1) & 0x80);
		// printf("%i ", (*message = *message << 1) & 0x80);
		// printf("%i ", (*message = *message << 1) & 0x80);
		printf("\n");
		++message;
	}
	printf("id : %d\n", id);
	//kill(id, SIGUSR1);
	printf("finished\n");
	return (0);
}