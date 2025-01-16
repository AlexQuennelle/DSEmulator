#pragma once

#define THIS true;

#include "cp15.h"
#include <cstdint>

using byte = uint8_t;
using hword = uint16_t;
using word = uint32_t;

class arm9
{
  public:
	word r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
	cp15 Coprocessor;

  private:
};
