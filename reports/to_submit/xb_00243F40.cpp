// bin: xb
// va: 0x00243F40
// what: The 64-bit name key: h = h * 65599, each character + 0x20 if below 'a', XORed in; no text gives the starting value back.
// tool: Claude (from the bytes; the 32-bit key at 0x243FA0 is the same idea)
unsigned __int64 __cdecl sub_00243F40(const char* text, unsigned __int64 h)
{
    if (text != 0)
    {
        while (*text != 0)
        {
            h = h * 65599;
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
        return h;
    }
    return h;
}
