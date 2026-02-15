# 🦕 ProSaurier V.2025 — Dino Park Manager

**Ein Retro-Dino-Park-Management-Game im C64-Style, geframet in einem Röhrenmonitor mit Scanlines, CRT-Verzerrung und SID-artiger Audiomodulation.**

Baue deinen eigenen Dinosaurier-Park auf! Kaufe Dinos von Händlern, päppele Fundtiere auf, untersuche sie mit Lupe, Waage und Stethoskop, und manage deine Wiese mit Futter, Gebäuden und Zäunen. Stelle Personal ein, streichle deine Dinos zu 5-Sterne-Bewohnern — und finde das geheime Ende.

---

### Features

- **CRT-Röhrenmonitor** mit Scanlines, Flicker und Phosphor-Glow
- **C64 Boot-Sequenz** — `LOAD "PROSAURIER",8,1` → `RUN`
- **10 Dinosaurier-Arten** als Pixel-Sprites (Triceratops, T-Rex, Velociraptor, Spinosaurus, ...)
- **★ Sterne-System (1–5)** — bessere Dinos erscheinen mit wachsendem Park
- **Untersuchungs-Minigame** — Werkzeuge auswählen, an der richtigen Stelle klicken
- **Wiesenansicht** — Dinos laufen 2D rum, 💩 wegklicken, Futter liefern
- **Gebäude & Zäune** — Unterstände, Teiche, Holz- bis Elektrozäune
- **Personal** — Tierärztin (ab 5 Dinos), Tierpfleger (ab 10), Assistentin (ab 20)
- **Progressives Geldsystem** — man geht praktisch nie pleite
- **Speichern & Laden** über Persistent Storage
- **Geheimes Ende** bei 40 × 5★ Dinos
- **C64 Sound** — Square/Triangle/Sawtooth-Wave Audiomodulation

### Starten

Das Spiel ist ein einzelnes React-Artifact (`.jsx`). Einfach in [claude.ai](https://claude.ai) als Artifact rendern oder in ein React-Projekt einbinden.

### Cheat

> `xyzzy`

---

<sub>

### Ursprung — ProSaurier V.1.0 (2016)

Dieses Projekt basiert auf meinem allerersten Programm aus dem Studium: **ProSaurier V.1.0**, geschrieben in C am 10.01.2016. Ein Terminal-basierter Dino-Park-Manager mit `struct`-Arrays, `gotoXY`-Cursor-Steuerung, `getch()`-Eingabe und Dateispeicherung über `fwrite`/`fread`. Die originalen Quelldateien (`zoo.c`, `lib.h`) liegen weiterhin im Repo.

*By Sascha Athmer — seit 2016*

</sub>
