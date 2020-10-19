//
// Created by YunfanLu on 2020/2/15.
//
#include <string.h>

#include "bit.h"


int bit_get(const unsigned char *bits, int pos) {
  unsigned char mask;
  int i;

  /* Set a mask for the bit to get. */

  // 0x80 is 1000,0000b
  mask = 0x80;

  for (i = 0; i < (pos % 8); i++) {
    mask >>= 1;
  }

  return ((mask & bits[(int)(pos / 8)]) == mask) ? 1 : 0;
}

void bit_set(unsigned char *bits, int pos, int state) {
  unsigned char mask;
  int i;

  mask = 0x80;

  for (i = 0; i < (pos % 8); i++) {
    mask >>= 1;
  }

  if (state == 1) {
    bits[pos / 8] = bits[pos / 8] | mask;
  } else {
    bits[pos / 8] = bits[pos / 8] & (~mask);
  }
  return;
}

void bit_xor(const unsigned char *bits1, const unsigned char *bits2,
             unsigned char *bitsx, int size) {
  int i;

  for (i = 0; i < size; i++) {
    bit_set(bitsx, i, bit_get(bits1, i) ^ (bit_get(bits2, i)));
  }
  return;
}

void bit_rot_left(unsigned char *bits, int size, int count) {
  int fbit, lbit, i, j;

  if (size > 0) {
    for (j = 0; j < count; j++) {
      // 这里要 -1 是因为防止，当 size 为 8 的整数倍数时，多一格的情况。例如当
      // size 为 64 时，实际的下标是 0 到 7。
      for (i = 0; i < ((size - 1) / 8); i++) {
        lbit = bit_get(&bits[i], 0);

        if (i == 0) {
          fbit = lbit;
        } else {
          bit_set(&bits[i - 1], 7, lbit);
        }
        bits[i] <<= 1;
      }
      bit_set(bits, size - 1, fbit);
    }
  }
}
