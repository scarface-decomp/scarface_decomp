// bin: xb
// va: 0x00230E80
// what: 
// tool: the portal's starter code (no AI)

// sub_00230E80 (0x00230E80, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491FC4;

int __cdecl sub_00230E80(void)
{
    return *(int*)(*(int*)(DAT_00491FC4 + 4) + 16);
}
