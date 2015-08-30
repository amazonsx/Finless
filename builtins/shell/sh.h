/*
 * This file is part of Finless Shell
 * Authors: Shi Xiao
 * Date created: 2015-08-28
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <pthread.h>

const char *builtin_cmds[] = {
	"ls",
	"cd",
	"rm",
	"touch"
};

const char ops[] = {
	'<',	//Input Redirection
	'>', 	//Output Redirection
	'|'	//Pipeline
};

typedef
struct cmd_type {
	int name;
	bool is_builtin;
	int argc;
	char *argv[];
	int errno;

} cmd_type;
