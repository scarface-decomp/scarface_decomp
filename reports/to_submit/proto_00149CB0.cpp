// bin: proto
// va: 0x00149CB0
// what: 
// tool: the portal's starter code (no AI)

// sub_00149CB0 (Proto 0x00149CB0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00139200();
};

extern "C" bool DAT_0045CC90;
extern "C" int DAT_00462DD4;
extern "C" int __cdecl sub_0013A550(void);

class Class_00149CB0
{
public:
    bool sub_00149CB0();
};

bool Class_00149CB0::sub_00149CB0()
{
    int r_esi, t1;

    r_esi = (int)this;
    if (DAT_0045CC90) {
        return *(int*)(r_esi + 16) == DAT_00462DD4;
    }
    t1 = sub_0013A550();
    if (t1) {
        r_esi = *(int*)(r_esi + 16);
        return ((Object*)t1)->sub_00139200() == r_esi;
    }
    return false;
}
