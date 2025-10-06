# 🕰️ Historian's Estimator

**Version:** 1.0.0  
**Language:** C (ISO C99)  
**Platform:** Cross-platform (Windows / Linux / macOS)  
**Executable Size:** ~142 KB  
**Source Code Size:** ~7 KB  
**License:** MIT

---

## 📘 Overview

**Historian's Estimator** (a.k.a. *Date Comparator*) is a C-based console application designed to calculate precise differences between two dates using the **Gregorian calendar**.  
It features **intelligent date auto-correction**, **historical year support**, and an **interactive CLI experience**.

This version serves as the **base release (v1.0.0)** following [Semantic Versioning 2.0.0](https://semver.org/).

---

## ⚙️ Features & Technical Highlights

* 📅 **Date Difference Calculation** – Accurate day-level difference between any two valid Gregorian dates
* 🧠 **Smart Auto-Correction** – Automatically adjusts invalid or overflow date entries
* 🕰️ **Historical Date Support** – Handles AD and BC dates (up to ±32,767 years)
* 🔢 **Dual Output Formats** – Results in both days and combined years/months/days
* 🔄 **Interactive Session Mode** – Compare multiple date pairs continuously until exit
* ❗ **Input Validation & Error Handling** – Detects invalid entries and prompts for re-entry
* 🧱 **Memory & File Efficient** – Single-file C implementation (~7 KB source, ~142 KB executable)
* 💻 **Cross-Platform Compatibility** – Works on Windows, Linux, and macOS
* 📦 **Minimal Dependencies** – Standard C Library only, no external libraries
* ⚡ **Execution Environment** – Runs entirely in terminal / command-line

---

## 🧱 Installation & Compilation

```bash
# Clone the repository
git clone https://github.com/dipsana/historian-estimator.git
cd historian-estimator

# Compile source code to bin folder
gcc -o bin/historian_estimator src/main.c

# Run the executable
./bin/historian_estimator
```

---

## 📁 Repository Structure [Clickable]

├─ 📁 [bin](./bin)  
│   └─ 📄 [historian_estimator.exe](./bin/historian_estimator.exe)  
├─ 📁 [docs](./docs)  
│   └─ 📄 [SRS.pdf](./docs/SRS.pdf)  
├─ 📁 [src](./src)  
│   └─ 📄 [main.c](./src/main.c)  
├─ 📄 [README.md](./README.md)  
├─ 📄 [LICENSE](./LICENSE)  
└─ 📄 [CHANGELOG.md](./CHANGELOG.md)

---

## 🧭 Usage

1. Run the executable in your terminal.
2. Enter dates in the format `dd mm yyyy`.
3. Use `y` or `n` to confirm re-entry or continue comparisons.
4. Results appear in both **days** and **years/months/days**.

---

## 🧾 Sample Output

```text
Welcome Historian! I'm your estimator based on Gregorian Calendar.
Enter any two dates separated by spaces in dd mm yyyy format for comparison.
You may also enter negative or exceeding values to try my auto-correct feature (^-^)

Enter Date 1 (dd mm yyyy): 10 10 2001
Do you want to re-enter the date? (y/n): n
Enter Date 2 (dd mm yyyy): 10 09 2000
Do you want to re-enter the date? (y/n): n

Min Date: 10/09/2000.
Max Date: 10/10/2001.

*******************************************
Difference between the two dates: 395 days.
Difference between the two dates: 1 year 1 month.
...
Stay tuned for more features, bye... :)
```

---

## 🧠 Technical Highlights

* Accurate leap year calculations
* Date overflow/underflow handling
* Historical calendar range: ±32,767 years
* Compact and efficient design

---

## 🚀 Roadmap / Future Enhancements

* Add support for Julian, Islamic, and Hebrew calendars
* Implement date arithmetic (add/subtract days)
* Introduce holiday calculations
* Develop GUI and Web API versions
* Batch processing support

---

## 🧾 Version History

| Version | Date       | Description             |
| ------- | ---------- | ----------------------- |
| 1.0.0   | 2025-10-05 | Base release (SRS done) |

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

---

> *“Welcome Historian! Precision begins where time meets logic.”* ⏳

---

**Versioning:** This project adheres to [Semantic Versioning 2.0.0](https://semver.org/).  
**Changelog Format:** Based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).
