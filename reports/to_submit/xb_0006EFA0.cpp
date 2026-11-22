// bin: xb
// va: 0x0006EFA0
// what: Takes a 24-byte object from a memory pool and sets it up, or returns nothing if there was no room.
// tool: Claude Opus 5.5 (transplanted from xb:0x0006ECE0, nearest by portal/tools/similar.py)
struct Heap
{
    void* sub_000745F0(unsigned int size);
};

struct Made
{
    void* vtable;
    int m_04;
    int m_08;
    int m_0C;
    int m_value; // +0x10
};

extern "C" char DAT_003A24DC[];
extern "C" char DAT_003A265C[];
extern "C" Heap* DAT_004795AC;
extern "C" int __cdecl sub_000758D0(void);
extern "C" int __cdecl sub_000758E0(void);

// Allocates a 24-byte object from the heap and builds it (base part first, then its own vtable).
// The value is stored after the null check, so a failed allocation writes to address 0x10.
Made* __cdecl sub_0006EFA0(int value)
{
    Made* made = (Made*)DAT_004795AC->sub_000745F0(24);
    if (made) {
        made->vtable = DAT_003A24DC;
        made->m_04 = 0;
        made->m_08 = sub_000758D0();
        made->m_0C = sub_000758E0();
        made->vtable = DAT_003A265C;
    }
    made->m_value = value;
    return made;
}