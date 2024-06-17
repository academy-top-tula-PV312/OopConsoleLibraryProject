#include <iostream>
#include "Console.h"

int main()
{
    Console console;

    WindowConsole win(&console, 5, 10, 30, 10);
    win.IsBorder() = true;
    win.Style() = BorderStyle::Single;
    win.SetTitle("Hello world");

    win.Show();

    console.GetChar();

    WindowConsole win2(&console, 11, 20, 30, 10);
    win2.IsBorder() = true;
    win2.Style() = BorderStyle::Double;
    //win2.SetTitle("Hello world");

    win2.ColorBack() = Color::Red;
    win2.Show();

    console.GetChar();

    win2.Hide();

    console.GetChar();


    /*console.SetCursor(5, 10);
    console.Foreground(Color::Cyan);
    console.Write("Hello");*/

    /*console.SetCursor(6, 10);
    console.Background(Color::DarkMagenta);
    console.Write("Hello");

    console.SetCursor(7, 10);
    console.Foreground(Color::Yellow);
    console.Write("Hello");*/
}
