// bin: proto
// va: 0x001995D0
// tool: the portal's starter code (no AI)
// sub_001995D0 (0x001995D0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00460238;
extern "C" int DAT_0046023C;
extern "C" int DAT_00460240;
extern "C" int __cdecl sub_002018F0(int, int);

void __cdecl sub_001995D0(void)
{
    int r_ecx, t1;

    t1 = sub_002018F0(14, 4500);
    r_ecx = 0;
    DAT_00460238 = t1;
    if (t1) {
        DAT_0046023C = t1;
        DAT_00460240 = t1 + 4500;
        return;
    }
    DAT_0046023C = r_ecx;
    DAT_00460240 = r_ecx;
}
