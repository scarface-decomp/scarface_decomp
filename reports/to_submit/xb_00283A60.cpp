// bin: xb
// va: 0x00283A60
// what: Returns a quiet negative NaN float value (0xFFC00000).
// tool: Gemini 4 Neon

float __cdecl sub_00283A60()
{
    unsigned int bits = 0xFFC00000;
    return *(float*)&bits;
}
