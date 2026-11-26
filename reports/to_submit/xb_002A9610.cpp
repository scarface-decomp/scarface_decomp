// bin: xb
// va: 0x002A9610
// what: Writes one character as UTF-16 (one unit or a surrogate pair) if there is room; a character out of range is replaced by the fallback character given.
// tool: Claude (from the bytes; UTF-16 is public)

int __cdecl sub_002A9610(unsigned int character, unsigned short* to, unsigned int room, int fallback,
                         int* bytes, int unused)
{
    int units;
    if (character <= 0xFFFF)
    {
        units = 1;
    }
    else if (character < 0x10FFFF)
    {
        units = 2;
    }
    else
    {
        // not a character: write the fallback instead, with no fallback of its own
        int result = sub_002A9610(fallback, to, room, 0, bytes, unused);
        if (result == -2)
        {
            result = -6;
        }
        return result;
    }

    if (room < (unsigned int)(units * 2))
    {
        return -1;
    }

    if (character <= 0xFFFF)
    {
        if (character >= 0xD800 && character <= 0xDFFF)
        {
            return -2;
        }
        to[0] = (unsigned short)character;
    }
    else if (character < 0x10FFFF)
    {
        character -= 0x10000;
        *to++ = (unsigned short)((character >> 10) + 0xD800);
        *to = (unsigned short)((character & 0x3FF) + 0xDC00);
    }
    else
    {
        if (fallback == 0)
        {
            return -4;
        }
        to[0] = (unsigned short)(fallback & 0xFF);
    }
    *bytes = units * 2;
    return 0;
}
