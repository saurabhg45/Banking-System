# 🏦 Basic Banking System in C++

## 📋 Project Description

This is a simple C++ program simulating a basic banking system. The program supports essential banking functionalities including account creation, deposit, withdrawal, and balance inquiry. The system ensures account validation, maintains a minimum balance requirement, and implements basic error handling.

---

## ✅ Features

- Create a new bank account with auto-generated account number.
- Deposit money to an account.
- Withdraw money ensuring the minimum balance is maintained.
- Check current account balance.
- Error handling for:
  - Invalid input
  - Negative deposits
  - Withdrawals causing balance to fall below the minimum requirement

---

## 🧑‍💼 Account Attributes

| Attribute       | Type     | Description                                       |
|----------------|----------|---------------------------------------------------|
| `name`          | `string` | Name of the account holder                        |
| `gender`        | `char`   | Gender of the account holder ('M', 'F', etc.)     |
| `amount`        | `double` | Current balance in the account                    |
| `accountNumber` | `int`    | Unique auto-generated account number              |

---

## 🔧 Methods

| Method            | Description                                                                 |
|-------------------|-----------------------------------------------------------------------------|
| `createAccount()` | Initializes a new account with unique number and validates initial details  |
| `deposit(double)` | Adds a non-negative amount to account balance                               |
| `withdraw(double)`| Deducts amount ensuring balance does not go below minimum                   |
| `checkBalance()`  | Returns current account balance                                             |

---

## 💰 Banking Rules

- 🔐 **Minimum balance required**: `5000`
- ❌ **Withdrawals** cannot reduce balance below minimum
- ⚠️ Invalid operations like negative deposits or overdrafts are handled gracefully

---

## 🚀 How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/banking-system.git
   cd banking-system
