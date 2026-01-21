# 🐚 Mini Shell C

A **simplified Linux shell** implemented from scratch in **C**, designed to demonstrate key concepts of process control, input/output redirection, pipes, signal handling, and custom command parsing. This project is modular, extensible, and serves as both a learning tool and a functional mini-shell.

---

## 🚀 Features

### Built-in Commands

* `cd [dir]` – Change the current working directory
* `exit` – Exit the shell
* Fully handles quoted arguments (e.g., `"multi word arg"`)

### External Commands

* Executes standard Linux commands using `fork()` and `execvp()`
* Supports multiple arguments

### Input/Output Redirection

* Overwrite output: `>` (e.g., `ls > out.txt`)
* Append output: `>>` (e.g., `echo "hello" >> out.txt`)

### Pipes

* Connect multiple commands: `|` (e.g., `ls -l | grep txt | wc -l`)

### Signal Handling

* `Ctrl+C` – Interrupt current command without exiting the shell
* `Ctrl+\` – Custom handling
* `Ctrl+L` – Clear terminal

### Parsing & Modular Design

* Handles spaces, quotes, and special characters
* Modular C structure for maintainability and readability
* Separate modules for input, parsing, execution, redirection, pipes, and signals

---

## 🛠 Build & Run Instructions

### 1. Clone the repository

```bash
git clone https://github.com/yourusername/mini-shell-c.git
cd mini-shell-c
```

### 2. Build using Make

```bash
make
```

### 3. Run the shell

```bash
./mini-shell
```

### 4. Clean build files

```bash
make clean
```

---

## 💡 Usage Examples

```bash
# Change directory
mini-shell> cd /home/user

# List files
mini-shell> ls -l

# Redirect output to file (overwrite)
mini-shell> ls > files.txt

# Append output to file
mini-shell> echo "New line" >> files.txt

# Pipe commands
mini-shell> ls -l | grep ".c" | wc -l

# Exit shell
mini-shell> exit
```

### Supports quoted arguments

```bash
mini-shell> echo "Hello World from mini-shell"
Hello World from mini-shell
```

---

## ⚠️ Known Limitations

* No support for background execution (`&`)
* No complex shell scripting features (loops, conditionals, etc.)
* Limited error handling for invalid commands
* No environment variable expansion (`$PATH`, `$HOME`, etc.)
* Single-level pipe handling is fully tested; complex pipe chains may require more testing

---

## 📈 Roadmap / Next Steps

* Add support for background processes (`&`)
* Implement environment variable expansion
* Support for command history with arrow navigation
* Advanced signal handling and job control
* Implement tab-completion for commands and paths

---

## 📂 Project Structure

```text
mini-shell-c/
├── include/
│   └── minishell.h        # Header file with function declarations and constants
├── src/
│   ├── main.c             # Main loop and signal setup
│   ├── input.c            # Handles user input
│   ├── parser.c           # Parses commands and arguments
│   ├── execute.c          # Executes commands, built-ins, redirections, and pipes
│   ├── builtins.c         # Implements built-in commands
│   ├── redirect.c         # Handles output redirection
│   ├── signals.c          # Signal handlers
│   └── pipe.c             # Handles pipes
├── Makefile               # Build automation
└── README.md
```

### File Responsibilities

* **main.c** – Initializes the shell, sets up signals, and runs the main loop
* **input.c** – Reads user input, handles buffering and trimming
* **parser.c** – Tokenizes commands, handles quotes, splits by spaces/pipes
* **execute.c** – Executes commands using `fork()`, `execvp()`, and waits for completion
* **builtins.c** – Implements `cd`, `exit`, and other internal commands
* **redirect.c** – Handles output redirection (`>` and `>>`)
* **pipe.c** – Implements pipe functionality for multiple commands
* **signals.c** – Handles `Ctrl+C`, `Ctrl+\`, `Ctrl+L` for a smooth shell experience

---

## 📚 References

* Linux man pages: `fork`, `execvp`, `wait`
* *Advanced Linux Programming*
* *GNU Bash Manual*
* *The C Programming Language (K&R)*

---

## 👤 Author

**Alen Lajeesh** – C programmer & Linux enthusiast
📅 *January 2026*

---

⭐ If you find this project useful, consider giving it a star!

