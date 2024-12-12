#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastructures/headers/list.h"

void print_list_details(List *list)
{
    printf("============================================\n");
    printf("\tLIST ADDRESS: %p\n", list);
    printf("\tLIST SIZE: %d\n", list->size);
    printf("\tLIST HEAD: %p\n", list->head);
    if (list->head != NULL)
    {
        printf("\t\tLIST HEAD DATA: %s\n", list->head->data);
        printf("\t\tLIST HEAD NEXT: %p\n", list->head->next);
    }
    if (list_size(list) > 2)
    {
        printf("\tLIST BODY:\n");
        ListElmt *current = list->head->next;
        while ( current != list->tail)
        {
            printf("\t\tLIST ELEMENT ADDRESS: %p\n", current);
            printf("\t\tLIST ELEMENT DATA: %s\n", current->data);
            printf("\t\tLIST ELEMENT NEXT: %p\n", current->next);
            printf("\t\t----------------------------------\n");
            current = current->next;
        }
    }
    printf("\tLIST TAIL: %p\n", list->tail);
    if (list->tail != NULL)
    {
        printf("\t\tLIST TAIL DATA: %s\n", list->tail->data);
        printf("\t\tLIST TAIL NEXT: %p\n", list->tail->next);
    }
}

void cdestroy(void *data)
{
    free(data);
    return;
}

int cmatch(const void *val1, const void *val2)
{
    return (char *) val1 == (char *) val2;
}

void list_test(){
    List my_list;
    list_init(&my_list, cdestroy);


    char *elements[] = {
        "[Element:1]",
        "[Element:2]",
        "[Element:3]",
        "[Element:4]",
        "[Element:5]",
        "[Element:6]",
        "[Element:7]",
        "[Element:8]",
        "[Element:9]",
        "[Element:10]",
    };
    for (int i = 0; i < 10; i++)
    {
        char *my_head_data = (char *) malloc(24*sizeof(char));
        if (my_head_data == NULL)
        {
            return -1;
        }
        strcpy(my_head_data, elements[i]);
        list_ins_next(&my_list, NULL, my_head_data);
    }

    my_list.match = cmatch;

    // printf("%d\n", my_list.match(my_list.head, my_list.tail));

    print_list_details(&my_list);

    list_destory(&my_list);

    return;
}


int main()
{
    return 0;
}