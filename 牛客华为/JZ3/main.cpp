#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x),next(NULL){

        }
};
class Solution{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> Num;
        ListNode* phead = head;
    }
    ListNode* createList(void){
        ListNode *p = NULL;
        struct ListNode *head = new ListNode(0);
        p = head;
        int x = 0;
        for(int i = 0; i < 10;i++)
        {
            cout <<"Please input the data for single linker:";
            cin >> x;
            ListNode *s = new ListNode(0);
            s-> val = x;
            cout <<"Input data:" << x <<endl;
            p->next = s;
            p = p->next;
        }
        head = head -> next;
        cout <<"hh:" << head->val << endl;
        p->next = NULL;
        return head;
    }
    void printlist(ListNode* head){
        ListNode *p = head;
        while(p != NULL){
            cout << p-> val <<":";
            p = p->next;
        }
    }
};
int main()
{
    Solution a;
    ListNode *test = a.createList();
    a.printlist(test);
    return 0;
}

