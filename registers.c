#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int init_regs(uint32_t **registers) {
  *registers = (uint32_t*) malloc(sizeof(uint32_t) * 32);
  (*registers)[0] = 0; // $zero must be initialized to 0
  if (*registers == NULL) return 1;
  else return 0;
}

void print_regs(uint32_t *registers) {
  int i;
  for ( i = 0; i < 32; i++) {
    if (i == 0) {
      printf("$zero = %d ", registers[i]);
    } else if (i == 1) {
      printf("$at = %d\n", registers[i]);
    } else if (i == 2) {
      printf("$v0 = %d ", registers[i]);
    } else if (i == 3) {
      printf("$v1 = %d ", registers[i]);
    } else if (i == 4) {
      printf("$a0 = %d ", registers[i]);
    } else if (i == 5) {
      printf("$a1 = %d ", registers[i]);
    } else if (i == 6) {
      printf("$a2 = %d ", registers[i]);
    } else if (i == 7) {
      printf("$a3 = %d\n", registers[i]);
    } else if (i == 8) {
      printf("$t0 = %d ", registers[i]);
    } else if (i == 9) {
      printf("$t1 = %d ", registers[i]);
    } else if (i == 10) {
      printf("$t2 = %d ", registers[i]);
    } else if (i == 11) {
      printf("$t3 = %d ", registers[i]);
    } else if (i == 12) {
      printf("$t4 = %d ", registers[i]);
    } else if (i == 13) {
      printf("$t5 = %d ", registers[i]);
    } else if (i == 14) {
      printf("$t6 = %d ", registers[i]);
    } else if (i == 15) {
      printf("$t7 = %d\n", registers[i]);
    } else if (i == 16) {
      printf("$s0 = %d ", registers[i]);
    } else if (i == 17) {
      printf("$s1 = %d ", registers[i]);
    } else if (i == 18) {
      printf("$s2 = %d ", registers[i]);
    } else if (i == 19) {
      printf("$s3 = %d ", registers[i]);
    } else if (i == 20) {
      printf("$s4 = %d ", registers[i]);
    } else if (i == 21) {
      printf("$s5 = %d ", registers[i]);
    } else if (i == 22) {
      printf("$s6 = %d ", registers[i]);
    } else if (i == 23) {
      printf("$s7 = %d\n", registers[i]);
    } else if (i == 24) {
      printf("$t8 = %d ", registers[i]);
    } else if (i == 25) {
      printf("$t9 = %d\n", registers[i]);
    } else if (i == 26) {
      printf("$k0 = %d ", registers[i]);
    } else if (i == 27) {
      printf("$k1 = %d\n", registers[i]);
    } else if (i == 28) {
      printf("$gp = %d ", registers[i]);
    } else if (i == 29) {
      printf("$sp = %d ", registers[i]);
    } else if (i == 30) {
      printf("$fp = %d ", registers[i]);
    } else if (i == 31) {
      printf("$ra = %d\n", registers[i]);
    }
  }
}

