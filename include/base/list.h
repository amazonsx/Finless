/*
 * Define general list operations
 * for both singly and doubly linked lists.
 *
 * Authors: Shi Xiao
 * Date created: 2015-08-28
 */

/*
 * Singly Linked List.
 */


/*
 * Doubly Linked List.
 */
typedef
struct hlist_head{ //head list
	struct hlist_head *next, *prev;
} hlist_head;

//#define HLIST_HEAD_INIT(name) \ //name is the List Name
	//{ &(name), &(name) }

typedef 
struct dlist_node{ 
	struct dlist_node *next; //to the next list_head
	struct dlist_node **prev; //to the previous list_head.next
} dlist_node;

typedef
struct dlist_head{
	dlist_node *next, *prev;
} dlist;

#define DLIST_HEAD_INIT( list_body, list) \
	{ (list_body)->list = (dlist){NULL, NULL}; } //attention the parenthesis around list


// NOTE(shixiao):
// If the node_body have the same name with the inner node var,
// there will be a mistake when compiling.
#define DLIST_INSERT_HEAD(list_body, mem_list, node_body, mem_node) 		\
	{							\
		dlist *list = &((list_body)->mem_list);		\
		dlist_node *dnode = &((node_body)->mem_node);	\
		if ((list)->next == NULL) {			\
			(list)->prev = dnode;			\
			(list)->next = dnode;			\
			(dnode)->next = NULL;			\
			(dnode)->prev = NULL;			\
		} else {					\
			dlist_node *tmp = (list)->next;		\
			(dnode)->next = tmp;			\
			(dnode)->prev = NULL;			\
			(list)->next = dnode;			\
			if (!tmp->prev) {			\
				tmp->prev = malloc(sizeof(dlist_node**));	\
				*((tmp)->prev) = dnode;				\
			}							\
		}						\
	}

#define DLIST_INSERT_TAIL(list_body, mem_list, node_body, mem_node) 		\
	{					\
		dlist *list = &((list_body)->mem_list);	\
		dlist_node *dnode = &((node_body)->mem_node);	\
		if ((list)->prev == NULL) {	\
			(list)->prev = dnode;	\
			(list)->next = dnode;	\
			(dnode)->next = NULL;	\
			(dnode)->prev = NULL;	\
		} else {			\
			dlist_node *tmp = (list)->prev;	\
			(dnode)->next = NULL;		\
			tmp->next = dnode;		\
			(dnode)->prev = malloc(sizeof(dlist_node**));		\
			*((dnode)->prev) = tmp;		\
			(list)->prev = dnode;		\
		}				\
	}

#define DLIST_REMOVE_HEAD(list_body, mem_list, removed_node) 			\
	{	dlist *list = &((list_body)->mem_list);			\
	 	dlist_node *tmp = (list)->next;				\
		if ((list)->next) {					\
			(list)->next = tmp->next;			\
			if (tmp->next) { 				\
				free(tmp->next->prev); 			\
				tmp->next->prev = NULL;			\
			} else { (list)->prev = NULL; }			\
		}							\
		removed_node = tmp;					\
	}

#define DLIST_REMOVE_TAIL(list_body, mem_list, removed_node) 			\
	{	dlist *list = &((list_body)->mem_list);			\
		dlist_node *tmp = (list)->prev;				\
		if ((list)->prev) {					\
			(list)->prev = NULL;				\
			if (tmp->prev) { 				\
				(list)->prev = *(tmp->prev);		\
				(list)->prev->next = NULL;		\
				free(tmp->prev);			\
			} else { (list)->next = NULL; }			\
		}							\
		removed_node = tmp;					\
	}

#define DLIST_ITERATE_INC(list_body, mem_list, node) 				\
		dlist *i_dlist_i = &((list_body)->mem_list);			\
		for (node = i_dlist_i->next; 				\
			node != NULL; node = node->next)

#define DLIST_ITERATE_DEC(list_body, mem_list, node) 				\
		dlist *i_dlist_d = &((list_body)->mem_list);			\
		for (node = i_dlist_d->prev; 				\
			node != NULL; node = node->prev ? *node->prev : NULL)
