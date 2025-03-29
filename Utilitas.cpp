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
            | |     |       | |       | |       |
            |_|      \_____/  |______/   \_____/ 
        
         __          __    ________   _________ 
        |  |        |  |  /  ______| |___   ___|         
        |  |        |  |  \  \____       | |
        |  |        |  |   \___   \      | |
        |  |        |  |       \   |     | |
        |  |        |  |  _    /   /     | | 
        |  |______  |  | | |__/   /      | |
        |_________| |__| |_______/       |_|

          Made by:
          )";
    cout<<RED<<"Yaboku29 & GPT(100%)";
    
    
    cout << RESET << endl;  // Kembali ke warna default
}

void clearScreen(){
    cout<<"\033[2J";
    cout<<"\033[1;1H";
    tampilkanHeader();
}