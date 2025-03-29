#include "TODO.hpp"
#include "Utilitas.hpp"

void setColor(const string &color){
    cout<<color;
}

//Fungsi baca dan simpan
json bacaData() {
    ifstream file("todolist.json");
    json data;

    if (!file) {
        cout << "File JSON tidak ditemukan, membuat file baru...\n";
        ofstream newFile("todolist.json");
        newFile << "[]"; // Isi awal agar JSON valid
        newFile.close();
        return json::array();
    }

    try {
        file >> data;
    } catch (json::parse_error& e) {
        cout << "ERROR: Gagal membaca JSON! " << e.what() << endl;
        return json::array();
    }

    file.close();
    return data;
}
void simpanData(const json& data) {
    ofstream file("todolist.json");

    if (!file) {
        cout << "ERROR: Tidak bisa membuka file JSON untuk ditulis!\n";
        return;
    }

    file << data.dump(4); // Simpan dalam format rapi
    file.close();
}

//Fungsi untuk menambah, mengedit, dan menghapus
void tambah_tugas() {
    clearScreen();
    json data = bacaData();
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
}
void hapus_tugas(){
    clearScreen();
    json data=bacaData();
    if(data.empty()){
        cout<<"belum ada tugas untuk dihapus.\n";
        return;
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
        return;
    }

    data.erase(data.begin()+nomor1-1);
    simpanData(data);
    cout<<"Tugas berhasil dihapus!\n";
}
void edit_tugas(){
    clearScreen();
    json data=bacaData();
    if(data.empty()){
        cout<<"Belum ada tugas untuk diedit\n";
        return;
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
        return;
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
}
void tampilkan_tugas(){
    clearScreen();
    json data=bacaData();
    if(data.empty()){
        cout<<"Belum ada tugas.\n";
        return;
    }
    
    int nomor=1;
    cout<<"\n=== Daftar To_Do List ===\n";
    for(const auto& tugas : data){
        cout<<nomor++<<". "<<tugas["deskripsi"]
        <<" | "<<tugas["deadline"]
        <<" | "<<tugas["prioritas"]
        <<" | "<<tugas["status"]<<endl;

    }
}
void tandai_selesai(){
    clearScreen();
    json data=bacaData();

    if(data.empty()){
        cout<<"Tidak ada tugas yang bisa ditandai selesa!\n";
        return;
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
        return;
    }
    //ubah ststus tugas
    data[index-1]["status"]="Selesai";
    simpanData(data);

    cout<<"Tugas berhasoil ditandai senagai 'Selesai'!\n";
}
void cari_tugas(){
    clearScreen();
    json data=bacaData();

    if(data.empty()){
        cout<<"Tidak ada tugas dalam daftar!\n";
        return;
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
}
void filter_tugas(){
    clearScreen();
    json data=bacaData();

    if(data.empty()){
        cout<<"Tidak ada tugas untuk difilter!\n";
        return;
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
        return;
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
}