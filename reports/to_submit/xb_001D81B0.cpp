// bin: xb
// va: 0x001D81B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001D81B0 (0x001D81B0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000778D0(void);
extern "C" void __cdecl sub_00077900(int);

class Class_001D81B0
{
public:
    void sub_001D81B0();
};

void Class_001D81B0::sub_001D81B0()
{
    int r_ecx, t1;

    r_ecx = (int)this;
    *(bool*)(r_ecx + 62) = false;
    *(bool*)(r_ecx + 64) = true;
    if (!*(int*)(r_ecx + 52)) {
        t1 = *(int*)(r_ecx + 48);
        if (!*(int*)(r_ecx + 48)) goto L_1D;
        *(int*)(r_ecx + 52) = t1;
        *(bool*)(r_ecx + 63) = true;
    }
L_1D:
    *(int*)(r_ecx + 48) = 0;
    sub_00077900(500);
    sub_000778D0();
}
