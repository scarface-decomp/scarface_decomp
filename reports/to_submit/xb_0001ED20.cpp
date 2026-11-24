// bin: xb
// va: 0x0001ED20
// what: Looks up an entry by byte index in the global table *DAT_0047151C and returns its 32-bit field at +0x04.
// tool: Gemini 4 Neon

struct Entry_0001ED20
{
    int m_Field00;
    int m_Field04; // +0x04
};

extern "C" Entry_0001ED20*** DAT_0047151C;

int __cdecl sub_0001ED20(unsigned char index)
{
    return (*DAT_0047151C)[index]->m_Field04;
}
