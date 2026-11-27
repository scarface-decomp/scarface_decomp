// bin: xb
// va: 0x002AAE60
// what: Sets up the memory pool file objects come from (0x168 bytes each, named "File"), and the lock around it.
// tool: Claude (from SPEC-019, SPEC-020)

extern "C" char DAT_004BDD64[];     // the lock around the file pool
extern "C" char DAT_004BDD80[];     // the file pool

void __cdecl sub_00283B60(void* lock);      // sets up a lock
int __cdecl CreateMemoryPool(void* pool, unsigned int size, int count, int a4, int heap, const char* name, int alignment, int a8);

void __cdecl sub_002AAE60(int count, int heap)
{
    sub_00283B60(DAT_004BDD64);
    CreateMemoryPool(DAT_004BDD80, 0x168, count, 0, heap, "File", 4, 0);
}
