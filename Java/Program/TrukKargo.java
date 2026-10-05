// ============================================================================
// KELAS: TrukKargo (Kelas Anak 1)
// Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
// ============================================================================
// TrukKargo merupakan turunan dari KendaraanPengiriman untuk moda transportasi darat.
// Memiliki atribut unik 'jumlahRoda' dan 'tarifPerKmDarat', serta meng-override
// method 'tampilkanSpesifikasi()' untuk menampilkan data khas truk logistik.
// ============================================================================

public class TrukKargo extends KendaraanPengiriman {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut spesifik: jumlah roda pada kendaraan truk (cth: 6, 10, 18 roda)
    private int jumlahRoda;

    // Atribut spesifik: tarif dasar pengiriman per kilometer jalan darat (Rupiah)
    private double tarifPerKmDarat;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: memanggil konstruktor induk dan mengosongkan atribut truk
    public TrukKargo() {
        super();
        this.jumlahRoda = 0;
        this.tarifPerKmDarat = 0.0;
    }

    // Konstruktor berparameter: menginisialisasi atribut induk dan atribut spesifik truk
    public TrukKargo(String idKendaraan, String merkModel, MesinKendaraan mesin, 
                     int jumlahRoda, double tarifPerKmDarat) {
        super(idKendaraan, merkModel, mesin);
        this.jumlahRoda = jumlahRoda;
        this.tarifPerKmDarat = tarifPerKmDarat;
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data)
    // ------------------------------------------------------------------------

    // Mengambil informasi jumlah roda truk
    public int getJumlahRoda() {
        return this.jumlahRoda;
    }

    // Mengambil informasi tarif pengiriman darat per kilometer
    public double getTarifPerKmDarat() {
        return this.tarifPerKmDarat;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data)
    // ------------------------------------------------------------------------

    // Mengubah informasi jumlah roda truk
    public void setJumlahRoda(int jumlahRoda) {
        this.jumlahRoda = jumlahRoda;
    }

    // Mengubah informasi tarif pengiriman darat per kilometer
    public void setTarifPerKmDarat(double tarifPerKmDarat) {
        this.tarifPerKmDarat = tarifPerKmDarat;
    }

    // ------------------------------------------------------------------------
    // METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
    // ------------------------------------------------------------------------

    // Menampilkan spesifikasi lengkap khusus kendaraan Truk Kargo
    @Override
    public void tampilkanSpesifikasi() {
        System.out.println("    ID Kendaraan     : " + this.idKendaraan);
        System.out.println("    Merk & Model     : " + this.merkModel);
        System.out.println("    Konfigurasi Roda : " + this.jumlahRoda + " roda");
        System.out.printf("    Tarif per Km     : Rp %.0f%n", this.tarifPerKmDarat);
        System.out.println("    Spesifikasi Mesin:");
        System.out.println("      - No Seri Mesin: " + this.mesin.getNomorSeriMesin());
        System.out.println("      - Tipe Mesin   : " + this.mesin.getTipeMesin());
        System.out.println("      - Bahan Bakar  : " + this.mesin.getJenisBahanBakar());
    }
}
