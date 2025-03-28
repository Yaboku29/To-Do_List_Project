#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json.hpp"

using json=nlohmann::json;
using namespace std;
const string FILE_NAME="todolist_sederhana.json";

void tampilkan_tugas();
void menu();
void tambah_tugas();
void hapus_tugas();
void edit_tugas();
json bacaData();
void simpanData(const json& data);
void tandai_selesai();
void cari_tugas();
void filter_tugas();

int main(){
    menu();
    return 0;   
}

json bacaData() {
    ifstream file(FILE_NAME);
    json data;

    if (!file) {
        cout << "⚠ File JSON tidak ditemukan, membuat file baru...\n";
        ofstream newFile(FILE_NAME);
        newFile << "[]"; // Isi awal agar JSON valid
        newFile.close();
        return json::array();
    }

    try {
        file >> data;
    } catch (json::parse_error& e) {
        cout << "⚠ ERROR: Gagal membaca JSON! " << e.what() << endl;
        return json::array();
    }

    file.close();
    return data;
}

void simpanData(const json& data) {
    ofstream file(FILE_NAME);

    if (!file) {
        cout << "⚠ ERROR: Tidak bisa membuka file JSON untuk ditulis!\n";
        return;
    }

    file << data.dump(4); // Simpan dalam format rapi
    file.close();
}


void tampilkan_tugas(){
    system("cls");
    json data=bacaData();
    if(data.empty()){
        cout<<"Belum ada tugas.\n";
        system("pause");
        menu();
    }
    
    int nomor=1;
    cout<<"\n=== Daftar To_Do List ===\n";
    for(const auto& tugas : data){
        cout<<nomor++<<". "<<tugas["deskripsi"]
        <<" | "<<tugas["deadline"]
        <<" | "<<tugas["prioritas"]
        <<" | "<<tugas["status"]<<endl;

    }
    system("pause");
    menu();
}

void tambah_tugas() {
    system("cls");
    json data = bacaData();

    //cout << "Isi JSON sebelum menambah tugas: " << data.dump(4) << endl; // Debug

    // HAPUS PENGECEKAN data.empty() karena JSON kosong itu bukan kesalahan
    // if (data.empty()) {
    //     cout << "⚠ Gagal membuka file atau file kosong!\n";
    //     system("pause");
    //     menu();
    // }

    string tugas, deadline, prioritas;
    cout << "Masukkan tugas baru: ";
    cin.ignore();
    getline(cin, tugas);
    cout << "Masukkan deadline baru (YYYY-MM-DD): ";
    getline(cin, deadline);
    cout << "Masukkan prioritas baru (Tinggi/Sedang/Rendah): ";
    getline(cin, prioritas);

    json tugasBaru = {
        {"deskripsi", tugas},
        {"deadline", deadline},
        {"prioritas", prioritas},
        {"status","Belum Selesai"}
    };
    data.push_back(tugasBaru);
    simpanData(data);

    cout << "Tugas berhasil ditambahkan!\n";
    system("pause");
    menu();
}

void hapus_tugas(){
    system("cls");
    json data=bacaData();
    if(data.empty()){
        cout<<"belum ada tugas untuk dihapus.\n";
        system("pause");
        menu();
    }


    //tampilkan_tugas();
    int nomor=1;
    cout<<"\n=== Daftar To_Do List ===\n";
    for(const auto& tugas : data){
        cout<<nomor++<<". "
        <<tugas["deskripsi"]
        <<" | "<<tugas["deadline"]
        <<" | "<<tugas["prioritas"]
        <<" | "<<tugas["status"]<<endl;
    }

    //=========
    int nomor1;
    cout<<"Masukkan nomor tugas yang ingin dihapus: ";
    cin>>nomor1;
    cin.ignore();
    if(nomor1<0||nomor1>data.size()){
        cout<<"Nomor tugas tidak valid\n";
        system("pause");
        menu();
    }

    data.erase(data.begin()+nomor1-1);
    simpanData(data);
    cout<<"Tugas berhasil dihapus!\n";
    system("pause");
    menu();
}

void edit_tugas(){
    system("cls");
    json data=bacaData();
    if(data.empty()){
        cout<<"Belum ada tugas untuk diedit\n";
        system("pause");
        menu();
    }
    //=======
    int nomor=1;
    cout<<"\n=== Daftar To_Do List ===\n";
    for(const auto& tugas : data){
        cout<<nomor++<<". "<<tugas["deskripsi"]<<" | "<<tugas["deadline"]<<" | "<<tugas["prioritas"]<<endl;
    }
    //=======
    int nomor1;
    cout<<"Masukkan nomor tugas yang ingin diedit: ";
    cin>>nomor1;
    cin.ignore();
    if(nomor1<1||nomor1>data.size()){
        cout<<"Nomor tugas tidak valid!\n";
        system("pause");
        menu();
    }

    cout<<"\nTugas saat ini: \n";
    cout<<"Deskripsi: "<<data[nomor1-1]["deskripsi"]<<endl;
    cout<<"Deadline: "<<data[nomor1-1]["deadline"]<<endl;
    cout<<"Prioritas: "<<data[nomor1-1]["prioritas"]<<endl;
    string tugasBaru,deadlineBaru,prioritasBaru;
    cout<<"Masukkan tugas baru: ";
    getline(cin,tugasBaru);
    cout<<"Masukkan deadline baru (YYYY-MM-DD): ";
    getline(cin,deadlineBaru);
    cout<<"Masukkan prioritas baru (Tinggi/Sedang/Rendah): ";
    getline(cin,prioritasBaru);

    data[nomor1-1]={
        {"deskripsi",tugasBaru},
        {"deadline",deadlineBaru},
        {"prioritas",prioritasBaru},
        {"status","Belum Selesai"}
    };
    simpanData(data);
    cout<<"Tugas berhasil diedit!\n";
    system("pause");
    menu();
}

void tandai_selesai(){
    system("cls");
    json data=bacaData();

    if(data.empty()){
        cout<<"Tidak ada tugas yang bisa ditandai selesa!\n";
        system("pause");
        menu();
    }
    //=======
    int nomor=1;
    cout<<"\n=== Daftar To_Do List ===\n";
    for(const auto& tugas : data){
        cout<<nomor++<<". "<<tugas["deskripsi"]
        <<" | "<<tugas["deadline"]
        <<" | "<<tugas["prioritas"]
        <<" | "<<tugas["status"]<<endl;
    }
    //=======
    int index;
    cout<<"Masukkan nomor tugas yang ingin ditandai sebagai selesai: ";
    cin>>index;
    if(index<1||index>data.size()){
        cout<<"Nomor tidak valid!\n";
        system("pause");
        menu();
    }
    //ubah ststus tugas
    data[index-1]["status"]="Selesai";
    simpanData(data);

    cout<<"Tugas berhasoil ditandai senagai 'Selesai'!\n";
    system("pause");
    menu();
}

void cari_tugas(){
    system("cls");
    json data=bacaData();

    if(data.empty()){
        cout<<"Tidak ada tugas dalam daftar!\n";
        system("pause");
        menu();
    }
    int pilihan;
    cout<<"Cari Tugas Berdasarkan:\n";
    cout<<"1. Deskripsi\n";
    cout<<"2. Deadline\n";
    cout<<"3. Prioritas\n";
    cout<<"4. Status (Belum Selesai/Selesai)\n";
    cout<<"Pilihan: ";
    cin>>pilihan;
    cin.ignore();

    string keyword;
    cout<<"Masukkan kata kunci: ";
    getline(cin,keyword);

    bool ditemukan=false;
    cout<<"\nHasil Pencarian:\n";
    for(size_t i=0;i<data.size();i++){
        bool cocok=false;
        if(pilihan==1&&data[i]["deskripsi"].get<string>().find(keyword)!=string::npos){
            cocok=true;
        }
        else if(pilihan==2&&data[i]["deadline"].get<string>()==keyword){
            cocok=true;
        }
        else if(pilihan==3&&data[i]["prioritas"].get<string>()==keyword){
            cocok=true;
        }
        else if(pilihan==4&&data[i]["status"].get<string>()==keyword){
            cocok=true;
        }
        if(cocok){
            cout<<i+1<<". "
                <<data[i]["deskripsi"]<<" | "
                <<data[i]["deadline"]<<" | "
                <<data[i]["prioritas"]<<" | "
                <<data[i]["status"]<<" | "<<endl;
            ditemukan=true;
        }
    }
    if(!ditemukan){
        cout<<"Tidak ada tugas yang cocok dengan pencarian.\n";
    }
    system("pause");
    menu();
}

void filter_tugas(){
    system("cls");
    json data=bacaData();

    if(data.empty()){
        cout<<"Tidak ada tugas untuk difilter!\n";
        system("pause");
        menu();
    }
    int pilihan;
    cout<<"Filter Tugas Berdasarkan:\n";
    cout<<"1. Status (Selesai/Belum Selesai)\n";
    cout<<"2. Prioritas (Tinggi/Sedang/Rendah)\n";
    cout<<"Pilihan: ";
    cin>>pilihan;
    cin.ignore();

    vector<json> hasil_filter;
    if(pilihan==1){
        string status;
        cout<<"Masukkan status (Selesai/Belum Selesai): ";
        getline(cin,status);
        for(const auto& tugas : data){
            if(tugas["status"].get<string>()==status){
                hasil_filter.push_back(tugas);
            }
        }
    }
    else if(pilihan==2){
        string prioritas;
        cout<<"Masukkan Prioritas (Tinggi/Sedang/Rendah): ";
        getline(cin,prioritas);
        for(const auto& tugas : data){
            if(tugas["prioritas"].get<string>()==prioritas){
                hasil_filter.push_back(tugas);
            }
        }
    }
    else {
        cout<<"Pilihan tidak valid\n";
        system("pause");
        menu();
    }

    if(hasil_filter.empty()){
        cout<<"Tidak ada tugas yang cocok dengan filter!\n";
    }
    else {
        cout<<"\n Hasil Filter:\n";
        for(size_t i=0;i<hasil_filter.size();i++){
            cout<<i+1<<". "<<hasil_filter[i]["deskripsi"]<<" | "
                <<hasil_filter[i]["deadline"]<<" | "
                <<hasil_filter[i]["prioritas"]<<" | "
                <<hasil_filter[i]["status"]<<" | "<<endl;
        }
    }

    system("pause");
    menu();

}

void menu(){
    json data=bacaData();
    system("cls");
    int pilihan;
    cout<<"\n=== TO-DO LIST ===\n";
    cout<<"1. Tampilkan Tugas\n";
    cout<<"2. Tambah Tugas\n";
    cout<<"3. Hapus Tugas\n";
    cout<<"4. Edit tugas\n";
    cout<<"5. Ubah status\n";
    cout<<"6. Cari Tugas\n";
    cout<<"7. Filter Tugas\n";
    cout<<"8. Keluar\n";
    cout<<"Pilih menu: ";
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
