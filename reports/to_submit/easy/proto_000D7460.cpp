// bin: proto
// va: 0x000D7460
// tool: the portal's starter code (no AI)
// sub_000D7460 (0x000D7460, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00387DEC[];
extern "C" char DAT_00387E00[];
extern "C" char DAT_0045A044[];
extern "C" bool DAT_0045A068;
extern "C" char DAT_0045A06C[];
extern "C" unsigned char DAT_0045A090;

void __cdecl sub_000D7460(void)
{
    int r_eax, r_edx;
    bool t1, t2;

    r_eax = DAT_0045A068;
    if (!(1 & ((unsigned char)r_eax))) {
        *(int*)&DAT_0045A068 |= 1;
        r_eax = (int)DAT_00387DEC;
        r_edx = (int)DAT_0045A044;
        r_edx -= (int)DAT_00387DEC;
        do {
            t1 = *(bool*)r_eax;
            *(bool*)(r_edx + r_eax) = *(bool*)r_eax;
            r_eax += 1;
        } while (t1);
    }
    if (!(DAT_0045A090 & 1)) {
        *(int*)&DAT_0045A090 |= 1;
        r_eax = (int)DAT_00387E00;
        r_edx = (int)DAT_0045A06C;
        r_edx -= (int)DAT_00387E00;
        do {
            t2 = *(bool*)r_eax;
            *(bool*)(r_edx + r_eax) = *(bool*)r_eax;
            r_eax += 1;
        } while (t2);
    }
}
