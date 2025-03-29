#ifndef TODO_HPP
#define TODO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "json.hpp" 

using namespace std;
using json=nlohmann::json;

void setColor(const string &color);

const string RESET="\033[0m";
const string RED ="\033[31m";
const string BLUE ="\033[34m";
const string GREEN ="\033[32m";
const string CYAN_BG="\033[46m";

//struct tugas
struct Tugas{
    string deskripsi;
    string deadline;
    string prioritas;
    string selesai;
};

//Fungsi baca dan simpan
json bacaData();
void simpanData(const json &data);

//Fungsi untuk menambah, mengedit, dan menghapus
void tambah_tugas();
void hapus_tugas();
void edit_tugas();
void tampilkan_tugas();
void tandai_selesai();
void cari_tugas();
void filter_tugas();

#endif 