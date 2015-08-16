#include <stdio.h>
#include <stdint.h>

#define RAM 100


int main() {
  uint32_t *reg_arr;
  init_regs(&reg_arr);
  print_regs(reg_arr);
  uint8_t *ram;
  init_ram(&ram, RAM); 
  print_ram(ram, RAM);

  return 0;
}
