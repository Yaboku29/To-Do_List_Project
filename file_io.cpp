#include "file_io.hpp"
#include "Utilitas.hpp"
#include <fstream>
#include <sstream>
using json=nlohmann::json;

string trim(const string& str){
    size_t first=str.find_first_not_of(" \t\n\r");
    size_t last=str.find_last_not_of(" \t\n\r");
    return (first==string::npos) ? "" : str.substr(first,(last-first+1));
}

string cleanString(const string& str){
    return regex_replace(str,regex(R"(\\\")"),"\"");
}

void eksporData(){
    json data=bacaData();
    clearScreen();
    if(data.empty()){
        cout<<"Tidak ada data untuk diekspor!\n";
        return;
    }
    int pilihan;
    string filename;

    cout<<"Pilih format ekspor:\n";
    cout<<"1. .txt (Teks biasa)\n";
    cout<<"2. .csv (Bisa dibuka di Excel)\n";
    cout<<"Pilihan: ";
    cin>>pilihan;
    cin.ignore();
    cout<<"Masukkan nama file: ";
    getline(cin,filename);
    if(pilihan<1||pilihan>2){
        cout<<"Input invalid\n";
        return;
    }
    ofstream jsonFile(filename+".json",ios::trunc);
    if(!jsonFile.is_open()){
        cout<<"Gagal membuka file JSON!\n";
        return;
    }
    jsonFile<<data.dump(4);
    jsonFile.close();

    if(pilihan==1) filename+=".txt";
    else filename+=".csv";
    ofstream file(filename);
    if(!file.is_open()){
        cout<<"Gagal membuka file!\n";
        return;
    }
    if(pilihan==1){
        for(const auto& tugas : data){
            file<<tugas["deskripsi"]<<" | "
                <<tugas["deadline"]<<" | "
                <<tugas["prioritas"]<<" | "
                <<tugas["status"]<<"\n";
        }
    }
    else {
        file <<"Deskripsi, Deadline, Prioritas, Status\n";
        for(const auto& tugas : data){
            file<<"\""<<tugas["deskripsi"]<<"\","
                <<"\""<<tugas["deadline"]<<"\","
                <<"\""<<tugas["prioritas"]<<"\","
                <<"\""<<tugas["status"]<<"\"\n";
        }
    }
    file.close();
    cout<<"Data berhasil diekspor ke "<<filename<<"!\n";
}
void imporData(){
    string filename;
    cout<<"Masukkan nama file yang ingin diimpor (tanpa ekstensi): ";
    cin.ignore();
    getline(cin,filename);
    filename+=".json";
    ifstream file(filename);
    if(!file.is_open()){
        cout<<"Gagal membuka file!\n Pastikan nama dan ekstensi benar!\n";
        return;
    }

    json data;

    file>>data;
    file.close();

    ofstream outFile("todolist.json");
    if(!outFile.is_open()){
        cout<<"Gagal menyimpan data ke JSON!\n";
        return;
    }
    outFile<<data.dump(4);
    outFile.close();

    cout<<"Data berhasil diimpor dan disimpan!\n";
    //simpanData(data);
}