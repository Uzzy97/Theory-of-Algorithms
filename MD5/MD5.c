// Usman Sattar - G00345816
// https://tools.ietf.org/html/rfc1321

// Imports
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

// Constants For Md5 Transform Routine
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

//Pre-Defined Hash Values (Refer To Link: https://tools.ietf.org/html/rfc1321)
const uint32_t k[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
      };


// RORATE_LEFT rotates x left n bits.
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// F, G, H, I, are basic MD5 functions
#define F (x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))


// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
// Rotation is separate from addition to prevent recomputation.
#define FF(a, b, c, d, x, s, ac) { \
 (a) += F ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }

#define GG(a, b, c, d, x, s, ac) { \
 (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }

#define HH(a, b, c, d, x, s, ac) { \
 (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }

#define II(a, b, c, d, x, s, ac) { \
 (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }

// Reference: SHA256 Algorithm
// A sixty-four byte block of memory, accessed with different types.
union block {

  uint64_t sixfour[8];
  uint32_t threetwo[16];
  uint8_t eight [64];
};

enum flag {READ, PAD0, FINISH};

// Padding
static unsigned char PADDING[64] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };

// Next Block
int nextblock(union block *M, FILE *infile, uint64_t *nobits, enum flag *status){
  
  size_t nobytesread;

  if (*status == FINISH)
    return 0;

   int i;

   if (*status == PAD0) {
    for (i = 0; i < 56; i++)
      M ->eight[i] = 0x00;
    M->sixfour[7] = *nobits;
    *status = FINISH;
    
    return 1;
   }

   nobytesread = fread(M->eight, 1, 64, infile);
   
    if (nobytesread == 64)
      return 1;

    if (nobytesread == 56) {
      M-eight[nobytesread] = 0x80;
      for (int i = nobytesread + 1; i < 56; i++)
        M->eight[i] = 0;
      M->sixfour[7] = *nobits;
      *status = FINISH;

      return 1;
     }

     M->eight[nobytesread] = 0x80;
     for (int i = nobytesread + 1; i < 64; i++)
       M->eight[i] = 0;
     *status = PAD0;
     
     return 1;
   }


int main(int argc, char *argv[]) {

  if (argc != 2)
  {
    printf("Error: expected single filename as argument.\n");
    return 1;
  }

  FILE *infile = fopen(argv[1], "rb");
  if (!infile)
  {
    printf("Error: couldn't open file %s.\n", argv[1]);
    return 1;
  }

  uint32_t H[] = 
  {
    0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476
  };
  
  union block M;
  uint64_t nobits = 0;
  enum flag status = READ;

    // Read through all of the padded message blocks.
    while (nextblock(&M, infile, &nobits, &status)){

      md_hash(&M, H);
    }

 printf("\n Hash value of the file with MD5 algorithm\n");

// Print The Hash
 for (int i = 0; i < 4; i++)

  print("02" PRIX32 "", H[i]);

 printf("\n");

  fclose(infile);

  return 0;
}
