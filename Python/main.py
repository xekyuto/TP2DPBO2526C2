class KaryaSeni:
    def __init__(self, id_karya, judul, genre):
        self._id_karya = id_karya
        self._judul = judul
        self._genre = genre

    def get_id(self): return self._id_karya
    def get_judul(self): return self._judul
    def get_genre(self): return self._genre

class Film(KaryaSeni):
    def __init__(self, id_karya, judul, genre, sutradara, durasi, batas_umur):
        super().__init__(id_karya, judul, genre)
        self._sutradara = sutradara
        self._durasi = durasi
        self._batas_umur = batas_umur

    def get_sutradara(self): return self._sutradara
    def get_durasi(self): return self._durasi
    def get_batas_umur(self): return self._batas_umur

class FilmBioskop(Film):
    def __init__(self, id_karya, judul, genre, sutradara, durasi, batas_umur, studio, harga, poster):
        super().__init__(id_karya, judul, genre, sutradara, durasi, batas_umur)
        self._studio = studio
        self._harga = harga
        self._poster = poster

    def get_studio(self): return self._studio
    def get_harga(self): return self._harga
    def get_poster(self): return self._poster

def tampilkan_tabel(daftar_film):
    print("-" * 142)
    print(f"| {'ID':<5} | {'Judul Film':<20} | {'Genre':<15} | {'Sutradara':<15} | {'Durasi':<8} | {'Usia':<5} | {'Studio':<10} | {'Harga':<10} | {'Poster':<20} |")
    print("-" * 142)
    for f in daftar_film:
        print(f"| {f.get_id():<5} | {f.get_judul():<20} | {f.get_genre():<15} | {f.get_sutradara():<15} | {f.get_durasi():<8} | {f.get_batas_umur():<5} | {f.get_studio():<10} | {f.get_harga():<10} | {f.get_poster():<20} |")
    print("-" * 142)

def main():
    #5 Objek Awal 
    daftar_film = [
        FilmBioskop("F01", "Spiderman", "Action", "Sam Raimi", "120 mnt", "13+", "Studio 1", 50000, "spidey.jpg"),
        FilmBioskop("F02", "Interstellar", "Sci-Fi", "Chris Nolan", "169 mnt", "13+", "Studio 2", 60000, "inter.jpg"),
        FilmBioskop("F03", "Oppenheimer", "biografi", "Chris Nolan", "180 mnt", "13+", "Studio 3", 45000, "oppen.png"),
        FilmBioskop("F04", "Avenger", "Action", "Russo Bros", "180 mnt", "13+", "Studio 1", 55000, "avenger.jpg"),
        FilmBioskop("F05", "Dune", "Sci-Fi", "Denis V", "155 mnt", "13+", "Studio 4", 65000, "dune.jpg")
    ]

    while True:
        print("\n    MENU BIOSKOP OOP    ")
        print("1. Tampilkan Daftar Film")
        print("2. Tambah Film Baru")
        print("3. Keluar")
        pilihan = input("Pilih menu (1/2/3): ")

        if pilihan == '1':
            tampilkan_tabel(daftar_film)
        elif pilihan == '2':
            print("\n-- Masukkan Data Film Baru --")
            id_karya = input("ID Film: ")
            judul = input("Judul: ")
            genre = input("Genre: ")
            sutradara = input("Sutradara: ")
            durasi = input("Durasi (ex: 120 mnt): ")
            batas_umur = input("Batas Umur (ex: 13+): ")
            studio = input("Studio: ")
            harga = int(input("Harga Tiket: "))
            poster = input("Nama File Poster (ex: foto.jpg): ")
            
            film_baru = FilmBioskop(id_karya, judul, genre, sutradara, durasi, batas_umur, studio, harga, poster)
            daftar_film.append(film_baru)
            print("Data berhasil ditambahkan!")
        elif pilihan == '3':
            print("Selesai.")
            break
        else:
            print("Pilihan tidak valid.")

if __name__ == "__main__":
    main()