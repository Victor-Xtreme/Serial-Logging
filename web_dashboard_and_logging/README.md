# 🌐 Web Dashboard & Server Integration

## Overview

This module implements the **server integration and web dashboard** for the GDSC Serial Logging Project.

It is responsible for:

- Receiving sensor data from ESP32 (HTTP POST)
- Logging data into a CSV file
- Serving a real-time web dashboard
- Displaying the latest reading
- Showing the last 5 logged entries

---

## Architecture

ESP32 → HTTP POST → Node.js (Express) → CSV Logging → Web Dashboard

---

## API Endpoints

### POST `/data`
Receives sensor data:
```json
{
  "temperature": 28.5,
  "humidity": 65
}
GET /latest

Returns most recent reading.

GET /history

Returns last 5 logged readings.

Setup
cd web_dashboard_and_logging
npm install
node server.js

Open in browser:

http://localhost:3000