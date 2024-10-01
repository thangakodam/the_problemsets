typedef struct {
  int top;
  int val[100];
} stack;

stack* stack_init() {
  stack *st = malloc(sizeof(stack));
  st->top = -1;

  return st;
}

bool is_stack_full(stack *st) {
  return (st->top >= 100 - 1);
}

bool is_stack_empty(stack *st) {
  return (st->top == -1);
}

void stack_push(stack *st, int val) {
  // check stack is not full
  if (is_stack_full(st)) return;

  st->top++;
  st->val[st->top] = val;
}

int stack_pop(stack *st) {
  if (is_stack_empty(st)) return 0;

  int tmp = st->val[st->top];
  st->top--;
  return tmp;
}

void stack_destroy(stack *st) {
  free(st);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// problem: https://leetcode.com/problems/add-two-numbers-ii
// time complexity  -> O(M + N)  ; N, M - no of nodes in listNode
// space complexity -> O(1)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  stack *s1 = stack_init();
  stack *s2 = stack_init();

  // populate the stack with value form both the linked list
  while (l1 != NULL || l2 != NULL) {
    if (l1) {
      stack_push(s1, l1->val);
      l1 = l1->next;
    }

    if (l2) {
      stack_push(s2, l2->val);
      l2 = l2->next;
    }
  }

  struct ListNode *res = malloc(sizeof(struct ListNode));
  res->next = NULL;

  int carry = 0;

  while (!is_stack_empty(s1) || !is_stack_empty(s2) || carry) {
    int sum = stack_pop(s1) + stack_pop(s2) + carry;
    res->val = sum % 10;
    carry = sum / 10;

    if (!is_stack_empty(s1) || !is_stack_empty(s2) || carry) {
      struct ListNode *nd = malloc(sizeof(struct ListNode));
      nd->next = res;
      res = nd;
    }
  }

  return res;  
}
