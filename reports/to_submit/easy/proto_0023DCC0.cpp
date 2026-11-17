// bin: proto
// va: 0x0023DCC0
// tool: the portal's starter code (no AI)
// sub_0023DCC0 (0x0023DCC0, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int sub_00325508;
extern "C" char sub_00325540[];
extern "C" char sub_00325548[];

class Class_0023DCC0
{
public:
    void sub_0023DCC0(int a1, int a2, int a3);
};

void Class_0023DCC0::sub_0023DCC0(int a1, int a2, int a3)
{
    int r_eax, t1;

    r_eax = a1;
    if (*(int*)((int)this + (r_eax * 4) + 100) != a2) {
        *(int*)((int)this + (r_eax * 4) + 100) = a2;
        sub_00325508 |= 2048;
        *(int*)(((int)sub_00325540) + (a1 << 7)) = a2;
    }
    if (*(int*)((int)this + (r_eax * 4) + 132) != a3) {
        *(int*)((int)this + (r_eax * 4) + 132) = a3;
        t1 = sub_00325508 | 2048;
        r_eax <<= 7;
        sub_00325508 = t1;
        *(int*)(((int)sub_00325548) + r_eax) = a3;
    }
}
