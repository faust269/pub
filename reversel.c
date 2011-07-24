#include <stdio.h>
#include <stdlib.h>

typedef struct _s_list_entry {
    void *next;
    int data;
} s_list_entry;

s_list_entry* init_list(void)
{
    s_list_entry *head = NULL;
    s_list_entry *entry = NULL;
    s_list_entry *prev = NULL;
    int ii = 0;

    for (; ii < 10; ii++)
    {
        entry = (s_list_entry*)malloc(sizeof(s_list_entry));
        entry->data = ii;
        entry->next = NULL;

        if (head == NULL)
        {
            head = entry;
        }

        if (prev != NULL)
        {
            prev->next = entry;
        }

        prev = entry;
    }

    return head;
}

void print_list( s_list_entry *list )
{
    s_list_entry *entry = list;

    while (entry != NULL)
    {
        printf("%u", entry->data);
        entry = entry->next;

        if (entry != NULL)
        {
            printf(",");
        }
    }

    printf("\n");

    return;
}

s_list_entry* reverse_list( s_list_entry *list )
{
    s_list_entry *next = NULL;
    s_list_entry *new_head = NULL;

    while (list != NULL)
    {
        /*
         ** pop entry off of first list and
         ** make it the head of the new list
         */
        next = list->next;
        list->next = new_head;
        new_head = list;
        list = next;
    }

    return new_head;
}

int main( int argc, char** argv )
{
    s_list_entry *head = NULL;

    head = init_list();

    print_list(head);

    head = reverse_list(head);

    print_list(head);
    
    return 0;
}
