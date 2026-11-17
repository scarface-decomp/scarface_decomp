// bin: xb
// va: 0x000E9AE0
// tool: the portal's starter code (no AI)
// sub_000E9AE0 (0x000E9AE0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A8ECC[];
extern "C" char DAT_003A8EE0[];
extern "C" char DAT_00487940[];
extern "C" bool DAT_00487964;
extern "C" char DAT_00487968[];
extern "C" unsigned char DAT_0048798C;

void __cdecl sub_000E9AE0(void)
{
    int r_eax, r_edx;
    bool t1, t2;

    r_eax = DAT_00487964;
    if (!(1 & ((unsigned char)r_eax))) {
        *(int*)&DAT_00487964 |= 1;
        r_eax = (int)DAT_003A8ECC;
        r_edx = (int)DAT_00487940;
        r_edx -= (int)DAT_003A8ECC;
        do {
            t1 = *(bool*)r_eax;
            *(bool*)(r_edx + r_eax) = *(bool*)r_eax;
            r_eax += 1;
        } while (t1);
    }
    if (!(DAT_0048798C & 1)) {
        *(int*)&DAT_0048798C |= 1;
        r_eax = (int)DAT_003A8EE0;
        r_edx = (int)DAT_00487968;
        r_edx -= (int)DAT_003A8EE0;
        do {
            t2 = *(bool*)r_eax;
            *(bool*)(r_edx + r_eax) = *(bool*)r_eax;
            r_eax += 1;
        } while (t2);
    }
}
