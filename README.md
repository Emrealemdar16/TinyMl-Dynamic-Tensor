# TinyML Dinamik Tensör Yapısı (C Dili)

Bu proje, RAM kısıtlı gömülü sistemler (Arduino, ESP32 vb.) üzerinde Yapay Zeka (TinyML) modelleri çalıştırabilmek amacıyla tasarlanmış bellek dostu ve dinamik bir tensör veri yapısıdır.

## 🎯 Projenin Amacı ve Sorun
Standart yapay zeka modelleri genellikle 32-bit (Float32) ondalıklı sayılar kullanır. Ancak mikrodenetleyicilerde bu durum belleğin (RAM) saniyeler içinde dolmasına yol açar. Bu projede, standart `float` dizileri yerine duruma göre **32-bit Float**, **16-bit Float** veya **8-bit Integer (Quantized)** saklayabilen esnek bir yapı tasarlanmıştır.

## ⚙️ Teknik Mimari ve Kullanılan Yapılar
* **`union` ve `struct` Kullanımı:** Veriler için ayrı ayrı bellek ayırmak yerine `union` kullanılarak aynı bellek adresi farklı veri tipleri için paylaştırılmış, böylece struct boyutu minimumda tutulmuştur.
* **Dinamik Bellek Yönetimi (`malloc` & `free`):** Tensörler statik olarak değil, çalışma zamanında (runtime) ihtiyaç duyulan boyut ve tipe göre dinamik olarak bellekte yer kaplar. İşlem bitince `free` ile bellek sisteme iade edilir (Memory Leak önlemi).
* **Agentic Kodlama:** Proje geliştirme sürecinde yapay zeka destekli kodlama prensipleri (Agentic Coding) kullanılarak modüler ve temiz bir mimari (`.h` ve `.c` ayrımı) kurulmuştur.

## 🚀 Derleme ve Çalıştırma (Code::Blocks / GCC)

Projeyi terminal üzerinden derlemek ve çalıştırmak için:

```bash
gcc main.c tensor.c -o tinyml_app
./tinyml_app
