// bin: xb
// va: 0x001EA1A0
// what: Gets the script field cleanupPolicy of SpawnObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001EA1A0 (0x001EA1A0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043DCD8[];

int __cdecl sub_001EA1A0(int a1)
{
    return DAT_0043DCD8[*(char*)(a1 + 118)];
}
