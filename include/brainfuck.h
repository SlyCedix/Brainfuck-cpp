#pragma once
#ifndef BRAINFUCK_H
#include <string>
#include <register.h>
class Brainfuck {
	public:
		Brainfuck();
		Brainfuck(std::string, size_t, bool);
		~Brainfuck();

		void Run();
		bool Step();
		bool Step(size_t);
		
		void Loop(size_t);
		void SkipLoop();

		char GetCurrentCommand();

		void DumpRegister();
	private:
		Register *Reg;
		const std::string BF;
		size_t Pos;
		bool Dump;
};
#endif