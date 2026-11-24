// bin: xb
// va: 0x0020EDB0
// what: Sets the script field requiredDriver of VehicleTemplate (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_0020EDB0 (0x0020EDB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E8630(int, int);
};

extern "C" int DAT_0048F740;

void __cdecl sub_0020EDB0(int a1, int a2)
{
    *(int*)(a1 + 212) = ((Object*)DAT_0048F740)->sub_001E8630(a2, 0);
}
