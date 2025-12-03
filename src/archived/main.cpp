#include <iostream>
#include <algorithm> // std::min, std::max
using namespace std;

// ---------- Fungsi keanggotaan DISIPLIN & PRODUKTIVITAS ----------
float mu_rendah(float x)
{
    if (x <= 3)
        return 1.0;
    else if (x > 3 && x < 5)
        return (5.0f - x) / (5.0f - 3.0f);
    else
        return 0.0;
}

float mu_sedang(float x)
{
    if (x <= 3)
        return 0.0;
    else if (x > 3 && x < 5)
        return (x - 3.0f) / (5.0f - 3.0f);
    else if (x == 5)
        return 1.0;
    else if (x > 5 && x < 7)
        return (7.0f - x) / (7.0f - 5.0f);
    else
        return 0.0;
}

float mu_tinggi(float x)
{
    if (x <= 7)
        return 0.0;
    else if (x > 7 && x < 9)
        return (x - 7.0f) / (9.0f - 7.0f);
    else if (x == 9)
        return 1.0;
    else
        return 1.0;
}

// ---------- MAIN ----------
int main()
{
    float D, P;
    cout << "Input Disiplin (1-10) : ";
    cin >> D;
    cout << "Input Produktivitas (1-10) : ";
    cin >> P;

    // 1. Fuzzifikasi
    float D_r = mu_rendah(D);
    float D_s = mu_sedang(D);
    float D_t = mu_tinggi(D);

    float P_r = mu_rendah(P);
    float P_s = mu_sedang(P);
    float P_t = mu_tinggi(P);

    cout << "\n=== Fuzzifikasi ===\n";
    cout << "Disiplin Rendah : " << D_r << endl;
    cout << "Disiplin Sedang : " << D_s << endl;
    cout << "Disiplin Tinggi : " << D_t << endl;

    cout << "Produktivitas Rendah : " << P_r << endl;
    cout << "Produktivitas Sedang : " << P_s << endl;
    cout << "Produktivitas Tinggi : " << P_t << endl;

    // 2. Hitung predikat (MIN) untuk 9 rule
    // Contoh rule yang sama seperti sebelumnya:
    // 1) D rendah & P rendah -> Kinerja rendah
    // 2) D rendah & P sedang -> Kinerja rendah
    // 3) D rendah & P tinggi -> Kinerja sedang
    // 4) D sedang & P rendah -> Kinerja rendah
    // 5) D sedang & P sedang -> Kinerja sedang
    // 6) D sedang & P tinggi -> Kinerja tinggi
    // 7) D tinggi & P rendah -> Kinerja sedang
    // 8) D tinggi & P sedang -> Kinerja tinggi
    // 9) D tinggi & P tinggi -> Kinerja tinggi

    float a1 = min(D_r, P_r); // rendah
    float a2 = min(D_r, P_s); // rendah
    float a3 = min(D_r, P_t); // sedang
    float a4 = min(D_s, P_r); // rendah
    float a5 = min(D_s, P_s); // sedang
    float a6 = min(D_s, P_t); // tinggi
    float a7 = min(D_t, P_r); // sedang
    float a8 = min(D_t, P_s); // tinggi
    float a9 = min(D_t, P_t); // tinggi

    cout << "\n=== Predikat Rule (alpha) ===\n";
    cout << "a1 = " << a1 << endl;
    cout << "a2 = " << a2 << endl;
    cout << "a3 = " << a3 << endl;
    cout << "a4 = " << a4 << endl;
    cout << "a5 = " << a5 << endl;
    cout << "a6 = " << a6 << endl;
    cout << "a7 = " << a7 << endl;
    cout << "a8 = " << a8 << endl;
    cout << "a9 = " << a9 << endl;

    // 3. Kelompokkan alpha ke output:
    // Misal titik wakil (crisp) kinerja:
    // rendah = 35, sedang = 60, tinggi = 85
    float y_r = 35.0f;
    float y_s = 60.0f;
    float y_t = 85.0f;

    // Ambil alpha maksimum untuk tiap output (Mamdani, agregasi by max)
    float alpha_rendah = max(a1, max(a2, a4));
    float alpha_sedang = max(a3, max(a5, a7));
    float alpha_tinggi = max(a6, max(a8, a9));

    cout << "\n=== Alpha per Output ===\n";
    cout << "Kinerja Rendah : " << alpha_rendah << endl;
    cout << "Kinerja Sedang : " << alpha_sedang << endl;
    cout << "Kinerja Tinggi : " << alpha_tinggi << endl;

    // 4. Defuzzifikasi (rata-rata terbobot)
    float pembilang = alpha_rendah * y_r +
                      alpha_sedang * y_s +
                      alpha_tinggi * y_t;

    float penyebut = alpha_rendah + alpha_sedang + alpha_tinggi;

    float y_star = 0.0f;
    if (penyebut != 0)
        y_star = pembilang / penyebut;

    cout << "\n=== Defuzzifikasi (output kinerja) ===\n";
    cout << "Kinerja crisp = " << y_star << endl;

    return 0;
}