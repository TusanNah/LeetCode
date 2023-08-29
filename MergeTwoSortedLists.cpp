//You are given the heads of two sorted linked lists list1 and list2.
//
//Merge the two lists into one sorted list.The list should be made by splicing together the nodes of the first two lists.
//
//Return the head of the merged linked list.

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* head = NULL;
		if (list1 == NULL)
			return list2;
		if (list2 == NULL)
			return list1;
		if (list1->val < list2->val) {
			head = list1;
			list1 = list1->next;
		}
		else {
			head = list2;
			list2 = list2->next;
		}
		ListNode* lRes = head;
		while (list1 && list2) {
			if (list1->val < list2->val) {
				lRes->next = list1;
				list1 = list1->next;
			}
			else {
				lRes->next = list2;
				list2 = list2->next;
			}
			lRes = lRes->next;
		}
		if (list1) {
			lRes->next = list1;
		}
		if (list2) {
			lRes->next = list2;
		}
		return head;
	}
};