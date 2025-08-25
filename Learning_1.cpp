#include <stdio.h>
#include <assert.h> // For the friendlier static_assert
#include <stdint.h> // For uintptr_t

int main() {
    // This check happens at compile time.
    // If you compile this on a 32-bit system where pointers are 4 bytes,
    // the compilation will fail with the error message.
    static_assert(sizeof(void*) == 8, "This code requires a 64-bit architecture.");

    printf("Successfully compiled on a 64-bit system.\n");
    return 0;
}