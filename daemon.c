#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int
main(int argc, char * const argv[])
{
	int	foreground = 0;
	int	opt;
	pid_t	pid;
	char	*ip;
	FILE	*fp;

	while ((opt = getopt(argc, argv, "fi:")) != -1) {
		switch(opt) {
			case 'f':
				foreground = 1;
				break;
			case 'i':
				ip = optarg;		
			default:
				fprintf(stderr, "Usage: %s [-n] name\n", argv[0]);
				break;
		}
	}
	fp = fopen("Log.txt", "w+");
	if (foreground) {
		while (1) {
			fprintf(fp, "foreground: child running...\n");
			sleep(2);
			fflush(fp);
		}
	} else {
		pid = fork();
		if (pid < 0) {
			exit(0);
		}
		if (pid > 0) {
			printf("process id of child %d %s\n", pid, ip);
			exit(0);
		} 
		umask(0);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		while (1) {
			fprintf(fp, "daemon: child running..%s\n", ip);
			sleep(2);
			fflush(fp);
		}
	}
	printf("optind %d %s", optind, argv[optind]);
	fclose(fp);
	return (0);
}
