// bin: xb
// va: 0x001D7940
// what: Returns the 32-bit element at the signed 16-bit index from the array pointer at -0x10.
// tool: Gemini 4 Neon

class TapeTrackLibrary
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(short index);
};

int TapeTrackLibrary::vfunc_01(short index)
{
    return (*(int**)((char*)this - 0x10))[index];
}
