// bin: xb
// va: 0x0031D3D0
// what: Start-up code (a static initializer): stores the name key of "TrapezoidTemplateGroup" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D3D0 (0x0031D3D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CB558[];
extern "C" int DAT_0049039C;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031D3D0(void)
{
    DAT_0049039C = sub_00244040((int)DAT_003CB558, 0);
}
