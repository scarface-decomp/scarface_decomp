// bin: xb
// va: 0x000EA570
// what: Compares the signed 32-bit fields at +0x08 of two objects and returns 1 if the first is less.
// tool: Gemini 4 Neon

struct Item_000EA570
{
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

unsigned char __cdecl sub_000EA570(const Item_000EA570* a, const Item_000EA570* b)
{
    return a->m_Field08 < b->m_Field08;
}
