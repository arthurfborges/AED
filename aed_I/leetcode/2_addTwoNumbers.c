/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *Head;
    Head = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(!Head){
        printf("erro ao alocar head");
        exit(1);
    }

    Head->next = NULL;
    int sum=0, carry =0;

    struct ListNode *resultList = Head;

    while(l1 || l2 || carry != 0){
        sum = carry;
        
        if(l1){
        sum += l1->val ;
        l1= l1->next;}

        if(l2){
        sum += l2->val ;
        l2= l2->next;}

        carry = sum / 10;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(!newNode){
        printf("erro ao alocar head");
        exit(1);
        }
        
        newNode->val = sum % 10;
        newNode->next = NULL;

        resultList->next = newNode;
        resultList = resultList->next;

    }
    return Head->next;
}