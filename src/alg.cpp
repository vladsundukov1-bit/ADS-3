// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxvalue = num;
  while (num > 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxvalue) {
            maxvalue = num;
        }
    }
  return maxvalue;
}

unsigned int collatzLen(uint64_t num) {
   unsigned int lenn = 1;
   while (num > 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        lenn++;
    }
   return lenn;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int bestnum = lbound;
  *maxlen = 0;
    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int curlen = collatzLen(num);
        if (curlen > *maxlen) {
            *maxlen = curlen; 
            bestnum = num;
        }
    }
    return bestnum;
}
