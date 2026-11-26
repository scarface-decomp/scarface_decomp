// bin: xb
// va: 0x002BFCF0
// what: Reads from a signed save file by handing the request to the signed-read helper, with this drive supplying the blocks.
// tool: Claude (from SPEC-016)

namespace core
{
    class XboxSaveDrive;

    // The part of the object in front of the two interfaces (SPEC-016 section 9).
    class DriveFront
    {
    public:
        virtual void Front00();

        char m_pad04[0xD4];
    };

    // The signed-read interface, at +0xD8.
    class SignedRead
    {
    public:
        virtual int Read00() = 0;

        int sub_002CC160(XboxSaveDrive* drive, void* file, const char* name, unsigned int position, void* to,
                         unsigned int count, unsigned int* done, int space);
    };

    class XboxSaveDrive : public DriveFront, public SignedRead
    {
    public:
        virtual int Read00();
        int vfunc_14(void* file, const char* name, int unused, unsigned int position, void* to, unsigned int count,
                     unsigned int* done, int space);
    };
}

int core::XboxSaveDrive::vfunc_14(void* file, const char* name, int unused, unsigned int position, void* to,
                                  unsigned int count, unsigned int* done, int space)
{
    return SignedRead::sub_002CC160(this, file, name, position, to, count, done, space);
}
