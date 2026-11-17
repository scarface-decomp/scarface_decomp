// bin: proto
// va: 0x0012F360
// tool: the portal's starter code (no AI)
// sub_0012F360 (0x0012F360, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0012F340(int);
};

class Class_0012F360
{
public:
    void sub_0012F360(int a1);
};

void Class_0012F360::sub_0012F360(int a1)
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 44);
    if (r_eax) {
        r_ecx = *(int*)r_eax;
        if (r_ecx) {
            ((Object*)r_ecx)->sub_0012F340(a1);
            return;
        }
        r_ecx = a1;
        *(int*)r_eax = a1;
        return;
    }
    *(int*)(r_ecx + 44) = a1;
}
