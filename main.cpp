#include <TODO.hpp>
#include <windows.h>

void setColor(int color);
void menu();

int main(){
    menu();
    return 0;
}

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE),color);
}

void menu(){
    system("cls");
    int pilihan;
    cout<<"\n===>>> TO-DO LIST <<<===\n";
    setColor(4);
    cout<<"1. Tampilkan Tugas\n";
    cout<<"2. Tambah Tugas\n";
    cout<<"3. Hapus Tugas\n";
    cout<<"4. Edit tugas\n";
    cout<<"5. Ubah status\n";
    cout<<"6. Cari Tugas\n";
    cout<<"7. Filter Tugas\n";
    cout<<"8. Keluar\n";
    cout<<"Pilih menu: ";
    setColor(7);
    cin>>pilihan;

    switch (pilihan)
    {
    case 1:
        tampilkan_tugas();
        break;
    case 2:
        tambah_tugas();
        break;
    case 3:
        hapus_tugas();
        break;
    case 8:
        cout<<"Keluar dari program...\n";
        break;
    case 4:
        edit_tugas();
        break;
    case 5:
        tandai_selesai();
        break;
    case 6:
        cari_tugas();
        break;
    case 7:
        filter_tugas();
        break;
    default:
        cout<<"Pilihan tidak valid, coba lagi.\n";
        break;
    }
}