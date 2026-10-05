# ============================================================================
# KELAS: MesinKendaraan (Kelas Komponen)
# Konsep: Komposisi (Composition Component)
# ============================================================================
# Kelas MesinKendaraan berfungsi sebagai bagian integral/komponen mesin dari
# kendaraan pengiriman. Dalam relasi Komposisi, masa hidup objek mesin terikat
# sepenuhnya pada objek kendaraan yang memilikinya.
# ============================================================================

class MesinKendaraan:
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter: menginisialisasi atribut mesin sesuai argumen input
    def __init__(self, nomorSeriMesin="", tipeMesin="", jenisBahanBakar=""):
        # Atribut nomor seri unik manufaktur mesin
        self.__nomorSeriMesin = nomorSeriMesin

        # Atribut model/tipe konfigurasi mesin (cth: J08E Turbo, CFM56 Turbofan)
        self.__tipeMesin = tipeMesin

        # Atribut tipe bahan bakar yang digunakan mesin (cth: Solar CN-51, Avtur Jet A-1)
        self.__jenisBahanBakar = jenisBahanBakar

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data)
    # ------------------------------------------------------------------------

    # Mengambil informasi nomor seri mesin
    def getNomorSeriMesin(self):
        return self.__nomorSeriMesin

    # Mengambil informasi tipe/konfigurasi mesin
    def getTipeMesin(self):
        return self.__tipeMesin

    # Mengambil informasi jenis bahan bakar mesin
    def getJenisBahanBakar(self):
        return self.__jenisBahanBakar

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data)
    # ------------------------------------------------------------------------

    # Mengubah informasi nomor seri mesin
    def setNomorSeriMesin(self, nomorSeriMesin):
        self.__nomorSeriMesin = nomorSeriMesin

    # Mengubah informasi tipe/konfigurasi mesin
    def setTipeMesin(self, tipeMesin):
        self.__tipeMesin = tipeMesin

    # Mengubah informasi jenis bahan bakar mesin
    def setJenisBahanBakar(self, jenisBahanBakar):
        self.__jenisBahanBakar = jenisBahanBakar
