# 🌱 Smart Ornamental Plant Care System

An intelligent microcontroller-based project designed to automatically monitor and maintain ornamental plants.  
This system ensures plants receive the right amount of water, light, and environmental care through IoT and automation.

---

## 📖 Project Overview
The **Smart Ornamental Plant Care System** was developed as part of the Microcontroller and Interface course (ENGCE122) at Rajamangala University of Technology Lanna, Chiang Mai.  

The project aims to solve common issues in caring for ornamental plants such as improper watering, insufficient light, and lack of timely maintenance, which often lead to wilting or plant death.

---

## 👥 Project Team
- นางสาวบัณฑิตา สุธรรม (Bantita Sutham)  
- นายรชตะ รุ่งราตรี (Rochata Rungaratee)  
- นายบุญประพัฒน์ ตานัน (Boonprapat Tanan)  

Advisor: อาจารย์ศิวศิษฏ์ กุลศิริ  

Academic Year: 2566 (2023)

---

## 🎯 Objectives
- To study and improve the efficiency of caring for ornamental plants.  
- To apply automatic control for building a **smart ornamental plant care device**.  
- To provide practical benefits for those interested in **smart farming**.  

---

## 🛠️ Hardware & Components
- **NodeMCU ESP8266** (Wi-Fi enabled microcontroller)  
- **DHT11** Temperature & Humidity Sensor  
- **LDR Sensor** for light detection  
- **Brushless Motor Pump 12V** (watering system)  
- **UV LED** (artificial light for plants)  
- **Relay Module (5V 4-channel)**  
- **DC Fan 12V** (airflow for moisture measurement)  
- Supporting materials: jumper wires, power supply, water pipes, plant rack  

💰 **Total Cost:** ~1062 THB  

---

## ⚙️ System Design
- **Automatic Watering:** Uses soil humidity detection. Minimum threshold set at **51% RH**.  
- **Automatic Lighting:** Uses LDR to detect brightness. When darkness reaches **1024 (Analog pin reading)**, UV light is activated.  
- **IoT Monitoring:** Real-time monitoring & manual control through **Blynk mobile application**.  
- **Fan-assisted Moisture Detection:** Improves accuracy and reduces cost compared to typical smart farm setups.  

---

## 📊 Results
- Optimal soil humidity for watering: **51 %RH**  
- Optimal light threshold for UV activation: **1024 (Analog pin)**  
- The system successfully automates watering and lighting every ~1 hour and can be customized by users via Blynk.  

---

## 🚀 Quick Start
1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/<repo-name>.git
