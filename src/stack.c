#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * @brief Stack's structure.
 */
typedef struct stack_t {
  int max;
  int top;
  char *items;
} stack_t;

/**
 * @brief Create a stack.
 */
stack_t
stack_create(int max)
{
  stack_t stack;
  stack.max = max;
  stack.top = -1;
  stack.items = malloc(sizeof(char) * max);

  return stack;
}

/**
 * @brief Destroy the stack.
 */
void
stack_destroy(stack_t* stack)
{
  free(stack->items);
}

/**
 * @brief Get top item from stack.
 */
char
stack_top(stack_t* stack)
{
  if (stack_is_empty(stack))
  {
    fprintf(stderr, "Can't get top item from an empty stack \n");
    exit(1);
  }

  return (stack->items[stack->top]);
}

/**
 * @brief Push a new item into the stack.
 */
void
stack_push(stack_t* stack, char item)
{
  if (stack_is_full(stack))
  {
    fprintf(stderr, "Can't push item into a full stack \n");
    exit(1);
  }

  stack->items[++stack->top] = item;
}

/**
 * @brief Pop the last item from the stack.
 */
char
stack_pop(stack_t* stack)
{
  if (stack_is_empty(stack))
  {
    fprintf(stderr, "Can't pop item from an empty stack \n");
    exit(1);
  }

  char top = stack_top(stack);
  stack->top--;
  return top;
}

/**
 * @brief Check if stack is full.
 */
int
stack_is_full(stack_t* stack)
{
  return (stack->top == (stack->max - 1));
}

/**
 * @brief Check if stack is empty.
 */
int
stack_is_empty(stack_t* stack)
{
  return (stack->top == -1);
}
