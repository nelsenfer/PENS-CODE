# Balatro - Chain of Responsibility

Proyek ini adalah implementasi sederhana mekanisme poker ala Balatro menggunakan
C++ dan design pattern Chain of Responsibility. Program menggunakan deck standar
52 kartu, memilih kartu secara otomatis, mengevaluasi kombinasi poker, menghitung
score `Chips x Mult`, lalu memproses Joker, Blind, dan reward.

## Alur Permainan

Setiap ronde menjalankan urutan berikut:

```text
Generate 8 kartu
    -> Pilih 5 kartu terbaik dari 56 kombinasi
    -> Evaluasi kombinasi dengan Chain of Responsibility
    -> Hitung Chips x Mult
    -> Joker menambahkan bonus Mult
    -> Cek Blind
    -> Berikan reward atau Game Over
```

### 1. Generate Hand

`HandGenerator` membuat deck standar berisi 52 kartu dari empat suit
(`Hearts`, `Diamonds`, `Clubs`, `Spades`) dan rank 2 sampai Ace. Deck diacak,
lalu 8 kartu diambil tanpa duplikasi. Kartu yang sudah diambil dikeluarkan dari
deck dan deck di-reset jika kartu tersisa kurang dari 8.

### 2. Choose/Play Hand

`HandSelector::playHand()` membuat seluruh kombinasi 5 kartu dari 8 kartu
tersedia:

```text
C(8, 5) = 56 kombinasi
```

Setiap kombinasi dikirim ke checker. Kombinasi dengan `HandRank` tertinggi
dipilih. Jika rank sama, nilai rank kartu tertinggi digunakan sebagai
tie-breaker.

### 3. Evaluasi Chain

Urutan Chain harus tetap dari kombinasi tertinggi ke terendah:

```text
Flush Five
Flush House
Five of a Kind
Royal Flush
Straight Flush
Four of a Kind
Full House
Flush
Straight
Three of a Kind
Two Pair
Pair
High Card
```

Untuk satu kombinasi, chain berhenti ketika checker menemukan hasil yang cocok.
Selector tetap memeriksa kombinasi lain karena hasil yang lebih tinggi mungkin
ada pada kombinasi berikutnya.

### 4. Scoring

`ScoringRule` menggunakan rumus:

```text
Total Score = (Base Chips + nilai kartu dimainkan) x Mult
```

J, Q, K, dan Ace dihitung sebagai 10 Chips. Nilai dasar `Chips` dan `Mult`
berbeda untuk setiap kombinasi poker.

### 5. Joker

`JokerCard` menerima notifikasi setelah hand dimainkan:

```cpp
jokerCard.onHandPlayed(score);
score = jokerCard.modifyScore(score);
```

Joker sederhana yang digunakan saat ini memberikan bonus `+1 Mult`. Bonus
diterapkan sebelum Blind diperiksa.

### 6. Blind dan Reward

`BlindRule` menentukan kemenangan berdasarkan total score. Jika menang,
`RewardRule` menambahkan money. Jika gagal melewati Blind, ronde dihentikan dan
game berakhir.

## Struktur File

### Model Data

- `Card.h`: `Suit`, `Rank`, `Card`, dan fungsi format nama kartu.
- `Hand.h`: `HandRank`, `Hand`, dan `EvaluationResult`.

### Pembuatan dan Pemilihan Kartu

- `HandGenerator.h/.cpp`: membuat dan mengacak deck serta menghasilkan 8 kartu.
- `HandSelector.h/.cpp`: memeriksa 56 kombinasi dan memilih 5 kartu terbaik.

### Evaluasi Kartu

- `HandChecker.h/.cpp`: deklarasi dan implementasi Chain of Responsibility.

### Aturan Permainan

- `GameRules.h/.cpp`: scoring, Blind, dan reward.
- `JokerCard.h/.cpp`: modifier Joker.

### Game Loop

- `GameManager.h/.cpp`: mengatur urutan seluruh fase permainan.
- `main.cpp`: membuat checker dan menyusun chain.

Header dan source dipisahkan. `main.cpp` tidak meng-include file `.cpp`;
seluruh source dikompilasi bersama.

## Kompilasi dan Menjalankan Program

Dari folder proyek:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic *.cpp -o main.exe
main.exe
```

Program menampilkan:

- 8 `availableCards`.
- 5 `playedCards`.
- Kombinasi yang ditemukan.
- Chips, Mult, dan total score.
- Status Blind.
- Reward dan total money.

## Invariants

Komponen berikut harus dipertahankan:

1. Urutan Chain dari `Flush Five` sampai `High Card`.
2. Semua kombinasi 5 kartu dari 8 kartu harus dipertimbangkan.
3. Checker hanya mengevaluasi kartu dan tidak mengubah `playedCards`.
4. `GameManager` menjalankan urutan generate, select, evaluate, score, Joker,
   Blind, dan reward.
5. Tidak boleh ada kartu duplikat dalam hand yang dihasilkan.

## Komponen yang Dapat Dikembangkan

- Menambah checker baru dengan menempatkannya pada posisi yang tepat di chain.
- Mengubah nilai base Chips, Mult, Blind, atau reward.
- Menambah jenis Joker baru melalui `JokerCard`.
- Mengembangkan efek kartu, discard, upgrade, atau sistem shop.
