#include <register.h>

Register::Register() : Register(0) {}

Register::Register(size_t N) : SIZE(N > 0 ? N : UINT16_MAX), Index(0), Reg(new uint8_t [N])
{
	for (int i = 0; i < SIZE; i++) {
		Reg[i] = 0x00;
	}
}

Register::~Register(){ delete[] Reg; }

void Register::shiftLeft()
{
	Index = Index == 0 ? SIZE - 1 : Index - 1; //Decrements index, wraps to the last byte if Index is 0
}

void Register::shiftRight()
{
	Index = Index == SIZE - 1 ? 0 : Index + 1; //Increments index, wraps to 0 if index is already on the last byte
}

uint8_t Register::getVal(){	return Reg[Index]; }

void Register::setVal(uint8_t val) { Reg[Index] = val; }

size_t Register::getIndex() { return Index; }

void Register::increment() { Reg[Index] =	Reg[Index] != 255 ? Reg[Index] + 1 : 0; } // Increments value at Index, ensures overflow doesn't cause out of bounds

void Register::decrement() { Reg[Index] = Reg[Index] != 0 ? Reg[Index] -1 : 255; } // Decrements value at Index, ensures overflow doesn't cause out of bounds

void Register::DumpContents()
{
	for (int i = 0; i < SIZE; i++) {
		std::cout << (int)(Reg[i]) << ", ";
	}
}
