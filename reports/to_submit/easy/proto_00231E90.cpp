// bin: proto
// va: 0x00231E90
// tool: the portal's starter code (no AI)
// pure3d::TextureLoader::vfunc_06 (0x00231E90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_00231B90(int);

namespace pure3d {

class TextureLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2, int a3, int a4);
};

void TextureLoader::vfunc_06(int a1, int a2, int a3, int a4)
{
    int t1;

    t1 = sub_00231B90(a3);
    if (t1) {
        *(int*)a1 = t1;
        *(int*)a2 = *(int*)(t1 + 8);
    }
}

}
