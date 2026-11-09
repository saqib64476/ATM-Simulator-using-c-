# ATM-Simulator-using-c-
Console based simulating ATM machine 

# 🏧 Advanced ATM Simulator (C++)

A professional, command-line-based ATM simulator built using C++. This project goes beyond basic procedural programming by implementing core **Object-Oriented Programming (OOP)** principles, **File Handling**, and **Data Structures** to create a realistic banking session.

## ✨ Key Features
* **Object-Oriented Design:** Uses encapsulation to keep sensitive data like PINs and account balances private (`class ATM`).
* **Persistent Storage (File I/O):** Account balance is saved to a local `balance.txt` file using `<fstream>`, meaning your funds are retained even after the program closes.
* **Transaction History (Mini Statement):** Utilizes `std::vector` to record and display a session log of all deposits, withdrawals, and balance checks.
* **Secure Access:** Requires a 4-digit PIN for authentication before granting access to the main menu.

## 🛠️ Tech Stack
* **Language:** C++11 (or higher)
* **Standard Libraries:** `<iostream>`, `<fstream>`, `<string>`, `<vector>`

## 🚀 How to Run

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YourUsername/ATM-Simulator-Cpp.git](https://github.com/YourUsername/ATM-Simulator-Cpp.git)
   cd ATM-Simulator-Cpp
