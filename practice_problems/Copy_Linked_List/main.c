/* 
 * Write program to copy a linked list.
 */
 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct Node
 {
     int val;
     struct Node* next;
 }Node;
 
 void printList(Node* n)
 {
    while(n!=NULL)
    {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
 }
 
 void copyList(Node* srcList, Node** destList)
 {
     Node* newNode;
     Node* prev;
     Node dummy;
     dummy.next = NULL;
     prev = &dummy;
     
     while(srcList != NULL)
     {
        newNode = malloc(sizeof(Node));
        newNode->val = srcList->val;
        newNode->next = NULL;
        prev->next = newNode;
        
        prev = newNode;
        srcList = srcList->next;
     }
     
     *destList = dummy.next;
 }
 
 int main()
 {
     Node arrNodes[3];
     arrNodes[2].val = 2;
     arrNodes[2].next = NULL;
     
     #if 0
     for(int i = 0; i < (3-1); i++)
     {
         arrNodes[i].val = i;
         arrNodes[i].next = &arrNodes[i+1];
     }
     #else /* Alternate way */
     for(int i = 1; i >= 0; i--)
     {
         arrNodes[i].val = i;
         arrNodes[i].next = &arrNodes[i+1];
     }
     #endif
     
     Node* in = &arrNodes[0];
     Node* out = NULL;
     printList(in);
     copyList(in, &out);
     printList(out);
     
     return 0;
 }