// bin: proto
// va: 0x00064CC0
// what: Takes a 24-byte object from a memory pool and sets it up, or returns nothing if there was no room.
// tool: Claude Opus 5.5 (transplanted from xb:0x0006ECE0, nearest by portal/tools/similar.py)
struct Heap
{
    void* sub_00069F60(unsigned int size);
};

struct Made
{
    void* vtable;
    int m_04;
    int m_08;
    int m_0C;
    int m_value; // +0x10
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381B58[];
extern "C" Heap* DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

// Allocates a 24-byte object from the heap and builds it (base part first, then its own vtable).
// The value is stored after the null check, so a failed allocation writes to address 0x10.
Made* __cdecl sub_00064CC0(int value)
{
    Made* made = (Made*)DAT_0044E08C->sub_00069F60(24);
    if (made) {
        made->vtable = DAT_003819DC;
        made->m_04 = 0;
        made->m_08 = sub_0006B230();
        made->m_0C = sub_0006B240();
        made->vtable = DAT_00381B58;
    }
    made->m_value = value;
    return made;
}