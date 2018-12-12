#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct list_node
{
    char value;
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

void push_front_list(list *l, char value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = l->head;
    l->head = ln;
    l->size++;
}

char pop_front_list(list * l)
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

void push_back_list(list * l, char value)
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

char pop_back_list( list * l)
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

list * reverse(list * l)
{
    list_node * p = l->head;
    list * lAux = create_list();
    if (p == NULL)
    {
        return lAux;
    }

    while( p!= NULL)
    {
        push_front_list(lAux, p->value);
        p = p->next;
    }
    return lAux;
}

bool palindromo(list * l)
{
    list * lAux =  reverse(l);
    list_node * p = l->head;
    list_node * pAux = lAux->head;
    if (p == NULL)
    {
        return false;
    }
    else
        while( p!= NULL)
        {
            if(p->value != pAux->value)
                return false;
            p = p->next;
            pAux = pAux->next;
        }
        return true;
}


int main()
{

list * l = create_list();

//Esto crea una lista con elementos

char greeting[5] = {'H', 'e', 'l', 'e', 'H'};

push_back_list(l, greeting[0]);
push_back_list(l, greeting[1]);
push_back_list(l, greeting[2]);
push_back_list(l, greeting[3]);
push_back_list(l, greeting[4]);


list_node * p = l->head;
while( p!= NULL)
{
//printf("%d\n", pop_front_list(l));
//printf("%d\n", pop_back_list(l));
    printf("%c\n", p->value);
    p = p->next;
}



if(palindromo(l))
    printf("Es Palindromo\n");
else
    printf("No es Palindromo\n");


return 0;

}
