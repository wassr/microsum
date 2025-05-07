#include <microsum/macros.h>
#include <stdlib.h>

typedef struct {
    char*  name;
    size_t name_size;
    size_t state_size;
    size_t ideal_block_size;
    size_t output_size;
    void (*init)(void*, void*);
    void (*update)(void*, size_t, void*);
    void (*finalize)(void*, void*);
} msum_algo_def;

MSUM_PUBLIC const msum_algo_def* msum_query(size_t len, const char* name);
