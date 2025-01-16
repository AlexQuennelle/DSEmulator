#pragma once

#define ARM9 true;
#define ARM7 false;

#include <array>
#include <cstdint>

using byte = uint8_t;
using hword = uint16_t;
using word = uint32_t;

struct Memory
{
	char byte;
};

class Fifo
{
  private:
	std::array<word, 16> q1;
	std::array<word, 16> q2;

  public:
	word read(bool processor);
	void write(bool processor, word data);
};
