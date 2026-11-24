// bin: xb
// va: 0x000EA550
// what: Compares the signed 32-bit fields at +0x04 of two objects and returns 1 if the first is less.
// tool: Gemini 4 Neon

struct Item_000EA550
{
    int m_Field00;
    int m_Field04; // +0x04
};

unsigned char __cdecl sub_000EA550(const Item_000EA550* a, const Item_000EA550* b)
{
    return a->m_Field04 < b->m_Field04;
}
