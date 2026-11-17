// bin: xb
// va: 0x0006F6F0
// tool: the portal's starter code (no AI)
// sub_0006F6F0 (0x0006F6F0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0006F680(int, int, int);
};

extern "C" int __stdcall sub_0006F680(int, int, int);

class Class_0006F6F0
{
public:
    void sub_0006F6F0(int a1, int a2);
};

void Class_0006F6F0::sub_0006F6F0(int a1, int a2)
{
    int r_esi;

    r_esi = (int)this;
    *(int*)(r_esi + 16) = ::sub_0006F680(a1, *(int*)(r_esi + 16), a2);
    if (!*(bool*)(r_esi + 37)) goto L_40;
L_22:
    r_esi = *(int*)(r_esi + 24);
    if (r_esi) {
        *(int*)(r_esi + 16) = ((Object*)r_esi)->sub_0006F680(a1, *(int*)(r_esi + 16), a2);
        if (*(bool*)(r_esi + 37)) goto L_22;
    }
L_40:
    ;
}
