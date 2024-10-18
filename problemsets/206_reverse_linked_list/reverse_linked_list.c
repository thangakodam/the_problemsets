// problem: https://leetcode.com/problems/reverse-linked-list/description/

// SOLUTION 01 - Iterative Approach (occuping extra space)
// time complexity  -> O(N)
// space complexity -> O(N)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
  if (!head) return head;

  // creating a initial node to represent reversed linked list
  struct ListNode *reverse = malloc(sizeof(struct ListNode));
  reverse->next = NULL;

  while (head != NULL) {
    reverse->val = head->val;
    
    head = head->next;            // update the head reference to next node

    if (head) {
      // create new node and update the reference
      struct ListNode *node = malloc(sizeof(struct ListNode));
      node->next = reverse;
      node = reverse;
    }
  }

  return reverse;
}


// SOLUTION 02 - Recursive Approach
