#pragma once
#include <iostream>
#include <Windows.h>

enum Color
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	Gray,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White
};

class Console
{
	HANDLE descriptor;
	COORD coordinate;
	CONSOLE_SCREEN_BUFFER_INFO info;
public:
	Console();
	Console(int width, int height);

	HANDLE& Descriptor();

	void SetCursor(int row, int column);

	void Write(char symbol);
	void Write(const char* cstr);
	void Write(std::string str);

	void Foreground(Color color);
	void Background(Color color);

	void WritePosition(int row, int column, char symbol);
	void WritePosition(int row, int column, const char* cstr);
	void WritePosition(int row, int column, std::string str);

	void WritePositionWidth(int row, int column, char symbol);
	void WritePositionWidth(int row, int column, const char* cstr);
	void WritePositionWidth(int row, int column, std::string str);

	void WriteColor(char symbol, Color back, Color fore);
	void WriteColor(const char* cstr, Color back, Color fore);
	void WriteColor(std::string str, Color back, Color fore);
};

