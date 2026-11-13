// bin: xb
// va: 0x001B68D0
// what: Steps back to the object this one is part of and calls one of its functions with 0.
// tool: Claude Fable 5.2 (look-alike of 0x001B2250, names and addresses swapped)
// PimpYourMansionHUD::vfunc_01 (0x001B68D0, 11 bytes)
struct Object
{
    void sub_001B6090(int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void PimpYourMansionHUD::vfunc_01()
{
    ((Object*)(int)this + -104)->sub_001B6090(0);
}
