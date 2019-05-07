#ifndef __STACK_H__
#define __STACK_H__

  /**
   * @brief Stack's structure.
   */
  typedef struct stack_t {
    int max;
    int top;
    char items[15];
  } stack_t;

  /**
   * @brief Create a stack.
   */
  stack_t
  stack_create(int max);

  /**
   * @brief Get top item from stack.
   */
  char
  stack_top(stack_t* stack);

  /**
   * @brief Push a new item into the stack.
   */
  void
  stack_push(stack_t* stack, char item);

  /**
   * @brief Pop the last item from the stack.
   */
  char
  stack_pop(stack_t* stack);

  /**
   * @brief Check if stack is full.
   */
  int
  stack_is_full(stack_t* stack);

  /**
   * @brief Check if stack is empty.
   */
  int
  stack_is_empty(stack_t* stack);

#endif
