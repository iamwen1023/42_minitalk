#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int state = 0;

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

void	handler(int sigtype)
{
	printf("here");
	if (sigtype == SIGUSR1)
		printf("SIGUSR1");
	else
	{
		printf("SIGUSR2");
	}
}


int	main()
{
	pid_t pid;
	struct sigaction action;
	struct sigaction action2;
	int i;

	pid = getpid();
	ft_putstr("PID :");
	ft_putnbr((int)pid);
	ft_putstr("\n");
	// action1.sa_handler = &handler;
	// //sigemptyset(&action1.sa_mask);
	// //sigaddset(&action1.sa_mask, SIGINT);
	// action2.sa_handler = &handler;
	// //sigaddset(&action2.sa_mask, SIGINT);
	// //sigemptyset(&action2.sa_mask);
	// //action.sa_flags = SA_RESTART;
	// 	sigaction(SIGUSR1 , &action1, NULL);
	// 	sigaction(SIGUSR2 , &action2, NULL);
	// 	int ret = pause();
	//kill(pid, SIGCONT);
	//sleep(1);
	action.sa_flags = SA_SIGINFO;
	action.sa_handler = &handler;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
	printf("after one seconce");
	return (0);
}
