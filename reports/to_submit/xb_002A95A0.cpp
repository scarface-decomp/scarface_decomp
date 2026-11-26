// bin: xb
// va: 0x002A95A0
// what: Reads one character from UTF-16 text (one unit, or a surrogate pair), giving the character and the bytes it took; false for a surrogate out of place.
// tool: Claude (from the bytes; UTF-16 is public)

bool __cdecl sub_002A95A0(const unsigned short* text, int* bytes, unsigned int* character, int unused)
{
    unsigned int value = text[0];
    int units = 1;
    if (value >= 0xD800 && value <= 0xDBFF)
    {
        unsigned int low = text[1];
        if (low < 0xDC00 || low > 0xDFFF)
        {
            return false;
        }
        value = 0x10000 + ((value - 0xD800) << 10) + (low - 0xDC00);
        units = 2;
    }
    else if (value >= 0xDC00 && value <= 0xDFFF)
    {
        return false;
    }
    if (bytes != 0)
    {
        *bytes = units * 2;
    }
    if (character != 0)
    {
        *character = value;
    }
    return true;
}
