// bin: xb
// va: 0x000EFDB0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// CheckOutToeToHead::vfunc_05 (0x000EFDB0, 7 bytes)
extern "C" float DAT_003AAC30;

class CheckOutToeToHead
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual float vfunc_05();
};

float CheckOutToeToHead::vfunc_05()
{
    return DAT_003AAC30;
}
