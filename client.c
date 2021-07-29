#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, char *argv[])
{
	ft_atoi();
	kill(argv[1], SIGKILL);
	printf("finished\n");
	return (0);
}