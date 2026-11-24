// bin: xb
// va: 0x00063180
// what: Forwards a non-negative 16-bit integer argument to sub_000616E0, or returns 0 when it is negative.
// tool: Gemini 4 Neon

extern "C" int __cdecl sub_000616E0(short value);

int __cdecl sub_00063180(short value)
{
    int result = 0;
    if (value >= 0)
        result = sub_000616E0(value);
    return result;
}
