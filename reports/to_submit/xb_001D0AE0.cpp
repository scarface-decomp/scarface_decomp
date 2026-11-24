// bin: xb
// va: 0x001D0AE0
// what: Sets the script field instancePosition of InstanceObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001D0AE0 (0x001D0AE0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001D0820(int);
};

void __cdecl sub_001D0AE0(int a1, int a2)
{
    ((Object*)a1)->sub_001D0820(a2);
}
