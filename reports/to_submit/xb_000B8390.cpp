// bin: xb
// va: 0x000B8390
// what: If the pointer at +0x00 is non-null, dereferences it and returns sub_00011770(); otherwise returns 0.
// tool: Gemini 4 Neon

struct Inner_000B8390
{
    int sub_00011770();
};

class Class_000B8390
{
public:
    int sub_000B8390();
    Inner_000B8390** m_Field00; // +0x00
};

int Class_000B8390::sub_000B8390()
{
    int result = 0;
    Inner_000B8390** p = m_Field00;
    if (p) {
        result = (*p)->sub_00011770();
    }
    return result;
}
