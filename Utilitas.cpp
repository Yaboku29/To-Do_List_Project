#include "Utilitas.hpp"

using namespace std;

void tampilkanHeader(){
    cout<<CYAN<<BOLD;
    cout << R"(  
         _________    _____    ______     _____
        |___   ___|  /     \  |      \   /     \
            | |     |  ___  | |  ___  | |  ___  |
            | |     | |   | | | |   | | | |   | |
            | |     | |   | | | |   | | | |   | |
            | |     | |___| | | |___| | | |___| |
            |_|      \_____/  |______/   \_____/ 
          Made by:
          )";
    cout<<RED<<"Yaboku29";
    
    
    cout << RESET << endl;  // Kembali ke warna default
}

void clearScreen(){
    cout<<"\033[2J";
    cout<<"\033[1;1H";
    tampilkanHeader();
}