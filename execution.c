#include "minihell_test.h"

int execution(Node *head)
{
	int status;
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		// Child process
		char *args[MAX_ARGS];
		Node *current = head;
		int i = 0;

		while (current != NULL && i < MAX_ARGS - 1) {
			args[i++] = current->arg;
			current = current->next;
		}
		args[i] = NULL; // Null-terminate the argument list

		if (execvp(args[0], args) == -1) {
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else {
		// Parent process
		waitpid(pid, &status, 0);
	}
	return WEXITSTATUS(status);
}
