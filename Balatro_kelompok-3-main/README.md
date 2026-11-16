Task - Chain of Responsibility: Balatro

Proyek ini adalah implementasi sistem pengecekan kombinasi kartu (Poker Hand Checker) yang terinspirasi dari mekanisme game Balatro. Sistem ini dibangun menggunakan design pattern Chain of Responsibility di C++ untuk memastikan evaluasi kartu berjalan efisien, modular, dan mudah dikembangkan.

1. Core Loop

Fase permainan dalam Game Manager berjalan secara berurutan pada setiap rondenya:

Hand Generation Phase: Sistem (HandGenerator) mengacak deck standar 52 kartu dan menghasilkan 8 kartu unik untuk pemain pada ronde tersebut.

Hand Selection Phase: HandSelector memeriksa seluruh 56 kombinasi 5 kartu dari 8 kartu yang tersedia melalui rantai checker, lalu memilih kombinasi dengan HandRank tertinggi.

Hand Evaluation Phase: Lima kartu terpilih dievaluasi kembali oleh rantai PokerHandChecker (bergerak dari kombinasi tertinggi hingga terendah).

Scoring Phase: Sistem (ScoringRule) menghitung `Chips` dari base hand dan nilai kartu yang dimainkan, lalu mengalikannya dengan `Mult` dasar kombinasi (`Chips x Mult`).

Joker Phase: JokerCard menerima notifikasi ketika hand dimainkan dan menambahkan bonus `+1 Mult` sebelum Blind diperiksa.

Blind Check Phase: Sistem (BlindRule) mengecek apakah skor yang diraih memenuhi target Blind untuk memenangkan ronde tersebut.

Reward & Resolution Phase: Pemain mendapatkan uang (RewardRule) jika berhasil lolos Blind, atau Game Over jika gagal.

Struktur file dipisahkan antara deklarasi header dan implementasi source:

- `Card.h` dan `Hand.h`: model kartu dan hand.
- `HandChecker.h/.cpp`: Chain of Responsibility.
- `HandGenerator.h/.cpp`: pembuatan deck dan 8 kartu.
- `HandSelector.h/.cpp`: pemilihan otomatis 5 kartu terbaik.
- `GameRules.h/.cpp`: scoring, Blind, dan reward.
- `JokerCard.h/.cpp`: modifier Joker.
- `GameManager.h/.cpp`: orkestrasi game loop.
- `main.cpp`: penyusunan chain dan entry point.

2. Invariants (Komponen yang Tidak Boleh Berubah)

Urutan Pengecekan Kartu (Chain Order):
Rantai checker TIDAK BOLEH dibalik atau diacak. Evaluasi harus selalu dimulai dari kombinasi tertinggi (Flush Five) turun hingga ke terendah (High Card).

Urutan Core Loop:
Kartu harus di-generate -> Dievaluasi -> Dihitung Skornya -> Dicek terhadap Blind -> Diberikan Reward. Urutan eksekusi ini absolut.

Apa yang rusak jika urutannya diubah?
Jika urutan Chain of Responsibility diubah (misalnya PairChecker diletakkan sebelum FullHouseChecker), maka saat pemain memiliki kartu Full House, sistem akan langsung mendeteksinya sebagai Pair dan menghentikan pengecekan. Hal ini akan merusak logika fundamental permainan Poker.

3. Mutable Elements (Komponen Fleksibel)

Internal Checker Logic (Logika Validasi Kombinasi):
Cara setiap kelas (seperti FlushChecker atau StraightChecker) memvalidasi isi vektor kartu bebas dimodifikasi tanpa mengganggu rantai utama.

Aturan Permainan (Scoring, Blind, Reward):
Angka target Blind, rumus perhitungan poin di ScoringRule, dan kalkulasi uang di RewardRule adalah komponen yang sangat fleksibel (mutable) dan bisa diganti untuk melakukan balancing pada gameplay.

Mekanisme Generasi Kartu:
Logika di dalam HandGenerator bebas diubah, misalnya dari sekadar simulasi nilai acak menjadi sistem deck kartu yang sesungguhnya (tarik kartu, discard, dll).

4. Technical Reflection

1. Apa struktur invariant dari game kamu?
Struktur invariant di proyek ini adalah arsitektur Chain of Responsibility pada pengecekan kartu dan core loop pertarungan di GameManager. Pengecekan wajib mengalir satu arah ke bawah hingga ada node yang berhasil mengidentifikasi kartu. Pemanggilan antar-objek dalam putaran juga bersifat kaku: kita tidak mungkin mengecek Blind (syarat menang) sebelum mengetahui hasil evaluasi kartu dan skornya.

2. Bagian mana yang mutable?
Bagian yang mutable adalah implementasi detail (logika di dalam fungsi override) dari setiap node checker, serta parameter-parameter skor/uang. Antarmuka PokerHandChecker menyembunyikan bagaimana sebuah Flush dicek, sehingga kita bisa bebas merombak algoritma pencarian suit kartu di dalam FlushChecker tanpa harus menyentuh kelas GameManager.

3. Jika ingin menambah fitur baru, kelas mana yang akan berubah?
Jika saya ingin menambah kombinasi kartu rahasia baru (misalnya "Giga Flush"), saya tidak perlu mengedit GameManager. Saya hanya perlu membuat kelas GigaFlushChecker baru yang mewarisi PokerHandChecker, lalu menyisipkannya ke urutan teratas di dalam fungsi main(). Ini sangat sejalan dengan prinsip Open-Closed (terbuka untuk ekstensi, tertutup untuk modifikasi).

4. Jika urutan loop diubah, apa yang akan rusak?
Seperti yang dijelaskan pada bagian Invariant, mengubah hierarki Chain of Responsibility akan menghancurkan sistem hierarki nilai Poker (kartu kuat dianggap kartu lemah). Selain itu, mengacak urutan runSession() di GameManager (misalnya menghitung skor sebelum mengecek kartu) akan membuat game crash atau menghasilkan status data yang tidak valid (garbage value).