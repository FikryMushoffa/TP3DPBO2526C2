// ============================================================================
// KELAS: DepoLogistik (Kelas Pengelola)
// Konsep: Agregasi (Aggregation) & Array of Objects
// ============================================================================
// DepoLogistik mengelola sekumpulan kendaraan dan paket yang ditempatkan di suatu kota.
// Penerapan Konsep:
// 1. Agregasi: Depo memiliki hubungan kepemilikan bebas (has-a) dengan kendaraan
//    dan paket. Depo hanya menyimpan referensi objek. Jika objek Depo
//    dihancurkan/ditutup, kendaraan dan paket tetap ada dan dapat dialokasikan ke depo lain.
// 2. Array of Objects: Menggunakan ArrayList objek terpisah untuk tiap kelas:
//    - daftarTruk    : Array of TrukKargo
//    - daftarKapal   : Array of KapalLaut
//    - daftarPesawat : Array of PesawatKargo
//    - daftarPaket   : Array of Paket
// ============================================================================

import java.util.ArrayList;
import java.util.List;

public class DepoLogistik {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut kode identifikasi unik fasilitas depo logistik (cth: DPO-SUB-01)
    private String kodeDepo;

    // Atribut nama kota operasional lokasi fasilitas depo berada (cth: Surabaya)
    private String kotaLokasi;

    // Array of Objects: kumpulan referensi ke kendaraan Truk Kargo (Agregasi)
    private List<TrukKargo> daftarTruk;

    // Array of Objects: kumpulan referensi ke kendaraan Kapal Laut (Agregasi)
    private List<KapalLaut> daftarKapal;

    // Array of Objects: kumpulan referensi ke kendaraan Pesawat Kargo (Agregasi)
    private List<PesawatKargo> daftarPesawat;

    // Array of Objects: kumpulan referensi ke paket logistik (Agregasi)
    private List<Paket> daftarPaket;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: menginisialisasi atribut depo dengan nilai awal kosong
    public DepoLogistik() {
        this.kodeDepo = "";
        this.kotaLokasi = "";
        this.daftarTruk = new ArrayList<>();
        this.daftarKapal = new ArrayList<>();
        this.daftarPesawat = new ArrayList<>();
        this.daftarPaket = new ArrayList<>();
    }

    // Konstruktor berparameter: menginisialisasi kode depo dan kota lokasi
    public DepoLogistik(String kodeDepo, String kotaLokasi) {
        this.kodeDepo = kodeDepo;
        this.kotaLokasi = kotaLokasi;
        this.daftarTruk = new ArrayList<>();
        this.daftarKapal = new ArrayList<>();
        this.daftarPesawat = new ArrayList<>();
        this.daftarPaket = new ArrayList<>();
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data Sesuai Desain)
    // ------------------------------------------------------------------------

    // Mengambil informasi kode unik depo
    public String getKodeDepo() {
        return this.kodeDepo;
    }

    // Mengambil informasi nama kota lokasi fasilitas depo
    public String getKotaLokasi() {
        return this.kotaLokasi;
    }

    // Mengambil daftar referensi seluruh kendaraan truk yang ada di depo
    public List<TrukKargo> getDaftarTruk() {
        return this.daftarTruk;
    }

    // Mengambil daftar referensi seluruh kendaraan kapal yang ada di depo
    public List<KapalLaut> getDaftarKapal() {
        return this.daftarKapal;
    }

    // Mengambil daftar referensi seluruh kendaraan pesawat yang ada di depo
    public List<PesawatKargo> getDaftarPesawat() {
        return this.daftarPesawat;
    }

    // Mengambil daftar referensi seluruh paket kiriman yang ada di depo
    public List<Paket> getDaftarPaket() {
        return this.daftarPaket;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data Sesuai Desain)
    // ------------------------------------------------------------------------

    // Mengubah informasi kode unik fasilitas depo
    public void setKodeDepo(String kodeDepo) {
        this.kodeDepo = kodeDepo;
    }

    // Mengubah informasi nama kota lokasi fasilitas depo
    public void setKotaLokasi(String kotaLokasi) {
        this.kotaLokasi = kotaLokasi;
    }

    // Mengganti seluruh daftar referensi kendaraan truk di depo
    public void setDaftarTruk(List<TrukKargo> daftarTruk) {
        this.daftarTruk = (daftarTruk != null) ? daftarTruk : new ArrayList<>();
    }

    // Mengganti seluruh daftar referensi kendaraan kapal di depo
    public void setDaftarKapal(List<KapalLaut> daftarKapal) {
        this.daftarKapal = (daftarKapal != null) ? daftarKapal : new ArrayList<>();
    }

    // Mengganti seluruh daftar referensi kendaraan pesawat di depo
    public void setDaftarPesawat(List<PesawatKargo> daftarPesawat) {
        this.daftarPesawat = (daftarPesawat != null) ? daftarPesawat : new ArrayList<>();
    }

    // Mengganti seluruh daftar referensi paket kiriman di depo
    public void setDaftarPaket(List<Paket> daftarPaket) {
        this.daftarPaket = (daftarPaket != null) ? daftarPaket : new ArrayList<>();
    }

    // ------------------------------------------------------------------------
    // METHOD PENAMBAHAN DATA SATUAN (HELPER OPERASIONAL)
    // ------------------------------------------------------------------------

    // Menambahkan satu objek referensi kendaraan Truk Kargo ke dalam depo (Agregasi)
    public void tambahTruk(TrukKargo truk) {
        if (truk != null) {
            this.daftarTruk.add(truk);
        }
    }

    // Menambahkan satu objek referensi kendaraan Kapal Laut ke dalam depo (Agregasi)
    public void tambahKapal(KapalLaut kapal) {
        if (kapal != null) {
            this.daftarKapal.add(kapal);
        }
    }

    // Menambahkan satu objek referensi kendaraan Pesawat Kargo ke dalam depo (Agregasi)
    public void tambahPesawat(PesawatKargo pesawat) {
        if (pesawat != null) {
            this.daftarPesawat.add(pesawat);
        }
    }

    // Menambahkan satu objek referensi Paket kiriman ke dalam depo (Agregasi)
    public void tambahPaket(Paket paket) {
        if (paket != null) {
            this.daftarPaket.add(paket);
        }
    }

    // ------------------------------------------------------------------------
    // METHOD OPERASIONAL: TAMPILKAN STATUS RINGKASAN DEPO
    // ------------------------------------------------------------------------

    // Menampilkan informasi umum dan rekapitulasi jumlah kendaraan serta paket pada fasilitas depo
    public void tampilkanInformasiDepo() {
        int totalKendaraan = this.daftarTruk.size() + this.daftarKapal.size() + this.daftarPesawat.size();
        System.out.println("Kode Depo       : " + this.kodeDepo);
        System.out.println("Kota Lokasi     : " + this.kotaLokasi);
        System.out.println("Total Kendaraan : " + totalKendaraan + " unit (" + 
                           this.daftarTruk.size() + " Truk, " + 
                           this.daftarKapal.size() + " Kapal, " + 
                           this.daftarPesawat.size() + " Pesawat)");
        System.out.println("Total Paket     : " + this.daftarPaket.size() + " paket kiriman");
    }
}
