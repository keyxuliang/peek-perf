#include <stdio.h>
#include <stdlib.h>

int main() {
  float rslt[16];

  asm volatile (
    "  mov $0xF0000000, %%rax\n"
    ".LOOP: \n"
    "  vfmadd132ps %%zmm0, %%zmm0, %%zmm1 \n"
    "  vfmadd132ps %%zmm1, %%zmm1, %%zmm2 \n"
    "  vfmadd132ps %%zmm2, %%zmm2, %%zmm3 \n"
    "  vfmadd132ps %%zmm3, %%zmm3, %%zmm4 \n"
    "  vfmadd132ps %%zmm4, %%zmm4, %%zmm5 \n"
    "  vfmadd132ps %%zmm5, %%zmm5, %%zmm6 \n"
    "  vfmadd132ps %%zmm7, %%zmm7, %%zmm8 \n"
    "  vfmadd132ps %%zmm8, %%zmm8, %%zmm9 \n"
    "  vfmadd132ps %%zmm9, %%zmm9, %%zmm0 \n"
    "  sub $0x1, %%rax \n"
    "  jne .LOOP \n"
    "  vmovaps (%0), %%zmm0 \n"
    "  ret"
    : "=r" (rslt)
  );

  return 0;
}
