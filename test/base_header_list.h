#include <string.h>
#include <errno.h>

#include "../include/base/list.h"

struct demo_data_node {                                                      
	dlist_node node;                                                     
	int id;                                                              
	char name[8];
};                                                                           

struct demo_data_list {                                                      
	dlist list_head;                                                
};                                                                           

extern int errno;

int list_test(void)                                                              
{                                                                            
	// TEST DLIST_HEAD_LIST
	struct demo_data_list data_list;
	DLIST_HEAD_INIT(&data_list, list_head);
	// Create 10 nodes for the list
	for ( int i = 0; i < 20; i ++) {
		struct demo_data_node *node = malloc(sizeof(struct demo_data_node));
		// node.id = i; node.name = NODE$i                          
		node->id = i;
		char *name_id = malloc(2);
		name_id[0] = i + 'A';
		name_id[1] = 0;
		//node->name = "NODE";
		if (strcpy(node->name, "NODE") != node->name) {
			printf("The errno of strcpy is %d\n", errno);
		}
		if (!strcat(node->name, name_id)) {
			printf("The errno of strcat is %d:\n", errno);
		}
		printf("The node name is %s\n", node->name);
		free(name_id);
		// if block without {} and add ; at the end, it will wrong
		if (i < 10) {DLIST_INSERT_HEAD(&data_list, list_head, node, node)}
		else { DLIST_INSERT_TAIL(&data_list, list_head, node, node)}
	}                                                                   

	struct demo_data_node *iter_node = NULL;
	dlist_node *iter_nodep = NULL;
	DLIST_ITERATE_INC(&data_list, list_head, iter_nodep) {
		iter_node = (struct demo_data_node*)iter_nodep;
		printf("INC Iterate node %s\n", iter_node->name);
	}
	DLIST_ITERATE_DEC(&data_list, list_head, iter_nodep) {
		iter_node = (struct demo_data_node*)iter_nodep;
		printf("DEC Iterate node %s\n", iter_node->name);
	}
	
	for (int i = 0; i < 20; i ++) {                                     
		struct demo_data_node *node = NULL;
		dlist_node *node_pointer = NULL;

		if (i < 10) { DLIST_REMOVE_TAIL(&data_list, list_head, node_pointer) }
		else { DLIST_REMOVE_HEAD(&data_list, list_head, node_pointer) }
		//DLIST_REMOVE_HEAD(&data_list, list_head, node_pointer);
		//DLIST_REMOVE_TAIL(&data_list, list_head, node_pointer);

		node = (struct demo_data_node*)node_pointer;
		printf("Remove node %s\n", node->name);
		free(node);                                                 
	}                                                                   

	return 0;                                                           
}                                                                           
