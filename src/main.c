#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * Recursion examples:
 * 1) factorial(n): classic recursion with base case n<=1
 * 2) recursive_multiply(a,b): multiplies via repeated addition using recursion
 *
 * Both include rich prints when TRACE is enabled to visualize the call stack.
 */

#ifndef TRACE
#define TRACE 1
#endif

static int depth = 0;

static void indent(void){
#if TRACE
    for(int i=0;i<depth;i++) fputs("  ", stdout);
#endif
}

uint64_t factorial(uint64_t n){
#if TRACE
    indent(); printf("call factorial(%" PRIu64 ")\n", n);
    depth++;
#endif
    if (n <= 1){
#if TRACE
        depth--;
        indent(); printf("return 1  (base case for %" PRIu64 ")\n", n);
#endif
        return 1;
    }
    uint64_t sub = factorial(n-1);
    uint64_t res = n * sub;
#if TRACE
    depth--;
    indent(); printf("return %" PRIu64 "  (=%" PRIu64 " * %" PRIu64 ")\n", res, n, sub);
#endif
    return res;
}

/* multiply a*b using recursion: a*b = a + (a*(b-1)), base when b==0 */
int64_t recursive_multiply(int64_t a, int64_t b){
#if TRACE
    indent(); printf("call recursive_multiply(%" PRId64 ", %" PRId64 ")\n", a, b);
    depth++;
#endif
    if (b == 0){
#if TRACE
        depth--;
        indent(); printf("return 0  (base case)\n");
#endif
        return 0;
    }
    int64_t part = recursive_multiply(a, b-1);
    int64_t res = a + part;
#if TRACE
    depth--;
    indent(); printf("return %" PRId64 "  (=%" PRId64 " + %" PRId64 ")\n", res, a, part);
#endif
    return res;
}

int main(int argc, char** argv){
    uint64_t n = 5;
    if (argc > 1) n = strtoull(argv[1], NULL, 10);

    printf("=== Recursion Demo ===\n");
    printf("Computing factorial(%" PRIu64 ")\n\n", n);

    uint64_t fact = factorial(n);
    printf("\nResult: factorial(%" PRIu64 ") = %" PRIu64 "\n\n", n, fact);

    /* show a second recursion example (small inputs for brevity) */
    int64_t a = 7, b = 6;
    printf("Computing recursive_multiply(%" PRId64 ", %" PRId64 ")\n\n", a, b);
    int64_t mul = recursive_multiply(a, b);
    printf("\nResult: recursive_multiply(%" PRId64 ", %" PRId64 ") = %" PRId64 "\n", a, b, mul);
    return 0;
}
