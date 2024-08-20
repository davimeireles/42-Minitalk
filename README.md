# Project: Minitalk - Implementing a Client-Server Communication System

## Project Overview

The primary objective of Minitalk was to develop a communication program in the form of a client and server. The server must be launched first and print its PID (Process ID) after starting. The client takes two parameters: the server PID and the string to send. The client must then send the string to the server, and the server must print it.

## Key Features

### Server

- Launches first and displays its PID
- Handles incoming signals to reconstruct and display the received message
- Runs indefinitely and can receive strings from several clients in a row
- Displays the received string quickly

### Client

- Takes the server PID as a parameter
- Sends the string (passed as a parameter) to the server
- Terminates properly after sending the message

### Bonus Features

- Added support for Unicode characters
- Implemented server acknowledgment for each message received

## Technical Implementation

### Signal Usage

- Utilized SIGUSR1 and SIGUSR2 for communication
- Implemented binary encoding of characters using these two signals
