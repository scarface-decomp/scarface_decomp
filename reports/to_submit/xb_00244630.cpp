// bin: xb
// va: 0x00244630
// what: Takes a heap id out of the tree of heaps, lets go of its allocator and gives it the default allocator again.
// tool: Claude Opus 5.5 (from the bytes, with the examiner's roles)

// A heap allocator: the memory system calls it through its table.
struct Allocator
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

// One heap id's place in the tree of heaps.
struct HeapNode
{
    Allocator* allocator;
    HeapNode* firstChild;
    HeapNode* nextSibling;
    HeapNode* parent;
};

extern "C" HeapNode DAT_00493B40;          // the tree's root; its allocator is the default one
extern "C" HeapNode g_heapTable[0x81];     // one node per heap id

void __cdecl sub_00244630(int id)
{
    HeapNode* node = &g_heapTable[id];
    HeapNode* parent = node->parent;
    HeapNode* previous = 0;
    for (HeapNode* child = parent->firstChild; child; child = child->nextSibling)
    {
        if (child == node)
        {
            if (previous)
                previous->nextSibling = node->nextSibling;
            else
                parent->firstChild = node->nextSibling;
            node->allocator->vfunc_01();
            node->allocator = DAT_00493B40.allocator;
            node->firstChild = 0;
            node->parent = 0;
            node->nextSibling = 0;
            return;
        }
        previous = child;
    }
}
