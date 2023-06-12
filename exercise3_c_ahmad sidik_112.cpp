#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x; // variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    bidangDatar() { // constructor
        x = 0;
    }
    virtual void input() {} // fungsi yang menerima input dan mengirim input melalui

    virtual float Luas(int a) { return 0; } // fungsi untuk menghitung luas
    virtual float Keliling(int a) { return 0; } // fungsi untuk menghitung keliling
    void setX(int a) { // fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }
    int getX() { // fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        int r;
        cout << "Masukkan jari-jari lingkaran: ";
        cin >> r;
        setX(r);
    }

    float Luas(int a) {
        int r; getX();
        return 3.14 * a * r;
    }

    float Keliling(int a) {
        int r; getX();
        return 2 * 3.14 * r;
    }
};

class Bujursangkar : public bidangDatar {
public:
    void input() {
        int sisi;
        cout << "Masukkan panjang sisi bujursangkar: ";
        cin >> sisi;
        setX(sisi);
    }

    float Luas(int a) {
        int r; getX();
        return a * r;
    }

    float Keliling(int a) {
        int r; getX();
        return 4 * r;
    }
};

int main() {
    Lingkaran lingkaran;
    Bujursangkar bujursangkar;

    bidangDatar* bidang; // pointer polymorphism

    int pilihan;
    cout << "Pilih bidang datar: \n";
    cout << "1. Lingkaran\n";
    cout << "2. Bujursangkar\n";
    cout << "Masukkan pilihan (1/2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        bidang = &lingkaran;
        bidang->input();
        cout << "Luas lingkaran: " << bidang->Luas(bidang->getX()) << endl;
        cout << "Keliling lingkaran: " << bidang->Keliling(bidang->getX()) << endl;
    }
    else if (pilihan == 2) {
        bidang = &bujursangkar;
        bidang->input();
        cout << "Luas bujursangkar: " << bidang->Luas(bidang->getX()) << endl;
        cout << "Keliling bujursangkar: " << bidang->Keliling(bidang->getX()) << endl;
    }
    else {
        cout << "Pilihan tidak valid\n";
    }

    return 0;

