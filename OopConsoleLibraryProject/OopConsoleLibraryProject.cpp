#include <iostream>
#include "Console.h"

int main()
{
    Console console;
    console.SetCursor(5, 10);
    console.Foreground(Color::Cyan);
    console.Write("Hello");

    console.SetCursor(6, 10);
    console.Background(Color::DarkMagenta);
    console.Write("Hello");

    console.SetCursor(7, 10);
    console.Foreground(Color::Yellow);
    console.Write("Hello");
}
