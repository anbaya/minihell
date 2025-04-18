
#include "minihell_test.h"

// void parse_input(char *input) {
// 	char *args[MAX_ARGS];
// 	int i = 0;

// 	// Tokenize the input string into arguments
// 	char *token = strtok(input, " \t\n");
// 	while (token != NULL && i < MAX_ARGS - 1) {
// 		args[i++] = token;
// 		token = strtok(NULL, " \t\n");
// 	}
// 	args[i] = NULL; // Null-terminate the argument list

// 	if (args[0] == NULL) {
// 		// Empty input
// 		return;
// 	}

// 	// Print the parsed arguments
// 	printf("Parsed arguments:\n");
// 	for (int j = 0; j < i; j++) {
// 		printf("arg[%d]: %s\n", j, args[j]);
// 	}
// }

Node *create_node(char *arg) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (!new_node) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new_node->arg = strdup(arg);
	if (!new_node->arg) {
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	return new_node;
}

Node *parse_input_to_list(char *input) {
	Node *head = NULL, *tail = NULL;

	// Tokenize the input string into arguments
	char *token = strtok(input, " \t\n");
	while (token != NULL) {
		Node *new_node = create_node(token);
		if (!head) {
			head = new_node;
			tail = new_node;
		} else {
			tail->next = new_node;
			tail = new_node;
		}
		token = strtok(NULL, " \t\n");
	}
	// print_list(head);
	// free_list(head); // Free the list after printing
	// Return the head of the list
	execution(head);
}

void free_list(Node *head) {
	while (head) {
		Node *temp = head;
		head = head->next;
		free(temp->arg);
		free(temp);
	}
}

void print_list(Node *head) {
	printf("Parsed arguments as linked list:\n");
	int i = 0;
	while (head) {
		printf("arg[%d]: %s\n", i++, head->arg);
		head = head->next;
	}
}
int main() {
	char input[MAX_INPUT];

	while (1) {
		printf("\033[1;31mninja-shell🗡 \033[0m");
		if (fgets(input, sizeof(input), stdin) == NULL) {
			break; // Exit on EOF
		}

		// Exit the shell if the user types "exit"
		if (strncmp(input, "exit", 4) == 0 && (input[4] == '\n' || input[4] == '\0')) {
			break;
		}

		parse_input_to_list(input);
	}

	return 0;
}
