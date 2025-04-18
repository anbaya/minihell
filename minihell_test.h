#ifndef MINIHELL_TEST_H
#define MINIHELL_TEST_H

// Include necessary standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <ctype.h>
#include <sys/stat.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

// Function prototypes
typedef struct Node {
	char *arg;
	struct Node *next;
} Node;

void parse_input(char *input);
void print_list(Node *head);
void free_list(Node *head);
Node *parse_input_to_list(char *input);
Node *create_node(char *arg);
int execution(Node *head);

#endif // MINIHELL_TEST_H
