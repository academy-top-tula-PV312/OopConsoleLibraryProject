#include "Console.h"

Console::Console()
{
	descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
}

Console::Console(int width, int height) : Console() {}

HANDLE& Console::Descriptor()
{
	return descriptor;
}

void Console::SetCursor(int row, int column)
{
	coordinate.X = column;
	coordinate.Y = row;
	SetConsoleCursorPosition(descriptor, coordinate);
}

void Console::Write(char symbol)
{
	std::cout << symbol;
}

void Console::Write(const char* cstr)
{
	std::cout << cstr;
}

void Console::Write(std::string str)
{
	std::cout << str;
}

void Console::Foreground(Color color)
{
	GetConsoleScreenBufferInfo(descriptor, &info);
	byte colorBack = info.wAttributes & (0b1111 << 4);
	byte colorFore = (byte)color;
	SetConsoleTextAttribute(descriptor, colorBack | colorFore);
}

void Console::Background(Color color)
{
	GetConsoleScreenBufferInfo(descriptor, &info);
	byte colorFore = info.wAttributes & 0b1111;
	byte colorBack = (byte)color << 4;
	SetConsoleTextAttribute(descriptor, colorBack | colorFore);
}
