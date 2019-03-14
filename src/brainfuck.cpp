#include <brainfuck.h>

Brainfuck::Brainfuck() : Brainfuck("", 0, false){}

Brainfuck::Brainfuck(std::string str, size_t N, bool D) : BF (str), Pos(0), Dump(D){
		Reg = new Register(N);
}

Brainfuck::~Brainfuck(){ delete Reg; }

void Brainfuck::Run()
{
	while (Pos != BF.length()) {
		Step();
	}
	if(Dump) DumpRegister();
}

bool Brainfuck::Step()
{
	return Step(0);
}

bool Brainfuck::Step(size_t LoopIndex)
{
	char comm = GetCurrentCommand();
	Pos++;
	switch (comm) {
		case '+':
			Reg->increment();
			break;
		case '-':
			Reg->decrement();
			break;
		case '<':
			Reg->shiftLeft();
			break;
		case '>':
			Reg->shiftRight();
			break;
		case '.':
			std::cout << Reg->getVal();
			break;
		case ',':
			char in;
			std::cin >> in;
			Reg->setVal(in);
			break;
		case '[':
			if (Reg->getVal() != 0) 
				Loop(Pos);
			else 
				SkipLoop();
			break;
		case ']':
			if (Reg->getVal() != 0) {
				Pos = LoopIndex;
				return true;
			}
			else {
				return false;
			}
			break;
		default:
			break;
	}
	//std::cout << Pos << ": " << (int)Reg->getVal() << " @ " << Reg->getIndex() << '\n';
	return true;
}

void Brainfuck::Loop(size_t LoopIndex)
{
	while (Step(LoopIndex) == true);
}

void Brainfuck::SkipLoop()
{
	size_t braces = 1;
	while (braces != 0) {
		if (GetCurrentCommand() == '[') {
			braces++;
		}
		else if (GetCurrentCommand() == ']') {
			braces--;
		}
		Pos++;
	}
}

char Brainfuck::GetCurrentCommand(){ return BF.at(Pos); }

void Brainfuck::DumpRegister()
{
	Reg->DumpContents();
}
