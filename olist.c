#include "olist.h"

// Create a new node on the list
onode_t * new_onode(uint32_t x, uint32_t y, int type)
{
    onode_t *temp = malloc(sizeof(onode_t));
    temp->next = NULL;

    switch(type)
    {
        case AIR_ID:
            temp->obj = new_air(x, y);
            break;

        case WALL_ID:
            temp->obj = new_wall(x, y);
            break;

        case DOOR_ID:
            temp->obj = new_door(x, y, 0);
            break;

        default:
            free(temp);
            return NULL;
            break;
    }
    
    return temp;
}

// Add an existing object to the end of a list
void add_to_end(onode_t *head, object_t *o)
{
    onode_t *current = head;

    while(current != NULL)
    {
        current = current->next;
    }

    current->obj = o;
}

// Print information about every object in the list to stdout
void print_olist(onode_t *head)
{
    onode_t *current = head;
    while(current->next != NULL)
    {
        printf("Object of type %d at (%d, %d). Address: %p\n", 
                current->obj->type, 
                current->obj->pos.x, 
                current->obj->pos.y,
                current->obj);
        current = current->next;
    }
}

// Go through and delete every list item
void delete_olist(onode_t *head)
{
    onode_t *current = head;
    onode_t *next;    

    while(current != NULL)
    {
        next = current->next;
        free(current->obj);
        free(current);
        current = next;
    }

    head = NULL;
}
