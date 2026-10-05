// ============================================================================
// KELAS: KapalLaut (Kelas Anak 2)
// Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
// ============================================================================
// KapalLaut merupakan turunan dari KendaraanPengiriman untuk moda transportasi laut.
// Memiliki atribut unik 'tipeKontainer' dan 'biayaSewaSektor', serta meng-override
// method 'tampilkanSpesifikasi()' untuk menampilkan data khas kapal kargo logistik.
// ============================================================================

public class KapalLaut extends KendaraanPengiriman {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut spesifik: tipe kontainer yang didukung (cth: Dry Container 20/40ft, Reefer)
    private String tipeKontainer;

    // Atribut spesifik: biaya sewa slot pengiriman laut per sektor pelayaran (Rupiah)
    private double biayaSewaSektor;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: memanggil konstruktor induk dan mengosongkan atribut kapal
    public KapalLaut() {
        super();
        this.tipeKontainer = "";
        this.biayaSewaSektor = 0.0;
    }

    // Konstruktor berparameter: menginisialisasi atribut induk dan atribut spesifik kapal
    public KapalLaut(String idKendaraan, String merkModel, MesinKendaraan mesin, 
                     String tipeKontainer, double biayaSewaSektor) {
        super(idKendaraan, merkModel, mesin);
        this.tipeKontainer = tipeKontainer;
        this.biayaSewaSektor = biayaSewaSektor;
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data)
    // ------------------------------------------------------------------------

    // Mengambil informasi jenis/tipe kontainer kapal
    public String getTipeKontainer() {
        return this.tipeKontainer;
    }

    // Mengambil informasi biaya sewa rute per sektor pelayaran
    public double getBiayaSewaSektor() {
        return this.biayaSewaSektor;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data)
    // ------------------------------------------------------------------------

    // Mengubah informasi jenis/tipe kontainer kapal
    public void setTipeKontainer(String tipeKontainer) {
        this.tipeKontainer = tipeKontainer;
    }

    // Mengubah informasi biaya sewa rute per sektor pelayaran
    public void setBiayaSewaSektor(double biayaSewaSektor) {
        this.biayaSewaSektor = biayaSewaSektor;
    }

    // ------------------------------------------------------------------------
    // METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
    // ------------------------------------------------------------------------

    // Menampilkan spesifikasi lengkap khusus kendaraan Kapal Laut
    @Override
    public void tampilkanSpesifikasi() {
        System.out.println("    ID Kendaraan     : " + this.idKendaraan);
        System.out.println("    Nama / Model     : " + this.merkModel);
        System.out.println("    Tipe Kontainer   : " + this.tipeKontainer);
        System.out.printf("    Biaya Sewa Rute  : Rp %.0f / sektor%n", this.biayaSewaSektor);
        System.out.println("    Spesifikasi Mesin:");
        System.out.println("      - No Seri Mesin: " + this.mesin.getNomorSeriMesin());
        System.out.println("      - Tipe Mesin   : " + this.mesin.getTipeMesin());
        System.out.println("      - Bahan Bakar  : " + this.mesin.getJenisBahanBakar());
    }
}
