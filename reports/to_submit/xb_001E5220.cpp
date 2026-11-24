// bin: xb
// va: 0x001E5220
// what: Sets the script field spawnTemplate of ResourceLoader (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001E5220 (0x001E5220, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E8630(int, int);
};

extern "C" int DAT_0048F740;

void __cdecl sub_001E5220(int a1, int a2)
{
    *(int*)(a1 + (*(int*)(a1 + 120) * 4) + 124) = ((Object*)DAT_0048F740)->sub_001E8630(a2, 2);
    *(int*)(a1 + 120) += 1;
}
