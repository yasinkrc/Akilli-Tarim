#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

const int tarlaSayisi = 6;

struct Tarla {
    int numara;
    bool sulama;
    bool ilaclama;
    bool gubreleme;
    bool capalama;
};

struct TarlaKarsilastir {
    bool operator()(const Tarla& t1, const Tarla& t2) {
        // İlaçlama > Çapalama > Gübreleme > Sulama önceliği
        if (t1.ilaclama != t2.ilaclama) {
            return t1.ilaclama > t2.ilaclama;
        }
        if (t1.capalama != t2.capalama) {
            return t1.capalama > t2.capalama;
        }
        if (t1.gubreleme != t2.gubreleme) {
            return t1.gubreleme > t2.gubreleme;
        }
        return t1.sulama > t2.sulama;
    }
};

class Graf {
    int** komsuMatrisi;
    int boyut;

public:
    Graf(int boyut) {
        this->boyut = boyut;
        komsuMatrisi = new int*[boyut];
        for (int i = 0; i < boyut; i++) {
            komsuMatrisi[i] = new int[boyut];
        }
    }

    void kenarEkle(int kaynak, int hedef, int maliyet) {
        komsuMatrisi[kaynak][hedef] = maliyet;
        komsuMatrisi[hedef][kaynak] = maliyet;
    }

    int enKisaYol(int kaynak, int hedef) {
        vector<int> mesafe(boyut, INT_MAX);
        mesafe[kaynak] = 0;

        vector<bool> ziyaretEdildi(boyut, false);

        for (int i = 0; i < boyut - 1; i++) {
            int minMesafe = INT_MAX;
            int minDugum = -1;

            for (int j = 0; j < boyut; j++) {
                if (!ziyaretEdildi[j] && mesafe[j] < minMesafe) {
                    minMesafe = mesafe[j];
                    minDugum = j;
                }
            }

            if (minDugum == -1) {
                break;
            }

            ziyaretEdildi[minDugum] = true;

            for (int j = 0; j < boyut; j++) {
                if (!ziyaretEdildi[j] && komsuMatrisi[minDugum][j] && mesafe[minDugum] + komsuMatrisi[minDugum][j] < mesafe[j]) {
                    mesafe[j] = mesafe[minDugum] + komsuMatrisi[minDugum][j];
                }
            }
        }

        return mesafe[hedef];
    }
};


int main() {
    Tarla tarlalar[tarlaSayisi];

    tarlalar[0] = {1, true, false, true, true};
    tarlalar[1] = {2, true, true, false, false};
    tarlalar[2] = {3, true, false, false, true};
    tarlalar[3] = {4, true, false, true, false};
    tarlalar[4] = {5, true, true, false, true};
    tarlalar[5] = {6, true, false, false, false};

    Graf graf(tarlaSayisi);
    std::ifstream tarlaDosyasi("tarla.txt");
    if (!tarlaDosyasi) {
        std::cerr << "Tarla dosyası okunamadı." << std::endl;
        return 1;
    }


    for (int i = 0; i < tarlaSayisi; i++) {
        for (int j = 0; j < tarlaSayisi; j++) {
            int weight;
            tarlaDosyasi >> weight;
            if (weight != 0) {
                graf.kenarEkle(i, j, weight);
            }
        }
    }

    tarlaDosyasi.close();

    priority_queue<Tarla, vector<Tarla>, TarlaKarsilastir> tarlaSiralama;
    for (int i = 0; i < tarlaSayisi; i++) {
        tarlaSiralama.push(tarlalar[i]);
    }

    ofstream ciktiDosyasi("traktor_cikti.txt");

    while (!tarlaSiralama.empty()) {
        Tarla tarla = tarlaSiralama.top();
        tarlaSiralama.pop();


        if (tarla.ilaclama) {
            ciktiDosyasi << "Yapılacak işlem: İlaçlama" << endl;
            ciktiDosyasi << "Mevcut konum: " << tarla.numara << ". tarla" << endl;
            ciktiDosyasi << "İlaçlama için en kısa yol: ";
            if (!tarlaSiralama.empty()) {
                int enKisaYol = graf.enKisaYol(tarla.numara - 1, tarlaSiralama.top().numara - 1);
                ciktiDosyasi << tarla.numara << "-" << enKisaYol << "-" << tarlaSiralama.top().numara;
            } else {
                ciktiDosyasi << tarla.numara;
            }
            ciktiDosyasi << endl;
            ciktiDosyasi << "Toplam gidilen: ..." << endl;
            ciktiDosyasi << "İlaçlama bitti" << endl;
        }


        if (tarla.capalama) {
            ciktiDosyasi << "Yapılacak işlem: Çapalama" << endl;
            ciktiDosyasi << "Mevcut konum: " << tarla.numara << ". tarla" << endl;
            ciktiDosyasi << "Çapalama için en kısa yol: ";
            if (!tarlaSiralama.empty()) {
                int enKisaYol = graf.enKisaYol(tarla.numara - 1, tarlaSiralama.top().numara - 1);
                ciktiDosyasi << tarla.numara << "-" << enKisaYol << "-" << tarlaSiralama.top().numara;
            } else {
                ciktiDosyasi << tarla.numara;
            }
            ciktiDosyasi << endl;
            ciktiDosyasi << "Toplam gidilen: ..." << endl;
            ciktiDosyasi << "Çapalama bitti" << endl;
        }

        // Gübreleme işlemini yap
        if (tarla.gubreleme) {
            ciktiDosyasi << "Yapılacak işlem: Gübreleme" << endl;
            ciktiDosyasi << "Mevcut konum: " << tarla.numara << ". tarla" << endl;
            ciktiDosyasi << "Gübreleme için en kısa yol: ";
            if (!tarlaSiralama.empty()) {
                int enKisaYol = graf.enKisaYol(tarla.numara - 1, tarlaSiralama.top().numara - 1);
                ciktiDosyasi << tarla.numara << "-" << enKisaYol << "-" << tarlaSiralama.top().numara;
            } else {
                ciktiDosyasi << tarla.numara;
            }
            ciktiDosyasi << endl;
            ciktiDosyasi << "Toplam gidilen: ..." << endl;
            ciktiDosyasi << "Gübreleme bitti" << endl;
        }

        // Sulama işlemini yap
        if (tarla.sulama) {
            ciktiDosyasi << "Yapılacak işlem: Sulama" << endl;
            ciktiDosyasi << "Mevcut konum: " << tarla.numara << ". tarla" << endl;
            ciktiDosyasi << "Sulama için en kısa yol: ";
            if (!tarlaSiralama.empty()) {
                int enKisaYol = graf.enKisaYol(tarla.numara - 1, tarlaSiralama.top().numara - 1);
                ciktiDosyasi << tarla.numara << "-" << enKisaYol << "-" << tarlaSiralama.top().numara;
            } else {
                ciktiDosyasi << tarla.numara;
            }
            ciktiDosyasi << endl;
            ciktiDosyasi << "Toplam gidilen: ..." << endl;
            ciktiDosyasi << "Sulama bitti" << endl;
        }
    }

    ciktiDosyasi.close();

    return 0;
}


