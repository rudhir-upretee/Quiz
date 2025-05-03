/******************************************************************************

Reverse pairs of nodes in linked list 
Input: 1->2->3->4->5->6 
Output: 2->1->4->3->6->5 

*******************************************************************************/
#include <stdio.h>

typedef struct node
{
    int val;
    struct node* next;
}node;

node* reverseListInPairs(node* head)
{
    node tmp;
    
    node* first, *second, *next, *prev;
    
    if((head==NULL) || (head->next==NULL))
    {
        return head;
    }
    
    prev = &tmp;
    first = head;
    
    while((first!=NULL) && (first->next!=NULL))
    {
        //save next
        second = first->next;
        next = second->next;
        
        //swap the pairs
        second->next = first;
        
        //connect previous
        prev->next = second;
        
        //update previous
        prev = first;
        
        //next round
        first = next;
    }
    
    if(first != NULL)
    {
        //connect previous
        prev->next = first;
        
        //update previous
        prev = first;
    }
    
    prev->next = NULL;
    
    return tmp.next;
}

void printList(node *head)
{
    while(head != NULL)
    {
        printf("val:%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    const int CNT = 6;
    int i;
    node *revList;
    
    node a[CNT];
    for(i = 0; i < (CNT-1); i++)
    {
        a[i].val = i;
        a[i].next = &a[i+1];
    }
    a[i].val = i;
    a[i].next = NULL;
    
    printf("Original List:\n");
    printList(&a[0]);
    
    revList = reverseListInPairs(&a[0]);
    printf("Reverse List:\n");
    printList(revList);
    
    
    
    const int CNT2 = 5;
    node b[CNT2];
    for(i = 0; i < (CNT2-1); i++)
    {
        b[i].val = i;
        b[i].next = &b[i+1];
    }
    b[i].val = i;
    b[i].next = NULL;
    
    printf("Original List:\n");
    printList(&b[0]);
    
    revList = reverseListInPairs(&b[0]);
    printf("Reverse List:\n");
    printList(revList);


    return 0;
}