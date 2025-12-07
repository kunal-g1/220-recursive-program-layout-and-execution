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

## Mapping Function Calls and Recursion to the Software CPU
In our Software CPU design, we have general-purpose registers (such as **A** and **B**), a program counter (**PC**), a stack pointer (**SP**), and a block of **RAM**. To support function calls and recursion, we reserve the top of RAM for a **stack**. The stack pointer starts at the top and moves downward as data is pushed.

We can define two conceptual instructions:

- **CALL address** – push the return address on the stack and jump to the function address.
- **RET** – pop the return address from the stack and jump back to the caller.

When our driver program calls `factorial` on the Software CPU, the control unit executes **CALL**, which pushes the return address and sets **PC** to the factorial code.  
`factorial` stores its parameter `n` in the current stack frame and may use registers **A** and **B** for intermediate results. A recursive `CALL factorial(n-1)` repeats this process, so many copies of `factorial` are active on the stack at once, each with a different `n` value.

Once the **base case** is reached, each **RET** instruction restores the previous PC and stack pointer, and the partially computed results are combined as control returns to each caller.

This matches the behavior of recursion in C but expressed using our own CPU architecture.
