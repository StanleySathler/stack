#include <stdio.h>
#include "../lib/assert.h"
#include "../src/stack.h"

void
test_stack_create()
{
  stack_t stack = stack_create(5);
  assert_int(5, stack.max, "Should set the correct max");
  assert_int(-1, stack.top, "Should set the correct initial top");
}

int
main()
{
  test_stack_create();
  return(0);
}
