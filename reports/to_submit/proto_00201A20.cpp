// bin: proto
// va: 0x00201A20
// what: Finds the deepest heap in the heap tree that owns a block of memory, or 0 when none does.
// tool: Claude Opus 5.5 (transplanted from proto:0x002019E0, nearest by portal/tools/similar.py)
class Allocator_00201A20
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void Free(void* p);       // +0x14
    virtual void vfunc_pad6_0();
    virtual void vfunc_pad6_1();
    virtual void vfunc_pad6_2();
    virtual bool Contains(void* p);   // +0x18
};

struct Node_00201A20
{
    Allocator_00201A20* m_Allocator; // +0x00
    Node_00201A20* m_Child;          // +0x04
    Node_00201A20* m_Next;           // +0x08
};

extern "C" Node_00201A20* __cdecl sub_00201A20(Node_00201A20* node, void* p);

Node_00201A20* __cdecl sub_00201A20(Node_00201A20* node, void* p)
{
    for (; node; node = node->m_Next)
    {
        if (node->m_Allocator->Contains(p))
        {
            Node_00201A20* deeper = sub_00201A20(node->m_Child, p);
            return deeper ? deeper : node;
        }
    }
    return 0;
}