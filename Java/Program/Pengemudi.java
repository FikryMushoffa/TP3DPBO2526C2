// ============================================================================
// KELAS: Pengemudi (Kelas Operasional)
// Konsep: Asosiasi (Association)
// ============================================================================
// Pengemudi merepresentasikan personil operator/pengemudi kendaraan logistik.
// Relasi Asosiasi:
// Hubungan bersifat 'use-a' (menggunakan). Pengemudi tidak memiliki (has-a)
// kendaraan secara permanen sebagai atribut. Objek KendaraanPengiriman hanya
// diterima sebagai parameter sementara pada method 'tampilkanTugas(kendaraan)'.
// ============================================================================

public class Pengemudi {
    // ------------------------------------------------------------------------
    // ATRIBUT
    // ------------------------------------------------------------------------

    // Atribut unik nomor identifikasi registrasi pengemudi/operator
    private String idPengemudi;

    // Atribut nama lengkap pengemudi/operator
    private String nama;

    // Atribut nomor sertifikasi lisensi kemudi (SIM B2 / Lisensi Pelaut / ATPL)
    private String nomorLisensi;

    // ------------------------------------------------------------------------
    // KONSTRUKTOR
    // ------------------------------------------------------------------------

    // Konstruktor default: menginisialisasi atribut pengemudi dengan string kosong
    public Pengemudi() {
        this.idPengemudi = "";
        this.nama = "";
        this.nomorLisensi = "";
    }

    // Konstruktor berparameter lengkap: mengisi data ID, nama, dan lisensi kemudi
    public Pengemudi(String idPengemudi, String nama, String nomorLisensi) {
        this.idPengemudi = idPengemudi;
        this.nama = nama;
        this.nomorLisensi = nomorLisensi;
    }

    // ------------------------------------------------------------------------
    // GETTER (Method Akses Pembaca Data)
    // ------------------------------------------------------------------------

    // Mengambil nomor identitas registrasi pengemudi
    public String getIdPengemudi() {
        return this.idPengemudi;
    }

    // Mengambil nama lengkap personil pengemudi
    public String getNama() {
        return this.nama;
    }

    // Mengambil nomor sertifikasi lisensi kemudi pengemudi
    public String getNomorLisensi() {
        return this.nomorLisensi;
    }

    // ------------------------------------------------------------------------
    // SETTER (Method Akses Pengubah Data)
    // ------------------------------------------------------------------------

    // Mengubah nomor identitas registrasi pengemudi
    public void setIdPengemudi(String idPengemudi) {
        this.idPengemudi = idPengemudi;
    }

    // Mengubah nama lengkap personil pengemudi
    public void setNama(String nama) {
        this.nama = nama;
    }

    // Mengubah nomor sertifikasi lisensi kemudi pengemudi
    public void setNomorLisensi(String nomorLisensi) {
        this.nomorLisensi = nomorLisensi;
    }

    // ------------------------------------------------------------------------
    // METHOD SPESIFIK: PEMBUKTIAN ASOSIASI (ASSOCIATION)
    // ------------------------------------------------------------------------

    // Method pembuktian asosiasi: menerima objek KendaraanPengiriman sebagai parameter sementara
    // Menampilkan identitas pengemudi beserta kendaraan yang sedang ditugaskan kepadanya (ID & Model)
    public void tampilkanTugas(KendaraanPengiriman kendaraan) {
        if (kendaraan != null) {
            System.out.println("  [Operator / Pengemudi]");
            System.out.println("    ID Pengemudi        : " + this.idPengemudi);
            System.out.println("    Nama Pengemudi      : " + this.nama);
            System.out.println("    Nomor Lisensi       : " + this.nomorLisensi);
            System.out.println("    Penugasan Kendaraan : " + kendaraan.getIdKendaraan() + " (" + kendaraan.getMerkModel() + ")");
            System.out.println("  -------------------------------------------------------");
        }
    }
}
