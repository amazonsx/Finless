/*
 * Test Finless Headers.
 * Authors: Shi Xiao
 * Date created: 2015-08-28
 */
#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#define LIST_DEBUG 1

#ifdef LIST_DEBUG
#include "base_header_list.h"
#endif

int main(int argc, char *argv[])
{
#ifdef LIST_DEBUG
	list_test();
#endif
	return 0;
}

