// bin: proto
// va: 0x0022F5F0
// tool: the portal's starter code (no AI)
// pure3d::TextureFont::vfunc_14 (0x0022F5F0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int, int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual int vfunc_32(int, int, int, int, int);
};

extern "C" int DAT_00464C98;

namespace pure3d {

class TextureFont
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x4];
    int m_Field2C; // +0x2C
};

int TextureFont::vfunc_14(int a1)
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = m_Field2C;
    r_ecx = a1;
    r_eax = *(int*)(r_eax + (r_ecx * 4));
    r_ecx = m_Field24;
    *(int*)(r_ecx + 16) = r_eax;
    if (r_eax) {
        r_eax = *(int*)(r_eax + 12);
    } else {
        r_eax = 0;
    }
    r_ecx = *(int*)(r_ecx + 12);
    ((Object*)r_ecx)->vfunc_05(0x584554, r_eax);
    r_eax = m_Field24;
    r_eax = *(int*)(r_eax + 12);
    r_ecx = DAT_00464C98;
    r_eax = ((Object*)r_ecx)->vfunc_32(r_eax, 0, 8225, 0, 0);
    return r_eax;
}

}
