#ifndef UTILITAS_HPP
#define UTILITAS_HPP

#include <iostream>
#include <string>

// ANSI Escape Codes untuk warna teks
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

// Fungsi untuk menampilkan header ASCII "TO DO" dengan warna
void tampilkanHeader();

void clearScreen();
#endif // UTILITAS_HPP