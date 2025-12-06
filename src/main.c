#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * Recursion examples:
 * 1) factorial(n): classic recursion with base case n<=1
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

int main(int argc, char** argv){
    uint64_t n = 5;
    if (argc > 1) n = strtoull(argv[1], NULL, 10);

    printf("=== Recursion Demo ===\n");
    printf("Computing factorial(%" PRIu64 ")\n\n", n);

    uint64_t fact = factorial(n);
    printf("\nResult: factorial(%" PRIu64 ") = %" PRIu64 "\n\n", n, fact);
    return 0;
}
