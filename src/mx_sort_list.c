#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
    if(!lst || !cmp) return NULL;

    t_list *sorted = NULL;

    while (lst) {
        t_list *current = lst;
        lst = lst->next; 

        if (!sorted || cmp(sorted->data, current->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            t_list *temp = sorted;
            while (temp->next && !cmp(temp->next->data, current->data)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    return sorted;
}

