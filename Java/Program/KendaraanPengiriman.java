// ============================================================================
// KELAS: KendaraanPengiriman (Kelas Induk / Base Class)
// Konsep: Hierarchical Inheritance, Komposisi, Polimorfisme
// ============================================================================
// Kelas ini mendefinisikan karakteristik dasar seluruh moda transportasi logistik.
// Menerapkan:
// 1. Komposisi: Memiliki atribut 'mesin' bertipe MesinKendaraan yang terikat erat.
// 2. Hierarchical Inheritance: Menjadi induk bagi TrukKargo, KapalLaut, PesawatKargo.
// 3. Polimorfisme: Menyediakan method 'tampilkanSpesifikasi()' untuk dioverride kelas anak.
// ============================================================================

public class KendaraanPengiriman {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut hak akses protected agar dapat diakses langsung oleh kelas turunan
    // Kode unik identifikasi kendaraan (cth: TRK-001, KPL-101, PSW-201)
    protected String idKendaraan;

    // Merk dan nama model manufaktur kendaraan (cth: Hino Ranger, KM Meratus)
    protected String merkModel;

    // Objek komponen mesin (Komposisi: terikat erat dengan siklus hidup kendaraan)
    protected MesinKendaraan mesin;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: menginisialisasi atribut dengan nilai awal kosong
    public KendaraanPengiriman() {
        this.idKendaraan = "";
        this.merkModel = "";
        this.mesin = new MesinKendaraan();
    }

    // Konstruktor berparameter lengkap: mengisi atribut sesuai data input
    public KendaraanPengiriman(String idKendaraan, String merkModel, MesinKendaraan mesin) {
        this.idKendaraan = idKendaraan;
        this.merkModel = merkModel;
        this.mesin = (mesin != null) ? mesin : new MesinKendaraan();
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data)
    // ------------------------------------------------------------------------

    // Mengambil nilai ID kendaraan
    public String getIdKendaraan() {
        return this.idKendaraan;
    }

    // Mengambil nilai merk dan nama model kendaraan
    public String getMerkModel() {
        return this.merkModel;
    }

    // Mengambil objek komponen mesin kendaraan
    public MesinKendaraan getMesin() {
        return this.mesin;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data)
    // ------------------------------------------------------------------------

    // Mengubah nilai ID kendaraan
    public void setIdKendaraan(String idKendaraan) {
        this.idKendaraan = idKendaraan;
    }

    // Mengubah nilai merk dan model kendaraan
    public void setMerkModel(String merkModel) {
        this.merkModel = merkModel;
    }

    // Mengubah objek mesin kendaraan
    public void setMesin(MesinKendaraan mesin) {
        this.mesin = mesin;
    }

    // ------------------------------------------------------------------------
    // METHOD SPESIFIK & POLIMORFISME
    // ------------------------------------------------------------------------

    // Method polimorfik dasar untuk menampilkan spesifikasi umum kendaraan
    // Method ini dioverride oleh kelas-kelas turunan (Truk, Kapal, Pesawat)
    public void tampilkanSpesifikasi() {
        System.out.println("[Kendaraan Pengiriman Umum]");
        System.out.println("  ID Kendaraan    : " + this.idKendaraan);
        System.out.println("  Merk & Model    : " + this.merkModel);
        System.out.println("  Detail Mesin    : Seri " + this.mesin.getNomorSeriMesin() + 
                           " | " + this.mesin.getTipeMesin() + 
                           " | Bahan Bakar: " + this.mesin.getJenisBahanBakar());
    }
}
