# 1. Data Sistem Fuzzy

- **Input 1** : Disiplin X ∈ [1,10]
- **Input 2** : Produktivitas Y ∈ [1,10]
- **Output**  : Kinerja Z ∈ [10,90]

Fuzzy set (triangular):

- Disiplin: Rendah (DL), Sedang (DM), Tinggi (DH)
- Produktivitas: Rendah (PL), Sedang (PM), Tinggi (PH)
- Kinerja: Rendah (KL), Sedang (KM), Tinggi (KH)

---

# 2. Fungsi Keanggotaan

## 2.1. Disiplin (X)

### Disiplin Rendah (DL = [1,3,5])

| Kondisi | Nilai μ_DL(X) |
|---------|----------------|
| X ≤ 1 | 0 |
| 1 < X ≤ 3 | (X − 1) / (3 − 1) |
| 3 < X < 5 | (5 − X) / (5 − 3) |
| X ≥ 5 | 0 |

---

### Disiplin Sedang (DM = [3,5,7])

| Kondisi | Nilai μ_DM(X) |
|---------|----------------|
| X ≤ 3 | 0 |
| 3 < X ≤ 5 | (X − 3) / (5 − 3) |
| 5 < X < 7 | (7 − X) / (7 − 5) |
| X ≥ 7 | 0 |

---

### Disiplin Tinggi (DH = [5,7,9])

| Kondisi | Nilai μ_DH(X) |
|---------|----------------|
| X ≤ 5 | 0 |
| 5 < X ≤ 7 | (X − 5) / (7 − 5) |
| 7 < X < 9 | (9 − X) / (9 − 7) |
| X ≥ 9 | 0 |

---

## 2.2. Produktivitas (Y)

### Produktivitas Rendah (PL = [1,3,5])

| Kondisi | Nilai μ_PL(Y) |
|---------|----------------|
| Y ≤ 1 | 0 |
| 1 < Y ≤ 3 | (Y − 1) / (3 − 1) |
| 3 < Y < 5 | (5 − Y) / (5 − 3) |
| Y ≥ 5 | 0 |

---

### Produktivitas Sedang (PM = [3,5,7])

| Kondisi | Nilai μ_PM(Y) |
|---------|----------------|
| Y ≤ 3 | 0 |
| 3 < Y ≤ 5 | (Y − 3) / (5 − 3) |
| 5 < Y < 7 | (7 − Y) / (7 − 5) |
| Y ≥ 7 | 0 |

---

### Produktivitas Tinggi (PH = [5,7,9])

| Kondisi | Nilai μ_PH(Y) |
|---------|----------------|
| Y ≤ 5 | 0 |
| 5 < Y ≤ 7 | (Y − 5) / (7 − 5) |
| 7 < Y < 9 | (9 − Y) / (9 − 7) |
| Y ≥ 9 | 0 |

---

## 2.3. Kinerja (Z)

### Kinerja Rendah (KL = [10,30,50])

| Kondisi | Nilai μ_KL(Z) |
|---------|----------------|
| Z ≤ 10 | 0 |
| 10 < Z ≤ 30 | (Z − 10) / (30 − 10) |
| 30 < Z < 50 | (50 − Z) / (50 − 30) |
| Z ≥ 50 | 0 |

---

### Kinerja Sedang (KM = [30,50,70])

| Kondisi | Nilai μ_KM(Z) |
|---------|----------------|
| Z ≤ 30 | 0 |
| 30 < Z ≤ 50 | (Z − 30) / (50 − 30) |
| 50 < Z < 70 | (70 − Z) / (70 − 50) |
| Z ≥ 70 | 0 |

---

### Kinerja Tinggi (KH = [50,70,90])

| Kondisi | Nilai μ_KH(Z) |
|---------|----------------|
| Z ≤ 50 | 0 |
| 50 < Z ≤ 70 | (Z − 50) / (70 − 50) |
| 70 < Z < 90 | (90 − Z) / (90 − 70) |
| Z ≥ 90 | 0 |

---

# 3. Rule Fuzzy

| No | Rule Bahasa | Bentuk IF–THEN |
|----|-------------|----------------|
| R1 | D rendah & P rendah → K rendah | IF DL AND PL THEN KL |
| R2 | D rendah & P sedang → K rendah | IF DL AND PM THEN KL |
| R3 | D rendah & P tinggi → K sedang | IF DL AND PH THEN KM |
| R4 | D sedang & P rendah → K rendah | IF DM AND PL THEN KL |
| R5 | D sedang & P sedang → K sedang | IF DM AND PM THEN KM |
| R6 | D sedang & P tinggi → K tinggi | IF DM AND PH THEN KH |
| R7 | D tinggi & P rendah → K sedang | IF DH AND PL THEN KM |
| R8 | D tinggi & P sedang → K tinggi | IF DH AND PM THEN KH |
| R9 | D tinggi & P tinggi → K tinggi | IF DH AND PH THEN KH |

---

# 4. Fuzzifikasi (X = 6, Y = 4)

## Disiplin X = 6
- μ_DL(6) = 0
- μ_DM(6) = (7 − 6) / (7 − 5) = 0.5
- μ_DH(6) = (6 − 5) / (7 − 5) = 0.5

## Produktivitas Y = 4
- μ_PL(4) = (5 − 4) / (5 − 3) = 0.5
- μ_PM(4) = (4 − 3) / (5 − 3) = 0.5
- μ_PH(4) = 0

---

# 5. Nilai α Rule (Inferensi)

α_i = min(μ_D , μ_P)

- R1 = 0
- R2 = 0
- R3 = 0
- R4 = 0.5
- R5 = 0.5
- R6 = 0
- R7 = 0.5
- R8 = 0.5
- R9 = 0

Rule aktif: **R4, R5, R7, R8**

---

# 6. Metode MAMDANI

## 6.1. Clipping Output
- KL → dipotong pada 0.5
- KM → dipotong pada 0.5
- KH → dipotong pada 0.5

## 6.2. Centroid Per Label
Centroid:
- KL → 30
- KM → 50
- KH → 70

Hitungan:

Z = (0.5×30 + 0.5×50 + 0.5×70) / (0.5+0.5+0.5)
Z = (15 + 25 + 35) / 1.5 = 50

**Hasil Mamdani = 50**

---

# 7. Metode Sugeno (Orde 0)

Konsekuen:
- KL → 30
- KM → 50
- KH → 70

Rule aktif:
- R4 → 0.5, 30
- R5 → 0.5, 50
- R7 → 0.5, 50
- R8 → 0.5, 70

Weighted Average:

Z = (0.5×30 + 0.5×50 + 0.5×50 + 0.5×70) / 2
Z = 100 / 2 = 50

**Hasil Sugeno = 50**

