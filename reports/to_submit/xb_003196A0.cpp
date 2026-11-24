// bin: xb
// va: 0x003196A0
// what: Start-up code (a static initializer): stores the name key of "business_page_activated" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003196A0 (0x003196A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BE970[];
extern "C" int DAT_0048C89C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_003196A0(void)
{
    DAT_0048C89C = sub_00243FA0((int)DAT_003BE970, 0);
}
