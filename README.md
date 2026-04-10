# 📱 Smart Contact Manager

## 📌 Description
The Smart Contact Manager is a C++ application that allows users to manage contacts efficiently.  
It provides basic operations such as adding, deleting, searching, and restoring contacts.  

This project demonstrates the practical implementation of Data Structures in a real-world scenario.

---

## 🎯 Objectives
- To implement a real-world application using C++
- To understand Linked List operations
- To use Stack for undo functionality
- To design a menu-driven program

---

## ✨ Features
- ➕ Add new contacts (Name & Phone Number)
- ❌ Delete contacts
- 🔍 Search contacts by name
- ↩️ Undo last deleted contact
- 📋 Display all contacts

---

## 🧠 Data Structures Used

### 1. Linked List
- Used to store contacts dynamically
- Each node contains:
  - Name
  - Phone number
  - Pointer to next node
- Allows efficient insertion and deletion

### 2. Stack
- Used to store deleted contacts
- Enables undo functionality
- Follows LIFO (Last In First Out) principle

---

## ⚙️ Working of the System

- Contacts are stored using a Linked List  
- When a contact is deleted:
  - It is removed from the list  
  - It is pushed into the stack  
- When undo is performed:
  - The last deleted contact is restored from the stack  
- Searching is done by traversing the list

  done by shanala varshini

