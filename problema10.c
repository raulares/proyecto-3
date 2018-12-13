/*
 * Problema 10. Modifique la lista doblemente enlazada para que tenga valores tipo caracteres
 * y escribir una función bool palindromo(list * l) que devuelva si la lista de caracteres
 * es un palíndromo.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Primero cambiamos todos los datos int value, por char value, para usar caracteres.
struct list_node
{
    char value;
    struct list_node * next;
    struct list_node * previous;
};
typedef struct list_node list_node;

struct list
{
    list_node * head;
    list_node * tail;
    int size;
};
typedef struct list list;

list * create_list()
{
    list * l = (list *) malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
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
    ln->next = NULL;
    ln->previous = NULL;
    if (empty_list(l))
    {
        l->head = ln;
        l->tail = ln;
        l->size++;
    }
    else
    {
        ln->next = l->head;
        l->head = ln;
        l->size++;
    }
}

void push_back_list(list * l, char value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = NULL;
    ln->previous = NULL;
    if(empty_list(l))
    {
        l->head = ln;
        l->tail = ln;
        l->size++;
    }
    else
    {
        ln->previous = l->tail;
        l->tail->next = ln;
        l->tail = ln;
        l->size++;
    }
}

char pop_front_list(list * l)
{
    if(empty_list(l))
    {
        printf("Error empty list \n");
        return 0;
    }
    char value = l->head->value;
    list_node * ln = l->head;
    if (l->size == 1)
    {
        l->size--;
        l->head = NULL;
        l->tail = NULL;
        free(ln);
        return value;
    }
    else
    {
        l->head = l->head->next;
        l->head->previous = NULL;
        free(ln);
        l->size--;
        return value;
    }
}

char pop_back_list(list * l)
{
    if(empty_list(l))
    {
        printf("Error empty list \n");
        return 0;
    }
    char value = l->tail->value;
    list_node * ln = l->tail;
    if (l->size == 1)
    {
        l->size--;
        l->head = NULL;
        l->tail = NULL;
        free(ln);
        return value;
    }
    else
    {
        l->tail = l->tail->previous;
        l->tail->next = NULL;
        free(ln);
        l->size--;
        return value;
    }
}

/*
 * Esta función regresa true si la lista de caracteres es un palíndromo, para hacer esto
 * iteramos la lista en dos direcciones, del comienzo y del final, y comparamos sus valores
 * hasta llegar a la mitad, si son todos iguales, la lista de caracteres es un palíndromo.
 */
bool palindromo(list * l)
{
    list_node * pDer = l->head;
    list_node * pIzq = l->tail;
    if(pDer == NULL)
        {return false;}
    else
    {
        for (int i = 1; i <= l->size / 2; i++)
        {
            if (pDer->value != pIzq->value)
                {return false;}
            pDer = pDer->next;
            pIzq = pIzq->previous;
        }
        return true;
    }
}

int main()
{
    list * l = create_list();
    // Esto crea una lista con los elementos de letras
    char letras[5] = {'a', 'p', 'o', 'p', 'a'};
    push_back_list(l, letras[0]);
    push_back_list(l, letras[1]);
    push_back_list(l, letras[2]);
    push_back_list(l, letras[3]);
    push_back_list(l, letras[4]);

    // Comprobamos si la lista de caracteres es un palíndromo.
    if(palindromo(l))
        printf("La lista de caracteres es un palíndromo\n");
    else
        printf("La lista de caracteres no es un palíndromo\n");

    return 0;
}
