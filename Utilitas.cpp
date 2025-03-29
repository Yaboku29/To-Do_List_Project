#include "Utilitas.hpp"

using namespace std;

void tampilkanHeader(){
    cout<<CYAN<<BOLD;
    cout << "████████╗ ██████╗     ██████╗  ██████╗ \n";
    cout << "╚══██╔══╝██╔═══██╗    ██╔══██╗██╔═══██╗\n";
    cout << "   ██║   ██║   ██║    ██║  ██║██║   ██║\n";
    cout << "   ██║   ██║   ██║    ██║  ██║██║   ██║\n";
    cout << "   ██║   ╚██████╔╝    ██████╔╝╚██████╔╝\n";
    cout << "   ╚═╝    ╚═════╝     ╚═════╝  ╚═════╝ \n";
    cout << RESET << endl;  // Kembali ke warna default
}

void clearScreen(){
    cout<<"\033[2J";
    cout<<"\033[1;1H";
    tampilkanHeader();
}