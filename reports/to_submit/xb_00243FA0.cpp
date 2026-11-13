// bin: xb
// va: 0x00243FA0
// what: The game's name key: h = (h * 65599) & 0x7FFFFFFF, each character + 0x20 if below 'a', XORed in; top bit set.
// spec: docs/cleanroom/SPEC-006-lights-placed-props-reflection.md section 5
// tool: Claude Fable 5.2
// sub_00243FA0 (0x00243FA0, 75 bytes): no text, or empty text, gives the starting value back.
extern "C" unsigned int __cdecl sub_00243FA0(const char* text, unsigned int start);

unsigned int __cdecl sub_00243FA0(const char* text, unsigned int start)
{
    if (text == 0 || *text == 0)
    {
        return start;
    }
    unsigned int h = start & 0x7FFFFFFF;
    while (*text != 0)
    {
        h = (h * 65599) & 0x7FFFFFFF;
        if (*text < 'a')
        {
            h ^= *text + 0x20;
        }
        else
        {
            h ^= *text;
        }
        text++;
    }
    return h | 0x80000000;
}
