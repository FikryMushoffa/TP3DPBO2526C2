// ============================================================================
// KELAS: Pengemudi (Kelas Operasional)
// Konsep: Asosiasi (Association)
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// Pengemudi merepresentasikan personil operator/pengemudi kendaraan logistik.
// Relasi Asosiasi:
// Hubungan bersifat 'use-a' (menggunakan). Pengemudi tidak memiliki (has-a)
// kendaraan secara permanen sebagai atribut. Objek KendaraanPengiriman hanya
// diterima sebagai parameter sementara pada method 'tampilkanTugas(kendaraan)'.
class Pengemudi {
    private:
        // Atribut unik nomor identifikasi registrasi pengemudi/operator
        string idPengemudi;

        // Atribut nama lengkap pengemudi/operator
        string nama;

        // Atribut nomor sertifikasi lisensi kemudi (SIM B2 / Lisensi Pelaut / ATPL)
        string nomorLisensi;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // --------------------------------------------------------------------

        // Konstruktor default: menginisialisasi atribut pengemudi dengan string kosong
        Pengemudi() {
            this->idPengemudi = "";
            this->nama = "";
            this->nomorLisensi = "";
        }

        // Konstruktor berparameter lengkap: mengisi data ID, nama, dan lisensi kemudi
        Pengemudi(string idPengemudi, string nama, string nomorLisensi) {
            this->idPengemudi = idPengemudi;
            this->nama = nama;
            this->nomorLisensi = nomorLisensi;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data)
        // --------------------------------------------------------------------

        // Mengambil nomor identitas registrasi pengemudi
        string getIdPengemudi() const {
            return this->idPengemudi;
        }

        // Mengambil nama lengkap personil pengemudi
        string getNama() const {
            return this->nama;
        }

        // Mengambil nomor sertifikasi lisensi kemudi pengemudi
        string getNomorLisensi() const {
            return this->nomorLisensi;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data)
        // --------------------------------------------------------------------

        // Mengubah nomor identitas registrasi pengemudi
        void setIdPengemudi(const string& idPengemudi) {
            this->idPengemudi = idPengemudi;
        }

        // Mengubah nama lengkap personil pengemudi
        void setNama(const string& nama) {
            this->nama = nama;
        }

        // Mengubah nomor sertifikasi lisensi kemudi pengemudi
        void setNomorLisensi(const string& nomorLisensi) {
            this->nomorLisensi = nomorLisensi;
        }

        // --------------------------------------------------------------------
        // METHOD SPESIFIK: PEMBUKTIAN ASOSIASI (ASSOCIATION)
        // --------------------------------------------------------------------

        // Method pembuktian asosiasi: menerima objek KendaraanPengiriman sebagai parameter sementara
        // Menampilkan identitas pengemudi beserta kendaraan yang sedang ditugaskan kepadanya (ID & Model)
        void tampilkanTugas(const KendaraanPengiriman& kendaraan) const {
            cout << "  [Operator / Pengemudi]" << endl;
            cout << "    ID Pengemudi        : " << this->idPengemudi << endl;
            cout << "    Nama Pengemudi      : " << this->nama << endl;
            cout << "    Nomor Lisensi       : " << this->nomorLisensi << endl;
            cout << "    Penugasan Kendaraan : " << kendaraan.getIdKendaraan() << " (" << kendaraan.getMerkModel() << ")" << endl;
            cout << "  -------------------------------------------------------" << endl;
        }

        // Overload method asosiasi: menerima pointer KendaraanPengiriman
        void tampilkanTugas(const KendaraanPengiriman* kendaraan) const {
            if (kendaraan != nullptr) {
                this->tampilkanTugas(*kendaraan);
            }
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor: membersihkan alokasi objek Pengemudi
        ~Pengemudi() {
        }
};
