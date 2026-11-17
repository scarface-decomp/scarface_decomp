// bin: proto
// va: 0x00074790
// tool: the portal's starter code (no AI)
// sub_00074790 (0x00074790, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field8C
{
    void sub_00076610(int, int, int);
    void sub_00076AE0(int);
};

extern "C" int DAT_003FD5D0;
extern "C" int __cdecl sub_0006E550(int, int, int);
extern "C" int __cdecl sub_0006EF70(int, int);

class Class_00074790
{
public:
    int sub_00074790(int a1, int a2);
    char m_pad00[0x8C];
    Field8C* m_Field8C; // +0x8C
};

int Class_00074790::sub_00074790(int a1, int a2)
{
    int r_esi;

    r_esi = sub_0006EF70(a1, 0);
    if (r_esi) {
        *(int*)(r_esi + 52) = DAT_003FD5D0;
    }
    m_Field8C->sub_00076610(r_esi, 0, 0);
    m_Field8C->sub_00076AE0(sub_0006E550(r_esi, a2, 0));
    return r_esi != 0;
}
