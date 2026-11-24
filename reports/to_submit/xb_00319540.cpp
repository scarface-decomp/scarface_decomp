// bin: xb
// va: 0x00319540
// what: Start-up code (a static initializer): stores the name key of "car_purchased" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319540 (0x00319540, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B962C[];
extern "C" int DAT_0048C1CC;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00319540(void)
{
    DAT_0048C1CC = sub_00243FA0((int)DAT_003B962C, 0);
}
