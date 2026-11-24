// bin: xb
// va: 0x00231440
// what: 
// tool: the portal's starter code (no AI)

// sub_00231440 (0x00231440, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00492910;

int __cdecl sub_00231440(void)
{
    return *(int*)(DAT_00492910 + 16) != 0;
}
