// ============================================================================
// KELAS: PesawatKargo (Kelas Anak 3)
// Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
// ============================================================================
// PesawatKargo merupakan turunan dari KendaraanPengiriman untuk moda transportasi udara.
// Memiliki atribut unik 'ketinggianMaksimal' dan 'surchargeAvtur', serta meng-override
// method 'tampilkanSpesifikasi()' untuk menampilkan data khas pesawat kargo logistik.
// ============================================================================

public class PesawatKargo extends KendaraanPengiriman {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut spesifik: batas ketinggian terbang jelajah maksimal (kaki / feet)
    private int ketinggianMaksimal;

    // Atribut spesifik: biaya surcharge bahan bakar avtur per jadwal penerbangan (Rupiah)
    private double surchargeAvtur;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: memanggil konstruktor induk dan mengosongkan atribut pesawat
    public PesawatKargo() {
        super();
        this.ketinggianMaksimal = 0;
        this.surchargeAvtur = 0.0;
    }

    // Konstruktor berparameter: menginisialisasi atribut induk dan atribut spesifik pesawat
    public PesawatKargo(String idKendaraan, String merkModel, MesinKendaraan mesin, 
                        int ketinggianMaksimal, double surchargeAvtur) {
        super(idKendaraan, merkModel, mesin);
        this.ketinggianMaksimal = ketinggianMaksimal;
        this.surchargeAvtur = surchargeAvtur;
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data)
    // ------------------------------------------------------------------------

    // Mengambil informasi batas ketinggian terbang jelajah maksimal (kaki)
    public int getKetinggianMaksimal() {
        return this.ketinggianMaksimal;
    }

    // Mengambil informasi biaya surcharge bahan bakar avtur per penerbangan
    public double getSurchargeAvtur() {
        return this.surchargeAvtur;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data)
    // ------------------------------------------------------------------------

    // Mengubah informasi batas ketinggian terbang jelajah maksimal (kaki)
    public void setKetinggianMaksimal(int ketinggianMaksimal) {
        this.ketinggianMaksimal = ketinggianMaksimal;
    }

    // Mengubah informasi biaya surcharge bahan bakar avtur per penerbangan
    public void setSurchargeAvtur(double surchargeAvtur) {
        this.surchargeAvtur = surchargeAvtur;
    }

    // ------------------------------------------------------------------------
    // METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
    // ------------------------------------------------------------------------

    // Menampilkan spesifikasi lengkap khusus kendaraan Pesawat Kargo
    @Override
    public void tampilkanSpesifikasi() {
        System.out.println("    ID Kendaraan     : " + this.idKendaraan);
        System.out.println("    Model Pesawat    : " + this.merkModel);
        System.out.println("    Ketinggian Maks  : " + this.ketinggianMaksimal + " kaki");
        System.out.printf("    Surcharge Avtur  : Rp %.0f%n", this.surchargeAvtur);
        System.out.println("    Spesifikasi Mesin:");
        System.out.println("      - No Seri Mesin: " + this.mesin.getNomorSeriMesin());
        System.out.println("      - Tipe Mesin   : " + this.mesin.getTipeMesin());
        System.out.println("      - Bahan Bakar  : " + this.mesin.getJenisBahanBakar());
    }
}
