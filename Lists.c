#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{

    int data;
    struct Node *next;

} node;

node *CreateNewNodeEnd(node *list, int value){

    if(list == NULL){

        list = (node *)malloc(sizeof(node));

        list->data = value;
        list->next = NULL;

    }
    else{

        node *temp, *n;

        temp = list;

        while(temp->next != NULL){

            temp = temp->next;
        }

        n = (node *)malloc(sizeof(node));

        n->data = value;
        n->next = NULL;

        temp->next = n;

    }

    return list;
}

node *CreateNewNodeIndex(node *list, int value, int index){

    node *temp, *n;
    int i = 0;

    temp = list;

    while(i < index - 1){

        temp = temp->next;
        i++;
    }

    n = (node *)malloc(sizeof(node));

    n->data = value;
    n->next = temp->next;

    temp->next = n;

    return list;
}

node *ConcatenatingTwoLists(node *list1, node *list2){

    node *temp;

    temp = list1;

    while(temp->next != NULL){

        temp = temp->next;
    }

    temp->next = list2;

    return list1;
}

void ClearAllList(node *list){

    node *temp, *prev;

    temp = list;
    prev = NULL;

    while(temp->next != NULL){

        prev = temp;
        temp = temp->next;

        free(prev);
        prev = NULL;
    }

}

node *CloneList(node *list){

    node *temp, *c, *newlist, *p;

    temp = list;
    newlist = NULL;
    p = NULL;


    while(temp->next != NULL){

        c = (node *)malloc(sizeof(node));

        c->data = temp->data;
        c->next = temp->next;

        if(newlist == NULL)
        {
            newlist = c;
            p = c;
        }
        else
        {
            p->next = c;
            p = p->next;
        }

        temp = temp->next;
    }

    return newlist;

}

bool Contains(node *list, node *element)
{
    node *temp;

    temp = list;

    while(temp->next != NULL){

        if(temp == element){

            return true;
        }
        temp = temp->next;
    }

    return false;
}

node *GetElementIndex(node *list, int index){

    node *temp;
    int i = 0;

    temp = list;

    while(i < index){

        temp = temp->next;
        i++;
    }

    return temp;

}

int IndexOfElement(node *list, node *element){

    node *temp;
    int index = -1;
    int i = 0;

    temp = list;

    while(temp->next != NULL){

        if(temp == element)
        {
            index = i;
            return index;
        }

        i++;
        temp = temp->next;
    }

    return index;
}

void RemoveElementAtIndex(node *list, int index){

    node *temp;
    int i = 0;

    temp = list;

    while(i < index - 1){

        i++;
        temp = temp->next;
    }

    node *el;
    el = temp->next;

    temp->next = temp->next->next;

    free(el);

}

void RemoveElement(node *list, node *element){

    node *temp;

    temp = list;

    while(temp->next != NULL){

        if(temp->next == element)
        {
            node *el;
            el = temp->next;

            temp->next = temp->next->next;

            free(el);

            return;
        }

        temp = temp->next;
    }

}

int ListSize(node *list)
{
    int num = 0;
    node *temp;

    temp = list;

    while(temp != NULL){

        num++;
        temp = temp->next;
    }

    return num;
}


void ListToArray(node *list, int array[])
{
    int numberofelements = ListSize(list);

    node *temp;
    int i = 0;

    temp = list;

    while(temp != NULL){

        array[i] = temp->data;
        temp = temp->next;
        i++;
    }

}

void DisplayElements(node *list, int elementnumber, char nameoflist[])
{
    if(list == NULL)
    {
        return;
    }
    else
    {
        printf("%s - Element number %d >> %d\n", nameoflist, elementnumber, list->data);

        DisplayElements(list->next, elementnumber + 1, nameoflist);
    }
}

int main()
{
    node *list, *list2, *clonedlist;
    int n1 = 0, n2 = 0;
    list = NULL;
    list2 = NULL;
    clonedlist = NULL;

    printf("List 1 - Enter the number of elements >> ");
    scanf("%d", &n1);

    for(int i = 0; i < n1; i++){

        int element = 0;

        if(i == 0)
        {
            printf("List 1 - Enter the %dst element >> ", (i+1));
        }
        else if(i == 1)
        {
            printf("List 1 - Enter the %dnd element >> ", (i+1));
        }
        else if(i == 2)
        {
            printf("List 1 - Enter the %drd element >> ", (i+1));
        }
        else
        {
            printf("List 1 - Enter the %dth element >> ", (i+1));
        }

        scanf("%d", &element);

        list = CreateNewNodeEnd(list, element);

    }

    printf("\n");

    printf("List 2 - Enter the number of elements >> ");
    scanf("%d", &n2);

    for(int i = 0; i < n2; i++){

        int element = 0;

        if(i == 0)
        {
            printf("List 2 - Enter the %dst element >> ", (i+1));
        }
        else if(i == 1)
        {
            printf("List 2 - Enter the %dnd element >> ", (i+1));
        }
        else if(i == 2)
        {
            printf("List 2 - Enter the %drd element >> ", (i+1));
        }
        else
        {
            printf("List 2 - Enter the %dth element >> ", (i+1));
        }

        scanf("%d", &element);

        list2 = CreateNewNodeEnd(list2, element);

    }

    printf("\n");

    DisplayElements(list, 1, "List 1");

    //******************************

    printf("\n");

    DisplayElements(list2, 1, "List 2");

    //******************************

    list = CreateNewNodeIndex(list, 0, 3);

    printf("\n");

    DisplayElements(list, 1, "List 1 after adding 0");

    //******************************

    list = ConcatenatingTwoLists(list, list2);

    printf("\n");

    DisplayElements(list, 1, "List 1 + List 2 >> List 1");

    //******************************

    clonedlist = CloneList(list);

    printf("\n");

    DisplayElements(clonedlist, 1, "Cloned List 1");

    //*******************************

    printf("\n");

    if(Contains(list, list->next->next) == true){
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    //*******************************

    if(Contains(list2, list->next->next) == true){
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    //*******************************

    printf("\nList 1 - Element on index 3 >> %d\n", GetElementIndex(list, 3)->data);

    //*******************************

    printf("\nList 1 - Index of 3rd element >> %d\n", IndexOfElement(list, list->next->next));

    //*******************************

    RemoveElementAtIndex(list, 3);

    printf("\n");

    DisplayElements(list, 1, "List 1 after deleting 0");

    //*******************************

    RemoveElement(list, list->next);

    printf("\n");

    DisplayElements(list, 1, "List 1 after deleting 2");

    //*******************************

    if(ListSize(list) == 1){

        printf("\nList 1 - Size >> %d element\n", ListSize(list));

    }
    else{

        printf("\nList 1 - Size >> %d elements\n", ListSize(list));

    }

    //*******************************

    if(ListSize(list2) == 1){

        printf("\nList 2 - Size >> %d element\n", ListSize(list2));

    }
    else{

        printf("\nList 2 - Size >> %d elements\n", ListSize(list2));

    }


    //*******************************

    printf("\n");

    int array[ListSize(list)];
    ListToArray(list, array);

    for(int i = 0; i < ListSize(list); i++)
    {
        printf("List 1 >> Array - Element %d >> %d\n", (i+1), array[i]);
    }

    return 0;
}
