// bin: proto
// va: 0x000142C0
// what: 
// tool: the portal's starter code (no AI)

// sub_000142C0 (Proto 0x000142C0, 97 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00017190();
    void sub_000171B0(int);
};

extern "C" int DAT_00440BD8[];
extern "C" int DAT_00441410;
extern "C" int DAT_00441424;
extern "C" int __cdecl sub_000126F0(int);
extern "C" int __cdecl sub_00025140(int, int);

void __cdecl sub_000142C0(int a1, int a2)
{
    int t2, t3, t5;

    if (sub_000126F0(a1) == -1) {
        if (DAT_00441424 >= 64) goto L_60;
        t2 = sub_00025140(132, DAT_00441410);
        if (!t2) goto L_60;
        t3 = ((Object*)t2)->sub_00017190();
        if (t3) {
            ((Object*)t3)->sub_000171B0(a2);
            t5 = DAT_00441424;
            DAT_00440BD8[DAT_00441424] = t3;
            DAT_00441424 = t5 + 1;
        }
    }
L_60:
    ;
}
