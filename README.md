# Mini-proiect: Flappy Bird pe ESP32

[cite_start]Acest proiect reprezintă o implementare a jocului clasic **Flappy Bird** folosind un microcontroller **ESP32**, un afișaj OLED și un buzzer pentru efecte sonore.

## 🛠️ Materiale Folosite
* [cite_start]**Microcontroller:** ESP32.
* [cite_start]**Ecran:** Modul afișaj OLED SSD1306 (128x64 px).
* [cite_start]**Control:** Buton (Push-button) pentru saltul păsării.
* [cite_start]**Audio:** Buzzer pentru sunete în timpul jocului.
* [cite_start]**Altele:** Breadboard și 8 cabluri de conexiune.

---

## 🔌 Conectare Hardware
[cite_start]Conectarea componentelor la pinii ESP32 este realizată astfel:

### Afișaj SSD1306 (I2C)
* [cite_start]**GND** -> GND 
* [cite_start]**VCC** -> 3V3 
* [cite_start]**SCL** -> Pin D22 
* [cite_start]**SDA** -> Pin D21 

### Alte Componente
* [cite_start]**Buzzer:** Pol pozitiv la Pin D23, GND la GND.
* [cite_start]**Buton:** Conectat între Pin D4 și GND.

---

## 🕹️ Funcționalități și Logică
* [cite_start]**Săritură:** Pasărea "sare" la fiecare apăsare a butonului, declanșând și un efect sonor scurt prin funcția `playJumpSound()`.
* [cite_start]**Obstacole:** Jocul generează obstacole cu spații libere prin care pasărea trebuie să treacă.
* [cite_start]**Scor:** Scorul este afișat în timp real în partea de sus a ecranului și crește la trecerea fiecărui obstacol.
* [cite_start]**Game Over:** Jocul se termină la coliziunea cu marginile sau obstacolele, putând fi resetat prin funcția `resetGame()`.

---

## 🚀 Instalare și Utilizare
1. [cite_start]**Biblioteci necesare:** Asigură-te că ai instalate în Arduino IDE bibliotecile `Adafruit_GFX` și `Adafruit_SSD1306`.
2. [cite_start]**Încărcare cod:** Conectează ESP32 la PC și încarcă scriptul furnizat în documentație.
3. [cite_start]**Start:** Pasărea este reprezentată grafic printr-un bitmap de 8x8 pixeli. Apasă butonul pentru a începe!

---

## 👤 Autor
[cite_start]**Chirițoiu Constantin-Sorin** *Documentație realizată pentru proiectul Flappy Bird - ESP32*.
