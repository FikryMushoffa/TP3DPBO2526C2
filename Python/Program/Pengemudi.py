# ============================================================================
# KELAS: Pengemudi (Kelas Operasional)
# Konsep: Asosiasi (Association)
# ============================================================================
# Pengemudi merepresentasikan personil operator/pengemudi kendaraan logistik.
# Relasi Asosiasi:
# Hubungan bersifat 'use-a' (menggunakan). Pengemudi tidak memiliki (has-a)
# kendaraan secara permanen sebagai atribut. Objek KendaraanPengiriman hanya
# diterima sebagai parameter sementara pada method 'tampilkanTugas(kendaraan)'.
# ============================================================================

class Pengemudi:
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter lengkap: mengisi data ID, nama, dan lisensi kemudi
    def __init__(self, idPengemudi="", nama="", nomorLisensi=""):
        # Atribut unik nomor identifikasi registrasi pengemudi/operator
        self.__idPengemudi = idPengemudi

        # Atribut nama lengkap pengemudi/operator
        self.__nama = nama

        # Atribut nomor sertifikasi lisensi kemudi (SIM B2 / Lisensi Pelaut / ATPL)
        self.__nomorLisensi = nomorLisensi

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data)
    # ------------------------------------------------------------------------

    # Mengambil nomor identitas registrasi pengemudi
    def getIdPengemudi(self):
        return self.__idPengemudi

    # Mengambil nama lengkap personil pengemudi
    def getNama(self):
        return self.__nama

    # Mengambil nomor sertifikasi lisensi kemudi pengemudi
    def getNomorLisensi(self):
        return self.__nomorLisensi

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data)
    # ------------------------------------------------------------------------

    # Mengubah nomor identitas registrasi pengemudi
    def setIdPengemudi(self, idPengemudi):
        self.__idPengemudi = idPengemudi

    # Mengubah nama lengkap personil pengemudi
    def setNama(self, nama):
        self.__nama = nama

    # Mengubah nomor sertifikasi lisensi kemudi pengemudi
    def setNomorLisensi(self, nomorLisensi):
        self.__nomorLisensi = nomorLisensi

    # ------------------------------------------------------------------------
    # METHOD SPESIFIK: PEMBUKTIAN ASOSIASI (ASSOCIATION)
    # ------------------------------------------------------------------------

    # Method pembuktian asosiasi: menerima objek KendaraanPengiriman sebagai parameter sementara
    # Menampilkan identitas pengemudi beserta kendaraan yang sedang ditugaskan kepadanya (ID & Model)
    def tampilkanTugas(self, kendaraan):
        if kendaraan is not None:
            print("  [Operator / Pengemudi]")
            print(f"    ID Pengemudi        : {self.__idPengemudi}")
            print(f"    Nama Pengemudi      : {self.__nama}")
            print(f"    Nomor Lisensi       : {self.__nomorLisensi}")
            print(f"    Penugasan Kendaraan : {kendaraan.getIdKendaraan()} ({kendaraan.getMerkModel()})")
            print("  -------------------------------------------------------")
