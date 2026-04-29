# 🔧 Linux Character Device Driver (Kernel Module)

## 📌 Description

This project implements a **Linux Character Device Driver** as a Loadable Kernel Module (LKM), enabling communication between **user-space applications and kernel-space** through a device file.

Character device drivers operate on a **stream of bytes**, allowing sequential read/write operations similar to regular files ([GitHub][1]).

---

## 🚀 Features

* 🔌 Loadable Kernel Module (LKM)
* 📥 Read data from device (user → kernel)
* 📤 Write data to device (kernel → user)
* 🔁 Open & release operations handling
* 🧠 Demonstrates kernel-user communication
* ⚙️ Dynamic device registration

---

## 🛠️ Technologies Used

* Language: **C**
* Platform: **Linux Kernel**
* Tools:

  * `gcc`
  * `make`
  * `insmod`, `rmmod`, `lsmod`
  * `dmesg`
* Concepts:

  * Kernel Programming
  * Character Device Drivers
  * System Calls Interface
  * File Operations (`open`, `read`, `write`, `release`)

---

## ⚙️ How It Works

### 🔹 Kernel Side

* Registers a character device using kernel APIs
* Defines file operations:

  * `open()`
  * `read()`
  * `write()`
  * `release()`
* Handles data transfer between kernel and user space

### 🔹 Device File

* A special file created using `mknod`
* Acts as an interface between user program and driver
* Identified using **Major & Minor numbers** ([GitHub][1])

---

## 📂 Project Structure

```bash
Character_Device_Driver/
│── char_driver.c
│── Makefile
│── user_app.c (optional)
│── README.md
```

---

## 🧑‍💻 Build & Run

### 🔧 Compile Kernel Module

```bash
make
```

### ▶️ Insert Module

```bash
sudo insmod char_driver.ko
```

### 📋 Verify Module

```bash
lsmod | grep char_driver
```

### 📜 Check Logs

```bash
dmesg | tail
```

### 📁 Create Device File

```bash
sudo mknod /dev/mychar c <major> <minor>
sudo chmod 666 /dev/mychar
```

### ▶️ Interact with Device

```bash
echo "Hello Kernel" > /dev/mychar
cat /dev/mychar
```

### ❌ Remove Module

```bash
sudo rmmod char_driver
```

---

## 📂 Output

* Kernel logs displayed using `dmesg`
* Data exchange between user-space and kernel-space
* Device file interaction via `/dev/mychar`

---

## 🔒 Requirements

* Linux OS (Ubuntu recommended)
* Root privileges (`sudo`)
* Kernel headers installed:

```bash
sudo apt install linux-headers-$(uname -r)
```

---

## 📈 Future Improvements

* Add IOCTL support for advanced control
* Implement circular buffer
* Support multiple devices
* Add synchronization (mutex/semaphores)
* Build user-space CLI tool

---

## 💡 Learning Outcomes

* Understanding Linux kernel internals
* Device driver development lifecycle
* Kernel ↔ User communication
* Working with system-level APIs

---

## 👤 Author

**Kartik Ganesh Jare**

---

## ⭐ Why This Project Matters

This project demonstrates **low-level kernel programming**, which is highly valuable for:

* System Programming roles
* Embedded Systems
* OS Development
* Linux Kernel Engineering
