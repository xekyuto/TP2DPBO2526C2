import java.util.ArrayList;
import java.util.Scanner;

class KaryaSeni {
    protected String id, judul, genre;
    public KaryaSeni(String id, String judul, String genre) {
        this.id = id; this.judul = judul; this.genre = genre;
    }
    public String getId() { return id; }
    public String getJudul() { return judul; }
    public String getGenre() { return genre; }
}

class Film extends KaryaSeni {
    protected String sutradara, durasi, batasUmur;
    public Film(String id, String judul, String genre, String sutradara, String durasi, String batasUmur) {
        super(id, judul, genre);
        this.sutradara = sutradara; this.durasi = durasi; this.batasUmur = batasUmur;
    }
    public String getSutradara() { return sutradara; }
    public String getDurasi() { return durasi; }
    public String getBatasUmur() { return batasUmur; }
}

class FilmBioskop extends Film {
    private String studio, poster;
    private int harga;
    public FilmBioskop(String id, String judul, String genre, String sutradara, String durasi, String batasUmur, String studio, int harga, String poster) {
        super(id, judul, genre, sutradara, durasi, batasUmur);
        this.studio = studio;
        this.harga = harga;
        this.poster = poster;
    }
    public String getStudio() { return studio; }
    public int getHarga() { return harga; }
    public String getPoster() { return poster; }
}

public class Main {
    public static void tampilkanTabel(ArrayList<FilmBioskop> daftar) {
        System.out.println("-".repeat(135));
        System.out.printf("| %-5s | %-20s | %-15s | %-15s | %-8s | %-5s | %-10s | %-10s | %-20s |\n", 
            "ID", "Judul", "Genre", "Sutradara", "Durasi", "Usia", "Studio", "Harga", "Poster");
        System.out.println("-".repeat(135));
        for (FilmBioskop f : daftar) {
            System.out.printf("| %-5s | %-20s | %-15s | %-15s | %-8s | %-5s | %-10s | %-10d | %-20s |\n",
                f.getId(), f.getJudul(), f.getGenre(), f.getSutradara(), f.getDurasi(), f.getBatasUmur(), f.getStudio(), f.getHarga(), f.getPoster());
        }
        System.out.println("-".repeat(135));
    }

    public static void main(String[] args) {
        ArrayList<FilmBioskop> daftarFilm = new ArrayList<>();
        daftarFilm.add(new FilmBioskop("F01", "Spiderman", "Action", "Sam Raimi", "120 mnt", "13+", "Studio 1", 50000, "spidey.jpg"));
        daftarFilm.add(new FilmBioskop("F02", "Interstellar", "Sci-Fi", "Nolan", "169 mnt", "13+", "Studio 2", 60000, "inter.jpg"));
        daftarFilm.add(new FilmBioskop("F03", "Oppenheimer", "biografi", "Chris Nolan", "180 mnt", "13+", "Studio 3", 45000, "oppen.png"));
        daftarFilm.add(new FilmBioskop("F04", "Avenger", "Action", "Russo Bros", "180 mnt", "13+", "Studio 1", 55000, "avenger.jpg"));
        daftarFilm.add(new FilmBioskop("F05", "Dune", "Sci-Fi", "Denis V", "155 mnt", "13+", "Studio 4", 65000, "dune.jpg"));

        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("\n    MENU BIOSKOP    ");
            System.out.println("1. Tampilkan Data");
            System.out.println("2. Tambah Data");
            System.out.println("3. Keluar");
            System.out.print("Pilih menu: ");
            String pilihan = sc.nextLine();

            if (pilihan.equals("1")) {
                tampilkanTabel(daftarFilm);
            } else if (pilihan.equals("2")) {
                System.out.print("ID Film: "); String id = sc.nextLine();
                System.out.print("Judul: "); String judul = sc.nextLine();
                System.out.print("Genre: "); String genre = sc.nextLine();
                System.out.print("Sutradara: "); String sutradara = sc.nextLine();
                System.out.print("Durasi: "); String durasi = sc.nextLine();
                System.out.print("Batas Umur: "); String batasUmur = sc.nextLine();
                System.out.print("Studio: "); String studio = sc.nextLine();
                System.out.print("Harga: "); int harga = Integer.parseInt(sc.nextLine());
                System.out.print("Poster: "); String poster = sc.nextLine();
                
                daftarFilm.add(new FilmBioskop(id, judul, genre, sutradara, durasi, batasUmur, studio, harga, poster));
                System.out.println("Data ditambahkan!");
            } else if (pilihan.equals("3")) {
                break;
            }
        }
        sc.close();
    }
}