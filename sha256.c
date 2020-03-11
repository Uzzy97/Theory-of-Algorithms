// Usman Sattar
// https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
// The secure hash algorithm 256-bit verion.
#include <stdio.h>
#include <stdint.h>

uint32_t Ch(uint32_t x, uint32_t y, uint32_t z){
  // Section 4.1.2
  return (x & y) ^ (!x & z);
}


int main(int argc, char *argv[]){

  // hexadecimal literal
  uint32_t x = 0x0f0f0f0f;
  uint32_t y = 0xcccccccc;
  uint32_t z = 0x55555555;
 
  printf("x          = %08x\n", x);
  printf("y          = %08x\n", y);
  printf("z          = %08x\n", z);

  printf("Ch (x,y,z) = %08x\n", Ch(x, y, z));

  return 0;
}
