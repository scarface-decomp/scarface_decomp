// bin: xb
// va: 0x002A93A0
// what: Reads one character from UTF-8 text (one to four bytes), giving the character and the bytes it took; false for a sequence that is not legal UTF-8.
// tool: Claude (from the bytes; the game follows Unicode's public reference conversion)

extern "C" const char DAT_003DA5B8[];           // for each first byte: how many bytes follow it
extern "C" const unsigned int DAT_003DA598[];   // for each count of following bytes: what to take off the sum

// Is this a legal UTF-8 sequence of the given length? File-local: the compiler passes both arguments in
// registers.
static bool sub_002A9310(const unsigned char* text, int length)
{
    unsigned char value;
    const unsigned char* at = text + length;
    switch (length)
    {
    default:
        return false;
    // each case falls through to the next: the bytes are checked from the last one back
    case 4:
        if ((value = *--at) < 0x80 || value > 0xBF)
        {
            return false;
        }
    case 3:
        if ((value = *--at) < 0x80 || value > 0xBF)
        {
            return false;
        }
    case 2:
        if ((value = *--at) > 0xBF)
        {
            return false;
        }
        switch (*text)
        {
        case 0xE0:
            if (value < 0xA0)
            {
                return false;
            }
            break;
        case 0xF0:
            if (value < 0x90)
            {
                return false;
            }
            break;
        case 0xF4:
            if (value > 0x8F)
            {
                return false;
            }
            break;
        default:
            if (value < 0x80)
            {
                return false;
            }
        }
    case 1:
        if (*text >= 0x80 && *text < 0xC2)
        {
            return false;
        }
    }
    if (*text > 0xF4)
    {
        return false;
    }
    return true;
}

bool __cdecl sub_002A93A0(const unsigned char* text, int* bytes, unsigned int* character, int unused)
{
    unsigned int value = 0;
    int more = DAT_003DA5B8[*text];
    if (!sub_002A9310(text, more + 1))
    {
        return false;
    }
    switch (more)
    {
    // each case falls through to the next
    case 3:
        value += *text++;
        value <<= 6;
    case 2:
        value += *text++;
        value <<= 6;
    case 1:
        value += *text++;
        value <<= 6;
    case 0:
        value += *text++;
    }
    value -= DAT_003DA598[more];
    if (bytes != 0)
    {
        *bytes = more + 1;
    }
    if (character != 0)
    {
        *character = value;
    }
    return true;
}
