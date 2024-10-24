#include <stdio.h>

#define MAX 100

struct stack
{
  int st[100];
  int top;
};

void initialise(struct stack *s1)
{
  s1->top = -1;
}

int isFull(struct stack *s1)
{
  return s1->top == MAX - 1; // Overflow Condition
}

int isEmpty(struct stack *s1)
{
  return s1->top == -1; // Underflow Condition
}

void push(struct stack *s1, int data)
{
  if (isFull(s1))
  {
    printf("Stack Overflow\n");
    return;
  }
  s1->st[++(s1->top)] = data;
}

int pop(struct stack *s1, int *popped)
{
  if (isEmpty(s1))
  {
    printf("Stack Underflow\n");
    return -1;
  }
  *popped = s1->st[s1->top--];
}

void peek(struct stack *s1)
{
  if (isEmpty(s1))
  {
    printf("Stack Empty\n");
    return;
  }
  printf("Element : %d", s1->st[s1->top]);
}
void display(struct stack *s1)
{
  if (isEmpty(s1))
  {
    return;
  }
  int temp;
  pop(s1, &temp);
  printf("%d \t", temp);
  display(s1);
  push(s1, temp);
}
void sort(struct stack *s1)
{
  if (isEmpty(s1))
  {
    return;
  }
  int b;
  pop(s1, &b);
  sort(s1);
  insert_popped(s1, &b);
}
insert_popped(struct stack *s1, int *b)
{
  if (isEmpty(s1) || s1->st[s1->top] <= *b)
  {
    push(s1, *b);
    return;
  }
  int temp;
  pop(s1, &temp);
  insert_popped(s1, b);
  push(s1, temp);
}
int main()
{
  struct stack s1;
  int popped, data, choice;
  initialise(&s1);
  do
  {
    printf("\n::Stack Operations::\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Sort\n");
    printf("6. Exit\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the data to store\n");
      scanf("%d", &data);
      push(&s1, data);
      printf("Pushed %d into stack", data);
      break;
    case 2:
      data = pop(&s1, &popped);
      if (data != -1)
      {
        printf("Popped element is %d \n", popped);
      }
      break;
    case 3:
      peek(&s1);
      break;
    case 4:
      display(&s1);
      break;
    case 5:
      sort(&s1);
      printf("Sorting\n");
      printf("Display to see results\n");
      break;
    case 6:
      printf("Exiting\n");
      break;
    default:
      printf("Invalid Choice\n");
      break;
    }
  } while (choice != 6);

  return 0;
}