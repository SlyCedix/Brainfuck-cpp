#pragma once
#ifndef REGISTER_H
#include <iostream>
class Register {
	public:
		Register();
		Register(size_t);
		~Register();

		void shiftLeft();
		void shiftRight();

		uint8_t getVal();
		void setVal(uint8_t);

		size_t getIndex();

		void increment();
		void decrement();

		void DumpContents();
	private:
		const size_t SIZE;
		size_t Index;
		uint8_t * Reg;
};
#endif