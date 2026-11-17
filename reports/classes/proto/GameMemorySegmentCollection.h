// GameMemorySegmentCollection (proto): one declaration merged from its matched functions.
// Proven for 9 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Segment;
class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual GameMemorySegmentCollection* vfunc_03(int a1);
    virtual void vfunc_04(int);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1, int a2);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual bool vfunc_10(unsigned int* freeBytes, unsigned int* largestUsed, unsigned int* usedCount, unsigned int* usedBytes);
    virtual void vfunc_11();
    virtual int vfunc_12();
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    Segment* m_segments; // +0x10
    int m_count; // +0x14
    int m_segmentSize; // +0x18
};
