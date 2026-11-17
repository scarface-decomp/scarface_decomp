// bin: xb
// va: 0x001033E0
// tool: the portal's starter code (no AI)
// sub_001033E0 (0x001033E0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000CE360(void);

int __cdecl sub_001033E0(void)
{
    return sub_000CE360() == 1;
}
