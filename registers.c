#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int init_regs(uint32_t **registers) {
  *registers = (uint32_t*) malloc(sizeof(uint32_t) * 32);
  (*registers)[0] = 0; // $zero must be initialized to 0
  // check to make sure malloc succeeded
  if (*registers == NULL) return 1;
  else return 0;
}


// initialize RAM, size in bytes
int init_ram(uint8_t **mem, uint32_t size) {
  if (size%4 != 0) {
    fprintf(stderr, "size must be word aligned.\n");
    return 1;
  } else {
    *mem = (uint8_t*) malloc(sizeof(uint32_t) * size);
    // check to make sure malloc succeeded
    if (*mem == NULL) return 1;
    else return 0;
  }
}


void print_ram(uint8_t *ram, uint32_t size) {
  int i;
  printf("addr | data\n");
  for (i = 0; i < size; i+=4) {
    printf("%4d | 0x%x%x%x%x\n", i, ram[i], ram[i+1], ram[i+2], ram[i+3]);
  }
}



void print_regs(uint32_t *regs) {
  printf("REGISTERS\n");
  printf("=====================================================\n");
  printf("| $t0 = %d | $s0 = %d | $v0 = %d | $gp   = %d | $k0 = %d |\n", 
         regs[8], regs[16], regs[2], regs[28], regs[26]);
  printf("| $t1 = %d | $s1 = %d | $v1 = %d | $sp   = %d | $k1 = %d |\n", 
         regs[9], regs[17], regs[3], regs[29], regs[27]);
  printf("| $t2 = %d | $s2 = %d | $a0 = %d | $fp   = %d |\n",
         regs[10], regs[18], regs[4], regs[30]);
  printf("| $t3 = %d | $s3 = %d | $a1 = %d | $ra   = %d |\n",
         regs[11], regs[19], regs[5], regs[31]);
  printf("| $t4 = %d | $s4 = %d | $a2 = %d | $at   = %d |\n",
         regs[12], regs[20], regs[6], regs[1]);
  printf("| $t5 = %d | $s5 = %d | $a3 = %d | $zero = %d |\n",
         regs[13], regs[21], regs[7], regs[0]);
  printf("| $t6 = %d | $s6 = %d |\n",
         regs[14], regs[22]);
  printf("| $t7 = %d | $s7 = %d |\n",
         regs[15], regs[23]);
  printf("| $t8 = %d |\n", regs[24]);
  printf("| $t9 = %d |\n", regs[25]);
  printf("=====================================================\n");
}


/* void print_regs(uint32_t *registers) { */
/*   printf("REGISTERS\n"); */
/*   printf("=========\n"); */
/*   int i; */
/*   for ( i = 0; i < 32; i++) { */
/*     if (i == 0) { */
/*       printf("$zero = %d ", registers[i]); */
/*     } else if (i == 1) { */
/*       printf("$at = %d\n", registers[i]); */
/*     } else if (i == 2) { */
/*       printf("$v0 = %d ", registers[i]); */
/*     } else if (i == 3) { */
/*       printf("$v1 = %d ", registers[i]); */
/*     } else if (i == 4) { */
/*       printf("$a0 = %d ", registers[i]); */
/*     } else if (i == 5) { */
/*       printf("$a1 = %d ", registers[i]); */
/*     } else if (i == 6) { */
/*       printf("$a2 = %d ", registers[i]); */
/*     } else if (i == 7) { */
/*       printf("$a3 = %d\n", registers[i]); */
/*     } else if (i == 8) { */
/*       printf("$t0 = %d ", registers[i]); */
/*     } else if (i == 9) { */
/*       printf("$t1 = %d ", registers[i]); */
/*     } else if (i == 10) { */
/*       printf("$t2 = %d ", registers[i]); */
/*     } else if (i == 11) { */
/*       printf("$t3 = %d ", registers[i]); */
/*     } else if (i == 12) { */
/*       printf("$t4 = %d ", registers[i]); */
/*     } else if (i == 13) { */
/*       printf("$t5 = %d ", registers[i]); */
/*     } else if (i == 14) { */
/*       printf("$t6 = %d ", registers[i]); */
/*     } else if (i == 15) { */
/*       printf("$t7 = %d\n", registers[i]); */
/*     } else if (i == 16) { */
/*       printf("$s0 = %d ", registers[i]); */
/*     } else if (i == 17) { */
/*       printf("$s1 = %d ", registers[i]); */
/*     } else if (i == 18) { */
/*       printf("$s2 = %d ", registers[i]); */
/*     } else if (i == 19) { */
/*       printf("$s3 = %d ", registers[i]); */
/*     } else if (i == 20) { */
/*       printf("$s4 = %d ", registers[i]); */
/*     } else if (i == 21) { */
/*       printf("$s5 = %d ", registers[i]); */
/*     } else if (i == 22) { */
/*       printf("$s6 = %d ", registers[i]); */
/*     } else if (i == 23) { */
/*       printf("$s7 = %d\n", registers[i]); */
/*     } else if (i == 24) { */
/*       printf("$t8 = %d ", registers[i]); */
/*     } else if (i == 25) { */
/*       printf("$t9 = %d\n", registers[i]); */
/*     } else if (i == 26) { */
/*       printf("$k0 = %d ", registers[i]); */
/*     } else if (i == 27) { */
/*       printf("$k1 = %d\n", registers[i]); */
/*     } else if (i == 28) { */
/*       printf("$gp = %d ", registers[i]); */
/*     } else if (i == 29) { */
/*       printf("$sp = %d ", registers[i]); */
/*     } else if (i == 30) { */
/*       printf("$fp = %d ", registers[i]); */
/*     } else if (i == 31) { */
/*       printf("$ra = %d\n", registers[i]); */
/*     } */
/*   } */
/* } */

