# "Famous" Bookstore Ordering System

> **Disclaimer:** This system is a fictional project developed for academic purposes.  
> The bookstore, names, and data used are entirely made up and do not represent any real business.

## 📖 Overview
The **"Famous" Bookstore Ordering System** is a C++ console-based application designed to simulate the order placement process in a bookstore. It supports **role-based access** for both staff and managers, allowing efficient handling of customer orders, inventory management, and sales reporting.

The system is user-friendly, menu-driven, and includes **input validation** to minimize errors during transactions.

---

## ⚙️ Tech Stack
- **Language:** C++  
- **Environment:** Console-based Application
- **IDE / Compiler Used:** Visual Studio 2022  

---

## ✨ Features
### Common Features (Staff & Manager)
- **Book Ordering**
  - Browse books by genre: Drama, Fiction, Non-fiction, Fantasy, Biography.
  - Select book by number and quantity.
  - Add multiple books to a single invoice.
  - Order confirmation before payment.

- **Payment Processing**
  - Supports Cash, Debit Card, Credit Card, and E-wallet.
  - Calculates change automatically.
  - Displays an on-screen receipt.

### Manager-Only Features
- **Secure Login** — Requires Manager ID and password.
- **Reports**
  - **Daily Sales Report**
  - **Best & Worst Genre Sales Report**
  - **Stock Report** (shows books left in inventory)

### Additional Highlights
- **Role-Based Access Control**
- **Organized Inventory Table**
- **Real-Time Report Updates**
- **Input Validation for all Menus**

---

## 📂 Project Structure
```plaintext
FamousBookstore/
│
├── main.cpp          # Entry point with menu system
├── functions.cpp     # Core functions for ordering, reporting, etc.
└── functions.h       # Function prototypes
