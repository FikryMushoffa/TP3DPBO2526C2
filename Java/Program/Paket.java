// ============================================================================
// KELAS: Paket (Kelas Data)
// Konsep: Entitas Data & Agregasi (Aggregated Entity)
// ============================================================================
// Kelas Paket merepresentasikan data kargo/barang kiriman yang dikelola oleh depo
// logistik. Paket memiliki siklus hidup independen dan diagregasikan oleh DepoLogistik.
// ============================================================================

public class Paket {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut unik nomor pelacakan resi kiriman (cth: PKG-ID-2026-001)
    private String nomorResi;

    // Atribut berat fisik kargo barang (satuan kilogram)
    private double beratKg;

    // Atribut deskripsi / manifest kategori muatan barang
    private String deskripsiBarang;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: menginisialisasi atribut paket dengan nilai awal kosong
    public Paket() {
        this.nomorResi = "";
        this.beratKg = 0.0;
        this.deskripsiBarang = "";
    }

    // Konstruktor berparameter lengkap: mengisi data resi, berat, dan deskripsi paket
    public Paket(String nomorResi, double beratKg, String deskripsiBarang) {
        this.nomorResi = nomorResi;
        this.beratKg = beratKg;
        this.deskripsiBarang = deskripsiBarang;
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data)
    // ------------------------------------------------------------------------

    // Mengambil informasi nomor resi paket
    public String getNomorResi() {
        return this.nomorResi;
    }

    // Mengambil informasi berat fisik paket (kg)
    public double getBeratKg() {
        return this.beratKg;
    }

    // Mengambil informasi rincian deskripsi barang kiriman
    public String getDeskripsiBarang() {
        return this.deskripsiBarang;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data)
    // ------------------------------------------------------------------------

    // Mengubah nomor resi paket
    public void setNomorResi(String nomorResi) {
        this.nomorResi = nomorResi;
    }

    // Mengubah berat fisik paket (kg)
    public void setBeratKg(double beratKg) {
        this.beratKg = beratKg;
    }

    // Mengubah rincian deskripsi barang kiriman
    public void setDeskripsiBarang(String deskripsiBarang) {
        this.deskripsiBarang = deskripsiBarang;
    }
}
