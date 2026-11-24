// bin: xb
// va: 0x0001EDD0
// what: Looks up an entry by byte index in the global table *DAT_0047151C and returns its byte at +0x28.
// tool: Gemini 4 Neon

struct Entry_0001EDD0
{
    char m_pad00[0x28];
    unsigned char m_Field28; // +0x28
};

extern "C" Entry_0001EDD0*** DAT_0047151C;

unsigned char __cdecl sub_0001EDD0(unsigned char index)
{
    return (*DAT_0047151C)[index]->m_Field28;
}
