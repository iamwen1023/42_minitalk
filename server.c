#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{	
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		write(1, "-", 1);
		n_long = n_long * (-1);
	}
	if (n_long >= 10)
	{
		ft_putnbr(n_long / 10);
		ft_putchar(n_long % 10 + '0');
	}
	else
		ft_putchar(n_long % 10 + '0');
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
}


int	main()
{
	pid_t pid;
	pid = getpid();
	ft_putstr("PID :");
	ft_putnbr((int)pid);
	ft_putstr("\n");
	//kill(pid, SIGCONT);
	//sleep(1);
	int ret = pause();
        printf("Pause returned with %d\n", ret);
	printf("after one seconce");



	return (0);
}
