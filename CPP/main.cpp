#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class KaryaSeni {
protected:
    string id_karya, judul, genre;
public:
    KaryaSeni(string id, string jdl, string gnr) : id_karya(id), judul(jdl), genre(gnr) {}
    string getId() { return id_karya; }
    string getJudul() { return judul; }
    string getGenre() { return genre; }
};

class Film : public KaryaSeni {
protected:
    string sutradara, durasi, batas_umur;
public:
    Film(string id, string jdl, string gnr, string sut, string dur, string bts) 
        : KaryaSeni(id, jdl, gnr), sutradara(sut), durasi(dur), batas_umur(bts) {}
    string getSutradara() { return sutradara; }
    string getDurasi() { return durasi; }
    string getBatasUmur() { return batas_umur; }
};

class FilmBioskop : public Film {
private:
    string studio, poster;
    int harga;
public:
    FilmBioskop(string id, string jdl, string gnr, string sut, string dur, string bts, string stdio, int hrg, string pstr)
        : Film(id, jdl, gnr, sut, dur, bts), studio(stdio), harga(hrg), poster(pstr) {}
    
    string getStudio() { return studio; }
    int getHarga() { return harga; }
    string getPoster() { return poster; }
};

void tampilkanTabel(vector<FilmBioskop>& daftar) {
    cout << string(135, '-') << endl;
    cout << "| " << left << setw(5) << "ID" 
         << " | " << setw(20) << "Judul" 
         << " | " << setw(15) << "Genre" 
         << " | " << setw(15) << "Sutradara" 
         << " | " << setw(8) << "Durasi" 
         << " | " << setw(5) << "Usia" 
         << " | " << setw(10) << "Studio" 
         << " | " << setw(10) << "Harga" 
         << " | " << setw(20) << "Poster" << " |" << endl;
    cout << string(135, '-') << endl;
    
    for (auto& f : daftar) {
        cout << "| " << left << setw(5) << f.getId() 
             << " | " << setw(20) << f.getJudul() 
             << " | " << setw(15) << f.getGenre() 
             << " | " << setw(15) << f.getSutradara() 
             << " | " << setw(8) << f.getDurasi() 
             << " | " << setw(5) << f.getBatasUmur() 
             << " | " << setw(10) << f.getStudio() 
             << " | " << setw(10) << f.getHarga() 
             << " | " << setw(20) << f.getPoster() << " |" << endl;
    }
    cout << string(135, '-') << endl;
}

int main() {
    vector<FilmBioskop> daftar;
    daftar.push_back(FilmBioskop("F01", "Spiderman", "Action", "Sam Raimi", "120 mnt", "13+", "Studio 1", 50000, "spidey.jpg"));
    daftar.push_back(FilmBioskop("F02", "Interstellar", "Sci-Fi", "Nolan", "169 mnt", "13+", "Studio 2", 60000, "inter.jpg"));
    daftar.push_back(FilmBioskop("F03", "Oppenheimer", "biografi", "Chris Nolan", "180 mnt", "13+", "Studio 3", 45000, "oppen.png"));
    daftar.push_back(FilmBioskop("F04", "Avenger", "Action", "Russo Bros", "180 mnt", "13+", "Studio 1", 55000, "avenger.jpg"));
    daftar.push_back(FilmBioskop("F05", "Dune", "Sci-Fi", "Denis V", "155 mnt", "13+", "Studio 4", 65000, "dune.jpg"));

    string pilihan;
    while (true) {
        cout << "\n   MENU BIOSKOP CPP    \n1. Tampilkan Data\n2. Tambah Data\n3. Keluar\nPilih menu: ";
        getline(cin, pilihan);
        
        if (pilihan == "1") {
            tampilkanTabel(daftar);
        } else if (pilihan == "2") {
            string id, jud, gen, sut, dur, bts, stdio, pos;
            int hrg;
            cout << "ID Film: "; getline(cin, id);
            cout << "Judul: "; getline(cin, jud);
            cout << "Genre: "; getline(cin, gen);
            cout << "Sutradara: "; getline(cin, sut);
            cout << "Durasi: "; getline(cin, dur);
            cout << "Batas Umur: "; getline(cin, bts);
            cout << "Studio: "; getline(cin, stdio);
            cout << "Harga: "; cin >> hrg; cin.ignore();
            cout << "Poster: "; getline(cin, pos);
            
            daftar.push_back(FilmBioskop(id, jud, gen, sut, dur, bts, stdio, hrg, pos));
            cout << "Data ditambahkan!\n";
        } else if (pilihan == "3") {
            break;
        }
    }
    return 0;
}