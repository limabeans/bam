#include <stdio.h>
#include <stdint.h>
// #include "registers.h"

int main() {
  uint32_t *reg_arr;
  init_regs(&reg_arr);
  print_regs(reg_arr);
  return 0;
}
