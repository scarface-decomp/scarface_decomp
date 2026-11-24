// bin: xb
// va: 0x003196E0
// what: Start-up code (a static initializer): stores the name key of "call_for_car_activated" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003196E0 (0x003196E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C06E8[];
extern "C" int DAT_0048D0F4;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_003196E0(void)
{
    DAT_0048D0F4 = sub_00243FA0((int)DAT_003C06E8, 0);
}
