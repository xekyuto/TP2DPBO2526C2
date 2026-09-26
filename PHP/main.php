<?php
class KaryaSeni {
    protected $id_karya, $judul, $genre;
    public function __construct($id, $jdl, $gnr) {
        $this->id_karya = $id; $this->judul = $jdl; $this->genre = $gnr;
    }
    public function getId() { return $this->id_karya; }
    public function getJudul() { return $this->judul; }
    public function getGenre() { return $this->genre; }
}

class Film extends KaryaSeni {
    protected $sutradara, $durasi, $batas_umur;
    public function __construct($id, $jdl, $gnr, $sut, $dur, $bts) {
        parent::__construct($id, $jdl, $gnr);
        $this->sutradara = $sut; $this->durasi = $dur; $this->batas_umur = $bts;
    }
    public function getSutradara() { return $this->sutradara; }
    public function getDurasi() { return $this->durasi; }
    public function getBatasUmur() { return $this->batas_umur; }
}

class FilmBioskop extends Film {
    private $studio, $harga, $foto_produk;
    public function __construct($id, $jdl, $gnr, $sut, $dur, $bts, $stdio, $hrg, $foto) {
        parent::__construct($id, $jdl, $gnr, $sut, $dur, $bts);
        $this->studio = $stdio;
        $this->harga = $hrg;
        $this->foto_produk = $foto; //atribut foto
    }
    public function getStudio() { return $this->studio; }
    public function getHarga() { return $this->harga; }
    public function getFoto() { return $this->foto_produk; }
}

//Inisialisasi 5 objek
$daftar = [
    new FilmBioskop("F01", "Spiderman", "Action", "Sam Raimi", "120 mnt", "13+", "Studio 1", 50000, "spidey.jpg"),
    new FilmBioskop("F02", "Interstellar", "Sci-Fi", "Nolan", "169 mnt", "13+", "Studio 2", 60000, "inter.jpg"),
    new FilmBioskop("F03", "Oppenheimer", "biografi", "Chris Nolan", "180 mnt", "13+", "Studio 3", 45000, "oppen.png"),
    new FilmBioskop("F04", "Avenger", "Action", "Russo Bros", "180 mnt", "13+", "Studio 1", 55000, "avenger.jpg"),
    new FilmBioskop("F05", "Dune", "Sci-Fi", "Denis V", "155 mnt", "13+", "Studio 4", 65000, "dune.jpg")
];
?>

<!DOCTYPE html>
<html>
<head>
    <title>Sistem Bioskop</title>
    <style>
        table { width: 100%; border-collapse: collapse; font-family: sans-serif; }
        th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }
        th { background-color: #f2f2f2; }
    </style>
</head>
<body>
    <h2>Daftar Film Bioskop</h2>
    <table>
        <tr>
            <th>ID</th><th>Judul</th><th>Genre</th><th>Sutradara</th><th>Durasi</th><th>Usia</th><th>Studio</th><th>Harga</th><th>Poster</th>
        </tr>
        <?php foreach ($daftar as $f) { ?>
        <tr>
            <td><?= $f->getId() ?></td>
            <td><?= $f->getJudul() ?></td>
            <td><?= $f->getGenre() ?></td>
            <td><?= $f->getSutradara() ?></td>
            <td><?= $f->getDurasi() ?></td>
            <td><?= $f->getBatasUmur() ?></td>
            <td><?= $f->getStudio() ?></td>
            <td>Rp <?= number_format($f->getHarga(), 0, ',', '.') ?></td>
            <td><?= $f->getFoto() ?></td>
        </tr>
        <?php } ?>
    </table>
</body>
</html>