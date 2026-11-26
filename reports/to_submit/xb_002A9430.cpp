// bin: xb
// va: 0x002A9430
// what: Writes one character as UTF-8 (one to four bytes) if there is room; a character out of range is replaced by the fallback character given.
// tool: Claude (from the bytes; the game follows Unicode's public reference conversion)

extern "C" const unsigned char DAT_003DA5B0[];      // for each length: the marker bits of the first byte

int __cdecl sub_002A9430(unsigned int character, char* to, unsigned int room, int fallback, int* bytes,
                         int unused)
{
    unsigned int count;
    if (character < 0x80)
    {
        count = 1;
    }
    else if (character < 0x800)
    {
        count = 2;
    }
    else if (character < 0x10000)
    {
        count = 3;
    }
    else if (character < 0x200000)
    {
        count = 4;
    }
    else
    {
        if (fallback == 0)
        {
            return -4;
        }
        // not a character: write the fallback instead, with no fallback of its own
        int result = sub_002A9430(fallback, to, room, 0, bytes, unused);
        if (result == -2)
        {
            result = -6;
        }
        return result;
    }

    if (room < count)
    {
        return -1;
    }

    to += count;
    switch (count)
    {
    // each case falls through to the next: the bytes are written from the last one back
    case 4:
        *--to = (char)((character & 0x3F) | 0x80);
        character >>= 6;
    case 3:
        *--to = (char)((character & 0x3F) | 0x80);
        character >>= 6;
    case 2:
        *--to = (char)((character & 0x3F) | 0x80);
        character >>= 6;
    case 1:
        *--to = (char)(character | DAT_003DA5B0[count]);
    }
    *bytes = count;
    return 0;
}
