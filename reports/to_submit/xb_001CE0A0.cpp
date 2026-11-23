// bin: xb
// va: 0x001CE0A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001CE0A0 (0x001CE0A0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00251350(void);

bool __cdecl sub_001CE0A0(void)
{
    return *(int*)(sub_00251350() + 4) == 43725;
}
