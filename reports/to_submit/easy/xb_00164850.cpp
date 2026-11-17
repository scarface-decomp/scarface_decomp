// bin: xb
// va: 0x00164850
// tool: the portal's starter code (no AI)
// sub_00164850 (0x00164850, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_0015FB20();
};

extern "C" int DAT_0048A9D8;
extern "C" int __cdecl sub_0015FD80(void);

class Class_00164850
{
public:
    bool sub_00164850();
};

bool Class_00164850::sub_00164850()
{
    int t1, t2;

    t1 = sub_0015FD80();
    t2 = DAT_0048A9D8;
    if (DAT_0048A9D8) {
        if ((int)this != t2) goto L_22;
        if (!t1) goto L_22;
        return ((Object*)t1)->sub_0015FB20();
    }
L_22:
    return false;
}
