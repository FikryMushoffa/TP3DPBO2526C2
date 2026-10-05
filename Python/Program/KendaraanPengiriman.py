# ============================================================================
# KELAS: KendaraanPengiriman (Kelas Induk / Base Class)
# Konsep: Hierarchical Inheritance, Komposisi, Polimorfisme
# ============================================================================
# Kelas ini mendefinisikan karakteristik dasar seluruh moda transportasi logistik.
# Menerapkan:
# 1. Komposisi: Memiliki atribut 'mesin' bertipe MesinKendaraan yang terikat erat.
# 2. Hierarchical Inheritance: Menjadi induk bagi TrukKargo, KapalLaut, PesawatKargo.
# 3. Polimorfisme: Menyediakan method 'tampilkanSpesifikasi()' untuk dioverride kelas anak.
# ============================================================================

from MesinKendaraan import MesinKendaraan

class KendaraanPengiriman:
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter: menginisialisasi atribut induk dan komponen mesin
    def __init__(self, idKendaraan="", merkModel="", mesin=None):
        # Atribut hak akses protected agar dapat diakses langsung oleh kelas turunan
        # Kode unik identifikasi kendaraan (cth: TRK-001, KPL-101, PSW-201)
        self._idKendaraan = idKendaraan

        # Merk dan nama model manufaktur kendaraan (cth: Hino Ranger, KM Meratus)
        self._merkModel = merkModel

        # Objek komponen mesin (Komposisi: terikat erat dengan siklus hidup kendaraan)
        self._mesin = mesin if mesin is not None else MesinKendaraan()

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data)
    # ------------------------------------------------------------------------

    # Mengambil nilai ID kendaraan
    def getIdKendaraan(self):
        return self._idKendaraan

    # Mengambil nilai merk dan nama model kendaraan
    def getMerkModel(self):
        return self._merkModel

    # Mengambil objek komponen mesin kendaraan
    def getMesin(self):
        return self._mesin

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data)
    # ------------------------------------------------------------------------

    # Mengubah nilai ID kendaraan
    def setIdKendaraan(self, idKendaraan):
        self._idKendaraan = idKendaraan

    # Mengubah nilai merk dan model kendaraan
    def setMerkModel(self, merkModel):
        self._merkModel = merkModel

    # Mengubah objek mesin kendaraan
    def setMesin(self, mesin):
        self._mesin = mesin

    # ------------------------------------------------------------------------
    # METHOD SPESIFIK & POLIMORFISME
    # ------------------------------------------------------------------------

    # Method polimorfik dasar untuk menampilkan spesifikasi umum kendaraan
    # Method ini dioverride oleh kelas-kelas turunan (Truk, Kapal, Pesawat)
    def tampilkanSpesifikasi(self):
        print("[Kendaraan Pengiriman Umum]")
        print(f"  ID Kendaraan    : {self._idKendaraan}")
        print(f"  Merk & Model    : {self._merkModel}")
        print(f"  Detail Mesin    : Seri {self._mesin.getNomorSeriMesin()} | {self._mesin.getTipeMesin()} | Bahan Bakar: {self._mesin.getJenisBahanBakar()}")
