// ============================================================================
// KELAS: MesinKendaraan (Kelas Komponen)
// Konsep: Komposisi (Composition Component)
// ============================================================================
// Kelas MesinKendaraan berfungsi sebagai bagian integral/komponen mesin dari
// kendaraan pengiriman. Dalam relasi Komposisi, masa hidup objek mesin terikat
// sepenuhnya pada objek kendaraan yang memilikinya.
// ============================================================================

public class MesinKendaraan {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut nomor seri unik manufaktur mesin
    private String nomorSeriMesin;

    // Atribut model/tipe konfigurasi mesin (cth: J08E Turbo, CFM56 Turbofan)
    private String tipeMesin;

    // Atribut tipe bahan bakar yang digunakan mesin (cth: Solar CN-51, Avtur Jet A-1)
    private String jenisBahanBakar;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: menginisialisasi atribut dengan nilai string kosong
    public MesinKendaraan() {
        this.nomorSeriMesin = "";
        this.tipeMesin = "";
        this.jenisBahanBakar = "";
    }

    // Konstruktor berparameter: menginisialisasi atribut mesin sesuai argumen input
    public MesinKendaraan(String nomorSeriMesin, String tipeMesin, String jenisBahanBakar) {
        this.nomorSeriMesin = nomorSeriMesin;
        this.tipeMesin = tipeMesin;
        this.jenisBahanBakar = jenisBahanBakar;
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data)
    // ------------------------------------------------------------------------

    // Mengambil informasi nomor seri mesin
    public String getNomorSeriMesin() {
        return this.nomorSeriMesin;
    }

    // Mengambil informasi tipe/konfigurasi mesin
    public String getTipeMesin() {
        return this.tipeMesin;
    }

    // Mengambil informasi jenis bahan bakar mesin
    public String getJenisBahanBakar() {
        return this.jenisBahanBakar;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data)
    // ------------------------------------------------------------------------

    // Mengubah informasi nomor seri mesin
    public void setNomorSeriMesin(String nomorSeriMesin) {
        this.nomorSeriMesin = nomorSeriMesin;
    }

    // Mengubah informasi tipe/konfigurasi mesin
    public void setTipeMesin(String tipeMesin) {
        this.tipeMesin = tipeMesin;
    }

    // Mengubah informasi jenis bahan bakar mesin
    public void setJenisBahanBakar(String jenisBahanBakar) {
        this.jenisBahanBakar = jenisBahanBakar;
    }
}
