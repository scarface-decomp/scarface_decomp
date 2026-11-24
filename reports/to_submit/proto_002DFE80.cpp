// bin: proto
// va: 0x002DFE80
// what: Start-up code (a static initializer): stores the name key of "DEC_DecorItemScriptClass" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002DFE80 (Proto 0x002DFE80, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D088[];
extern "C" int DAT_00446538;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002DFE80(void)
{
    DAT_00446538 = sub_00201440((int)DAT_0037D088, 0);
}
