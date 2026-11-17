// bin: proto
// va: 0x00065410
// tool: the portal's starter code (no AI)
// sub_00065410 (0x00065410, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000653A0(int, int, int);
};

extern "C" int __stdcall sub_000653A0(int, int, int);

class Class_00065410
{
public:
    void sub_00065410(int a1, int a2);
};

void Class_00065410::sub_00065410(int a1, int a2)
{
    int r_esi;

    r_esi = (int)this;
    *(int*)(r_esi + 16) = ::sub_000653A0(a1, *(int*)(r_esi + 16), a2);
    if (!*(bool*)(r_esi + 37)) goto L_40;
L_22:
    r_esi = *(int*)(r_esi + 24);
    if (r_esi) {
        *(int*)(r_esi + 16) = ((Object*)r_esi)->sub_000653A0(a1, *(int*)(r_esi + 16), a2);
        if (*(bool*)(r_esi + 37)) goto L_22;
    }
L_40:
    ;
}
