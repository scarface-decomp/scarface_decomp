// bin: xb
// va: 0x00314F30
// what: Start-up code (a static initializer): stores the name key of "InputLeftXAxis" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314F30 (0x00314F30, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4B5C[];
extern "C" int DAT_0048674C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00314F30(void)
{
    DAT_0048674C = sub_00243FA0((int)DAT_003A4B5C, 0);
}
