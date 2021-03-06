#include <stdio.h>
#include "../libs/assert.h"
#include "../src/stack.h"

void
test_stack_create()
{
  stack_t stack = stack_create(5);
  assert_int(5, stack.max, "[stack_create]: Should set the correct max");
  assert_int(-1, stack.top, "[stack_create]: Should set the correct initial top");
}

void
test_stack_push()
{
  stack_t stack = stack_create(2);

  stack_push(&stack, 2);
  assert_int(0, stack.top, "[stack_push]: Should increase the top to 0");

  stack_push(&stack, 3);
  assert_int(1, stack.top, "[stack_push]: Should increase the top to 1");
}

void
test_stack_top()
{
  stack_t stack = stack_create(2);

  stack_push(&stack, 'a');
  assert_char('a', stack_top(&stack), "[stack_top]: Should return the correct top item");

  stack_push(&stack, 'c');
  assert_char('c', stack_top(&stack), "[stack_top]: Should return the correct top item");
}

void
test_stack_pop()
{
  stack_t stack = stack_create(2);

  stack_push(&stack, 'a');
  assert_char('a', stack_pop(&stack), "[stack_pop]: Should return the correct top item");
  assert_int(-1, stack.top, "[stack_pop]: Should decrease the top to 0");

  stack_push(&stack, 'c');
  stack_push(&stack, 'a');
  assert_int('a', stack_pop(&stack), "[stack_pop]: Should return the correct top item");
  assert_int(0, stack.top, "[stack_pop]: Should decrease the top to 1");
}

int
main()
{
  test_stack_create();
  test_stack_push();
  test_stack_top();
  test_stack_pop();
  return(0);
}
