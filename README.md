# 220-recursive-program-layout-and-execution
Create a simple C function that has recursion - say a factorial calculation or even a simple multiplication! along with a main driver.

## Team Members
- Kunal Rajesh Goel
- Adithya Thirumalai
- Sunny Dilipkumar Shah
- Aruna Samhitha

This repo contains:
- A simple **C program with recursion** (`factorial` and `recursive_multiply`) and a driver `main`.
- A **report** that explains *program layout in memory*, *function calls*, and *how recursion executes* — both on a normal machine and mapped onto your **software CPU** design (stack frames, CALL/RET convention, and a worked trace).
- Clean build and run instructions that work on macOS/Linux/WSL.

## Structure
- `src/` — C source code
- `docs/` — layout report

## Quick Start

```bash
# Option A: CMake (recommended)
mkdir -p build && cd build
cmake .. && cmake --build . -j
./recursion_demo 5

# Option B: plain make
make
./recursion_demo 5
```

Expected output (for `n=5`):
```
factorial(5) = 120
recursive_multiply(7, 6) = 84
```

> Tip: try different inputs: `./recursion_demo 0`, `./recursion_demo 10`

## Files
- `src/main.c` — driver + recursion functions
- `docs/memory_layout.md` — detailed mapping to our Software CPU (stack frames, CALL/RET)
- `CMakeLists.txt`, `Makefile`, `.gitignore`
