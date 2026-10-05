# ============================================================================
# KELAS: Paket (Kelas Data)
# Konsep: Entitas Data & Agregasi (Aggregated Entity)
# ============================================================================
# Kelas Paket merepresentasikan data kargo/barang kiriman yang dikelola oleh depo
# logistik. Paket memiliki siklus hidup independen dan diagregasikan oleh DepoLogistik.
# ============================================================================

class Paket:
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter: mengisi data resi, berat, dan deskripsi paket
    def __init__(self, nomorResi="", beratKg=0.0, deskripsiBarang=""):
        # Atribut unik nomor pelacakan resi kiriman (cth: PKG-ID-2026-001)
        self.__nomorResi = nomorResi

        # Atribut berat fisik kargo barang (satuan kilogram)
        self.__beratKg = float(beratKg)

        # Atribut deskripsi / manifest kategori muatan barang
        self.__deskripsiBarang = deskripsiBarang

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data)
    # ------------------------------------------------------------------------

    # Mengambil informasi nomor resi paket
    def getNomorResi(self):
        return self.__nomorResi

    # Mengambil informasi berat fisik paket (kg)
    def getBeratKg(self):
        return self.__beratKg

    # Mengambil informasi rincian deskripsi barang kiriman
    def getDeskripsiBarang(self):
        return self.__deskripsiBarang

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data)
    # ------------------------------------------------------------------------

    # Mengubah nomor resi paket
    def setNomorResi(self, nomorResi):
        self.__nomorResi = nomorResi

    # Mengubah berat fisik paket (kg)
    def setBeratKg(self, beratKg):
        self.__beratKg = float(beratKg)

    # Mengubah rincian deskripsi barang kiriman
    def setDeskripsiBarang(self, deskripsiBarang):
        self.__deskripsiBarang = deskripsiBarang
