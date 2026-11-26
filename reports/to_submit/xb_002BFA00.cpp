// bin: xb
// va: 0x002BFA00
// what: Converts 16-bit text to 8-bit text one character at a time, stopping with an error when the destination is full.
// tool: Claude (from SPEC-016)

extern "C" bool __cdecl sub_002A95A0(const unsigned short* source, int* consumed, unsigned int* character, int c);
extern "C" int __cdecl sub_002A9430(unsigned int character, char* destination, int room, int a, int* produced, int c);

// 16-bit text to 8-bit text, one character at a time (SPEC-016 section 10.1). File-local: the compiler
// passes its first two arguments in ECX and EAX.
static int sub_002BFA00(char* destination, const unsigned short* source, int a, int capacity, int c)
{
    if ((const void*)source == (const void*)destination)
    {
        return -5;
    }
    const unsigned short* in = source;
    char* out = destination;
    int written = 0;
    while (*in != 0)
    {
        unsigned int character;
        int consumed;
        int produced;
        if (!sub_002A95A0(in, &consumed, &character, c))
        {
            return -2;
        }
        int result = sub_002A9430(character, out, capacity - written - 1, a, &produced, c);
        if (result != 0)
        {
            if (result == -1)
            {
                *out = 0;
                return -1;
            }
            return result;
        }
        in = (const unsigned short*)((const char*)in + consumed);
        out += produced;
        written += produced;
    }
    *out = 0;
    return 0;
}

int __cdecl sub_002C0480(char* destination, const unsigned short* source, int a, int capacity, int c)
{
    if (destination == 0)
    {
        return -3;
    }
    if (source == 0)
    {
        return -2;
    }
    return sub_002BFA00(destination, source, a, capacity, c);
}
