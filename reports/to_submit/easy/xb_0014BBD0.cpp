// bin: xb
// va: 0x0014BBD0
// tool: the portal's starter code (no AI)
// sub_0014BBD0 (0x0014BBD0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0014BBB0(int);
};

class Class_0014BBD0
{
public:
    void sub_0014BBD0(int a1);
};

void Class_0014BBD0::sub_0014BBD0(int a1)
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 44);
    if (r_eax) {
        r_ecx = *(int*)r_eax;
        if (r_ecx) {
            ((Object*)r_ecx)->sub_0014BBB0(a1);
            return;
        }
        r_ecx = a1;
        *(int*)r_eax = a1;
        return;
    }
    *(int*)(r_ecx + 44) = a1;
}
