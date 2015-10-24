#ifndef OLIST_H_
#define OLIST_H_

// olist.h
// linked list of objects

#include <stdlib.h>
#include "object.h"

struct onode
{
    struct onode *next;
    object_t *obj;
};

typedef struct onode onode_t;

onode_t * new_onode(uint32_t x, uint32_t y, int type);
void add_to_end(onode_t *head, object_t *o);
void print_olist(onode_t *head);
void delete_olist(onode_t *head);
#endif
