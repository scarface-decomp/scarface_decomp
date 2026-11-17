// bin: xb
// va: 0x001EA970
// tool: the portal's starter code (no AI)
// VehicleSpawnObject::vfunc_13 (0x001EA970, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004195CC[];
extern "C" char DAT_0041C604[];
extern "C" int __cdecl sub_0002B9E0(int);
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

class VehicleSpawnObject
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
    char m_pad04[0x1F4];
    int m_Field1F8; // +0x1F8
    int m_Field1FC; // +0x1FC
};

void VehicleSpawnObject::vfunc_13()
{
    int r_ebx, r_edi, t1, t2;

    r_edi = m_Field1FC;
    r_edi -= m_Field1F8;
    r_edi >>= 2;
    r_ebx = 0;
    if (r_edi > 0) {
        do {
            t1 = *(int*)(m_Field1F8 + (r_ebx * 4));
            t2 = m_Field1F8 + (r_ebx * 4);
            if (*(int*)(m_Field1F8 + (r_ebx * 4))) {
                *(int*)t2 = sub_002FC034(sub_0002B9E0(t1), 0, (int)DAT_004195CC, (int)DAT_0041C604, 0);
            }
            r_ebx += 1;
        } while (r_ebx < r_edi);
    }
}
