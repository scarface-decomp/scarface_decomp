// bin: xb
// va: 0x00244390
// what: Sets up the memory system: creates the default allocator and gives it to every heap id, then sets up the memory spaces.
// tool: Claude Opus 5.5 (from the bytes, with the examiner's roles)

// A heap allocator: the memory system calls it through its table.
struct Allocator
{
    virtual void vfunc_00();
};

// One heap id's place in the tree of heaps.
struct HeapNode
{
    Allocator* allocator;
    HeapNode* firstChild;
    HeapNode* nextSibling;
    HeapNode* parent;
};

extern "C" bool DAT_00493B50;              // set once the memory system is set up
extern "C" Allocator* DAT_00493328;        // the default allocator
extern "C" HeapNode DAT_00493B40;          // the tree's root
extern "C" HeapNode g_heapTable[0x81];     // one node per heap id
extern "C" Allocator* __cdecl sub_0028D110(void);
extern "C" void __cdecl sub_002A9290(void);

void __cdecl sub_00244390(void)
{
    DAT_00493B50 = true;
    Allocator* standard = sub_0028D110();
    DAT_00493328 = standard;
    DAT_00493B40.allocator = standard;
    DAT_00493B40.firstChild = 0;
    DAT_00493B40.nextSibling = 0;
    DAT_00493B40.parent = 0;
    for (unsigned int i = 0; i < 0x81; i++)
    {
        g_heapTable[i].firstChild = 0;
        g_heapTable[i].parent = 0;
        g_heapTable[i].nextSibling = 0;
        g_heapTable[i].allocator = standard;
    }
    sub_002A9290();
}
