# ============================================================================
# KELAS: DepoLogistik (Kelas Pengelola)
# Konsep: Agregasi (Aggregation) & Array of Objects
# ============================================================================
# DepoLogistik mengelola sekumpulan kendaraan dan paket yang ditempatkan di suatu kota.
# Penerapan Konsep:
# 1. Agregasi: Depo memiliki hubungan kepemilikan bebas (has-a) dengan kendaraan
#    dan paket. Depo hanya menyimpan referensi objek. Jika objek Depo
#    dihancurkan/ditutup, kendaraan dan paket tetap ada dan dapat dialokasikan ke depo lain.
# 2. Array of Objects: Menggunakan list objek terpisah untuk tiap kelas:
#    - daftarTruk    : Array of TrukKargo
#    - daftarKapal   : Array of KapalLaut
#    - daftarPesawat : Array of PesawatKargo
#    - daftarPaket   : Array of Paket
# ============================================================================

class DepoLogistik:
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter: menginisialisasi kode depo dan kota lokasi
    def __init__(self, kodeDepo="", kotaLokasi=""):
        # Atribut kode identifikasi unik fasilitas depo logistik (cth: DPO-SUB-01)
        self.__kodeDepo = kodeDepo

        # Atribut nama kota operasional lokasi fasilitas depo berada (cth: Surabaya)
        self.__kotaLokasi = kotaLokasi

        # Array of Objects: kumpulan referensi ke kendaraan Truk Kargo (Agregasi)
        self.__daftarTruk = []

        # Array of Objects: kumpulan referensi ke kendaraan Kapal Laut (Agregasi)
        self.__daftarKapal = []

        # Array of Objects: kumpulan referensi ke kendaraan Pesawat Kargo (Agregasi)
        self.__daftarPesawat = []

        # Array of Objects: kumpulan referensi ke paket logistik (Agregasi)
        self.__daftarPaket = []

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data Sesuai Desain)
    # ------------------------------------------------------------------------

    # Mengambil informasi kode unik depo
    def getKodeDepo(self):
        return self.__kodeDepo

    # Mengambil informasi nama kota lokasi fasilitas depo
    def getKotaLokasi(self):
        return self.__kotaLokasi

    # Mengambil daftar referensi seluruh kendaraan truk yang ada di depo
    def getDaftarTruk(self):
        return self.__daftarTruk

    # Mengambil daftar referensi seluruh kendaraan kapal yang ada di depo
    def getDaftarKapal(self):
        return self.__daftarKapal

    # Mengambil daftar referensi seluruh kendaraan pesawat yang ada di depo
    def getDaftarPesawat(self):
        return self.__daftarPesawat

    # Mengambil daftar referensi seluruh paket kiriman yang ada di depo
    def getDaftarPaket(self):
        return self.__daftarPaket

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data Sesuai Desain)
    # ------------------------------------------------------------------------

    # Mengubah informasi kode unik fasilitas depo
    def setKodeDepo(self, kodeDepo):
        self.__kodeDepo = kodeDepo

    # Mengubah informasi nama kota lokasi fasilitas depo
    def setKotaLokasi(self, kotaLokasi):
        self.__kotaLokasi = kotaLokasi

    # Mengganti seluruh daftar referensi kendaraan truk di depo
    def setDaftarTruk(self, daftarTruk):
        self.__daftarTruk = list(daftarTruk)

    # Mengganti seluruh daftar referensi kendaraan kapal di depo
    def setDaftarKapal(self, daftarKapal):
        self.__daftarKapal = list(daftarKapal)

    # Mengganti seluruh daftar referensi kendaraan pesawat di depo
    def setDaftarPesawat(self, daftarPesawat):
        self.__daftarPesawat = list(daftarPesawat)

    # Mengganti seluruh daftar referensi paket kiriman di depo
    def setDaftarPaket(self, daftarPaket):
        self.__daftarPaket = list(daftarPaket)

    # ------------------------------------------------------------------------
    # METHOD PENAMBAHAN DATA SATUAN (HELPER OPERASIONAL)
    # ------------------------------------------------------------------------

    # Menambahkan satu objek referensi kendaraan Truk Kargo ke dalam depo (Agregasi)
    def tambahTruk(self, truk):
        if truk is not None:
            self.__daftarTruk.append(truk)

    # Menambahkan satu objek referensi kendaraan Kapal Laut ke dalam depo (Agregasi)
    def tambahKapal(self, kapal):
        if kapal is not None:
            self.__daftarKapal.append(kapal)

    # Menambahkan satu objek referensi kendaraan Pesawat Kargo ke dalam depo (Agregasi)
    def tambahPesawat(self, pesawat):
        if pesawat is not None:
            self.__daftarPesawat.append(pesawat)

    # Menambahkan satu objek referensi Paket kiriman ke dalam depo (Agregasi)
    def tambahPaket(self, paket):
        if paket is not None:
            self.__daftarPaket.append(paket)

    # ------------------------------------------------------------------------
    # METHOD OPERASIONAL: TAMPILKAN STATUS RINGKASAN DEPO
    # ------------------------------------------------------------------------

    # Menampilkan informasi umum dan rekapitulasi jumlah kendaraan serta paket pada fasilitas depo
    def tampilkanInformasiDepo(self):
        total_kendaraan = len(self.__daftarTruk) + len(self.__daftarKapal) + len(self.__daftarPesawat)
        print(f"Kode Depo       : {self.__kodeDepo}")
        print(f"Kota Lokasi     : {self.__kotaLokasi}")
        print(f"Total Kendaraan : {total_kendaraan} unit ({len(self.__daftarTruk)} Truk, {len(self.__daftarKapal)} Kapal, {len(self.__daftarPesawat)} Pesawat)")
        print(f"Total Paket     : {len(self.__daftarPaket)} paket kiriman")
