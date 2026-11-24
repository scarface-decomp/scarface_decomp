// bin: xb
// va: 0x00013C50
// what: Indexes the global pointer table dereferenced from DAT_0046B21C using a signed 16-bit index.
// tool: Gemini 4 Neon

extern "C" int** DAT_0046B21C;

int __cdecl sub_00013C50(short index)
{
    return (*DAT_0046B21C)[index];
}
