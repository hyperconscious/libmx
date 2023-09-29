#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data){
    t_list *new_node = mx_create_node(data);
    t_list *curr = *list;

    if(*list == NULL){
        *list = new_node;
    } else {
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
    }
}

