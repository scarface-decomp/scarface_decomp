// bin: xb
// va: 0x0021F510
// what: Sets the script field address of AddressObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_0021F510 (0x0021F510, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0021F460(int);
};

void __cdecl sub_0021F510(int a1, int a2)
{
    ((Object*)a1)->sub_0021F460(a2);
}
