// problem: https://leetcode.com/problems/add-two-numbers
// time complexity  -> O( max(N, M) )  ; N, M - no of nodes in each ListNode
// space complexity -> O( max(N, M) )   ; depents on no of digits to store
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  // create new ListNode for holding sum result
  struct ListNode *res = malloc(sizeof(struct ListNode));
  res->next = NULL;

  struct ListNode *res_head = res;
  int carry = 0;

  while (l1 != NULL || l2 != NULL || carry) {
    int v1 = 0, v2 = 0, sum = 0;

    if (l1) {
      v1 = l1->val;
      l1 = l1->next;
    }

    if (l2) {
      v2 = l2->val;
      l2 = l2->next;
    }

    sum = v1 + v2 + carry;
    res->val = sum % 10;
    carry = sum / 10;

    if (l1 != NULL || l2 != NULL || carry) {
      // creating a new Node and updating the reference
      struct ListNode *nd = malloc(sizeof(struct ListNode));
      nd->next = NULL;

      res->next = nd;
      res = nd;
    }
  }

  return res_head;    
}
