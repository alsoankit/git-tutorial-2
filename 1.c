#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the stack

// Structure to represent a stack
struct Stack
{
  int arr[MAX]; // Array to hold stack elements
  int top;      // Index of the top element
};

// Function to initialize the stack
void initializeStack(struct Stack *stack)
{
  stack->top = -1; // Set top to -1 indicating the stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
  return stack->top == MAX - 1; // Stack is full if top is at MAX-1
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
  return stack->top == -1; // Stack is empty if top is -1
}

// Function to add an element to the stack (push)
void push(struct Stack *stack, int value)
{
  if (isFull(stack))
  {
    printf("Stack Overflow! Cannot push %d\n", value);
    return;
  }
  stack->arr[++(stack->top)] = value; // Increment top and add value
  printf("Pushed %d onto stack\n", value);
}

// Function to remove and return the top element from the stack (pop)
int pop(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack Underflow! Cannot pop\n");
    return -1; // Return -1 if the stack is empty
  }
  return stack->arr[(stack->top)--]; // Return the top element and decrement top
}

// Function to return the top element without removing it (peek)
int peek(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty! Cannot peek\n");
    return -1; // Return -1 if the stack is empty
  }
  return stack->arr[stack->top]; // Return the top element
}

// Function to display the stack elements
void display(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements are: ");
  for (int i = 0; i <= stack->top; i++)
  {
    printf("%d ", stack->arr[i]);
  }
  printf("\n");
}

// Main function to demonstrate the stack
int main()
{
  struct Stack stack;      // Declare a stack variable
  initializeStack(&stack); // Initialize the stack

  // Push elements onto the stack
  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);
  push(&stack, 40);
  push(&stack, 50);
  push(&stack, 60); // This will trigger stack overflow

  // Display the stack contents
  display(&stack);

  // Peek the top element
  printf("Peek: %d\n", peek(&stack));

  // Pop elements from the stack
  printf("Popped %d from stack\n", pop(&stack));
  printf("Popped %d from stack\n", pop(&stack));

  // Display the stack contents after popping
  display(&stack);

  return 0;
}
