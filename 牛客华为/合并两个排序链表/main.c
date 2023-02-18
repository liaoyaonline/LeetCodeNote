#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
  struct ListNode *next;
  int val;
} node;

//typedef bool (* remove_fn)(node const * v);
typedef remove_fn (node const * v);

node* creat_list(){

	//申请头结点
	node* head = (node* )malloc(sizeof(node));

	head->next = NULL;
	scanf("%d",&(head->val)); // 头结点的数据域可以存放总结点数

	//新增元素
	node* p =  NULL;
	int i;
	for(i=0;i<(head->val);i++){

		p = (node* )malloc(sizeof(node));

		scanf("%d",&(p->val));

		//这是头插法的关键所在
		p->next = head->next;
		head->next = p;

	}
	return head;

}
void print_list(node* head){

		node* p = head->next;

		while(p){

			printf("p->data: %d \t",p->val);

			p = p->next;

		}
		printf("\n");
}
struct ListNode* Merge(struct ListNode*pHead1,struct ListNode* pHead2){
    if(pHead1 == NULL)
    {
        return pHead2;
    }
    if(pHead2 == NULL)
    {
        return pHead1;
    }
    if(pHead1->val <= pHead2->val)
    {
        pHead1->next = Merge(pHead1->next,pHead2);
        return pHead1;
    }
    else
    {
        pHead2->next =Merge(pHead1,pHead2->next);
        return pHead2;
    }
}
int main()
{
    node* head = creat_list();
    node* head2 = creat_list();
    print_list(head);
    print_list(head2);
    node* head3 = Merge(head,head2);
    print_list(head3);
    return 0;
}

