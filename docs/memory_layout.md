# Memory Layout & Execution Trace (Detailed)

This document drills into *how* function calls and recursion are realized on a typical machine and how to **map** the idea onto your software CPU design.

## 1) Host (C on your laptop)

- Each function call creates a **stack frame** with parameters, locals, saved registers, and a **return address**.
- Return address is **pushed** automatically by the hardware `CALL` instruction and **popped** by `RET`.

### Frame example (factorial)
```
| caller locals |           <-- older frames
| return addr   |
| saved regs    |
| parameter n   |           <-- top of current frame
-----------------  (SP)
```

## 2) Software CPU mapping (design)

Assume:
- SP initialized to `0x7FFF` (stack grows downward).
- We add (or emulate) `CALL` (0x12) and `RET` (0x13) opcodes.

### CALL (0x12 abs16)
- Push (PC_low), then (PC_high) to `[SP]` and `[SP-1]`, update SP
- Set `PC = abs16`

### RET (0x13)
- Pop PC_high/low from stack, set `PC`

### Factorial in pseudo-assembly
```
; factorial(n) in A (parameter in A), returns A
; Prologue
PUSH A
CMP A,#1
JZ  base
DEC A
CALL factorial       ; recursive call with (n-1) in A
POP  B               ; restore original n into B
MUL A,B              ; res = n * sub   (MUL can be a helper loop)
RET

base:
LDA #1
RET
```

> If MUL isn't an opcode, multiply via a loop: add A to a sum B times.

## 3) Worked example: factorial(4)
- Frame 1: n=4 → calls factorial(3)
- Frame 2: n=3 → calls factorial(2)
- Frame 3: n=2 → calls factorial(1) → base returns 1
- Unwind: frame2 computes 3*1=3, frame1 computes 4*3=12

This is exactly what your C trace shows in `src/main.c` when TRACE is on.
