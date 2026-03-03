# Mini-proiect: Flappy Bird pe ESP32

Acest proiect reprezintă o implementare a jocului clasic **Flappy Bird** folosind un microcontroller **ESP32**, un afișaj OLED și un buzzer pentru efecte sonore.

## 🛠️ Materiale Folosite
* **Microcontroller:** ESP32.
* **Ecran:** Modul afișaj OLED SSD1306 (128x64 px).
* **Control:** Buton (Push-button) pentru saltul păsării.
* **Audio:** Buzzer pentru sunete în timpul jocului.
* **Altele:** Breadboard și 8 cabluri de conexiune.

---

## 🔌 Conectare Hardware
Conectarea componentelor la pinii ESP32 este realizată astfel:

### Afișaj SSD1306 (I2C)
* **GND** -> GND
* **VCC** -> 3V3
* **SCL** -> Pin D22
* **SDA** -> Pin D21

### Alte Componente
* **Buzzer:** Pol pozitiv la Pin D23, GND la GND.
* **Buton:** Conectat între Pin D4 și GND.

---

## 🕹️ Funcționalități și Logică
* **Săritură:** Pasărea "sare" la fiecare apăsare a butonului, declanșând și un efect sonor scurt prin funcția `playJumpSound()`.
* **Obstacole:** Jocul generează obstacole cu spații libere prin care pasărea trebuie să treacă.
* **Scor:** Scorul este afișat în timp real în partea de sus a ecranului și crește la trecerea fiecărui obstacol.
* **Game Over:** Jocul se termină la coliziunea cu marginile sau obstacolele, putând fi resetat prin funcția `resetGame()`.

---

## 🚀 Instalare și Utilizare
1. **Biblioteci necesare:** Asigură-te că ai instalate în Arduino IDE bibliotecile `Adafruit_GFX` și `Adafruit_SSD1306`.
2. **Încărcare cod:** Conectează ESP32 la PC și încarcă codul sursă.
3. **Start:** Pasărea este reprezentată grafic printr-un bitmap de 8x8 pixeli. Apasă butonul pentru a începe!

---

## 👤 Autor
**Chirițoiu Constantin-Sorin**
