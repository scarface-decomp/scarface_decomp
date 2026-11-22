// bin: proto
// va: 0x001995D0
// what: Allocates a 4,500-byte buffer and records where it starts and ends in globals (both 0 if it fails).
// tool: Claude Opus 5.5 (transplanted from xb:0x001D0FA0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00460238;
extern "C" int DAT_0046023C;
extern "C" int DAT_00460240;
extern "C" int __cdecl sub_002018F0(int, int);

void __cdecl sub_001995D0(void)
{
    int r_eax, r_ecx;

    r_eax = sub_002018F0(14, 4500);
    r_ecx = 0;
    DAT_00460238 = r_eax;
    if (r_eax) {
        DAT_0046023C = r_eax;
        r_eax += 4500;
        DAT_00460240 = r_eax;
        return;
    }
    DAT_0046023C = r_ecx;
    DAT_00460240 = r_ecx;
}