#include <stdio.h>
#include <stdlib.h>


typedef struct list_s
{
  int digit;
  struct list_s *next;
} list_t;

void print_list(list_t *head)
{
  list_t *current;

  if (!head)
    return;

  for (current = head; current; current = current->next)
    printf("%d\n", current->digit);
}

void free_list(list_t *h)
{
	list_t *node;
	while (h)
	{
		node = h;
		h = h->next;
		free(node);
	}
}

list_t *convert_num_to_list(int n)
{
  list_t *node, *head = NULL, *tail = NULL;
  int is_one_iteration = 0;

  while(n || !is_one_iteration)
  {
    is_one_iteration = 1;
    node = malloc(sizeof(list_t));
    if (!node)
    {
    	free_list(head);
      return (NULL);
    }

    node->digit = n % 10;
    node->next = NULL;
    tail ? (tail->next = node) : (void *)0;
    tail = node;
    !head ? head = node : (void *)0;
    n /= 10;
  }
  return (head);
}

list_t *reverse_list(list_t *head)
{
  list_t *current,*next, *prev = NULL;

  current = head;
  while(current)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return (head);
}

int is_pali(list_t *head)
{
  list_t *slow = head, *fast = head, *prev = NULL;
  int keep_going = 1;

  while(fast && fast->next)
  {
    fast = fast->next->next;
    prev = slow;
    slow = slow->next;
  }

  if (fast)
  	slow = slow->next;

  slow = reverse_list(slow);
  while(slow && keep_going)
  {
    if (head->digit != slow->digit)
    	keep_going = 0;
    head = head->next;
    prev = slow;
    slow = slow->next;
  }

  slow = reverse_list(prev);
  return (keep_going);
}



int main()
{
    int j, i, num, max = 0;
    list_t *digits;

    for (i = 100; i < 1000; i++)
      for (j = i; j < 1000; j++)
      {
      	num = i * j;
       	digits = convert_num_to_list(num);
        if (is_pali(digits))
                max = num > max ? num : max;
        free_list(digits);
      }

  printf("max is %d\n", max);



  return (0);
}
