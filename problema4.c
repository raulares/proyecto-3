/*
 * Problema 4. Usando una lista simplemente enlazada escribir una función
 * void clear_list(list * l) la cual dada una lista l, remueva todos los nodos de la lista.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct list_node
{
    int value;
    struct list_node * next;
};
typedef struct list_node list_node;

struct list
{
    list_node * head;
    int size;
};
typedef struct list list;

list * create_list()
{
    list * l = (list *) malloc(sizeof(list));
    l->head = NULL;
    l->size = 0;
    return l;
}

bool empty_list(list * l)
{
    return l->size == 0;
}

void push_front_list(list *l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = l->head;
    l->head = ln;
    l->size++;
}

int pop_front_list(list * l)
{
    if (empty_list(l))
        {
        printf("Error");
        return 0;
        }
    int value = l->head->value;
    list_node * ln = l->head;
    l->head = l->head->next;
    free(ln);
    l->size--;
    return value;
}

void push_back_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = NULL;
    list_node * p = l->head;
    while( p!= NULL && p->next != NULL)
    {
        p = p->next;
    }
    if ( p == NULL)
        l->head = ln;
    else
        p->next = ln;
        l->size++;
}

int pop_back_list( list * l)
{
    if (empty_list(l))
    {
        printf("Error empty list ! \n");
        return 0;
    }
    if (l->head->next == NULL)
    {
        int value = l->head->value;
        free(l->head);
        l->head = NULL;
        l->size--;
        return value;
    }
    list_node * ln = l->head;
    while( ln->next->next != NULL)
    {
        ln = ln->next;
    }
    int value = ln->next->value;
    free(ln->next);
    ln->next = NULL;
    l->size--;
    return value;
}

/*
 * Esta función remueve todos los nodos de la lista, para esto, usamos pop_back_list(l) hasta que,
 * l->size sea 0, esto hace que la lista sea vacía.
 */
void clear_list(list * l)
{
    while (l->size > 0)
        {pop_back_list(l);}
}


int main()
{
    list * l = create_list();
    // Esto crea una lista con n elementos 1,2,...,n.
    int n = 15;
    for (int i = 0; i < n; ++i)
        {push_back_list(l, i+1);}

    // Removemos todos los nodos de la lista, luego comprobamos que está vacía.
    clear_list(l);
    list_node * p = l->head;
    if(p == NULL)
        {printf("La lista está vacía.\n");}
    else
        {printf("La lista no está vacía. %d\n",p->value);}
    return 0;
}
