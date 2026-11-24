// bin: proto
// va: 0x001A0270
// what: 
// tool: the portal's starter code (no AI)

// sub_001A0270 (Proto 0x001A0270, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0006D1C0(void);
extern "C" void __cdecl sub_0006D1F0(void);

class Class_001A0270
{
public:
    void sub_001A0270();
};

void Class_001A0270::sub_001A0270()
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
    sub_0006D1F0();
    sub_0006D1C0();
}
