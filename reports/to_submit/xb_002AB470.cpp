// bin: xb
// va: 0x002AB470
// what: Constructs a file object for a saved game on a drive and queues the request that opens it.
// tool: Claude (from SPEC-019)

extern "C" char DAT_003DAA74[];     // core::IMutable's table
extern "C" char DAT_003DAA88[];     // core::File's table for the part at +4
extern "C" char DAT_003DAA94[];     // core::File's main table

void* __cdecl sub_002A9880(unsigned int size);      // the request classes' allocator
void __cdecl sub_00250EB0();
int __cdecl sub_00283A80(char* to, const char* from, int size);     // copies a string; negative if it did not fit
char* __cdecl sub_002FC450(char* to, const char* from, unsigned int size);

// The object at +0x12C of a file (0x34 bytes); its own functions know what is inside.
struct FilePart12C
{
    void sub_002BE6C0();    // its constructor
    char m_pad00[0x34];
};

namespace core
{
    class Request;
    class File;

    // The real drive (SPEC-017): only what a file uses of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();
        void sub_002AC690(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
    };

    class SaveGameOpenRequest
    {
    public:
        SaveGameOpenRequest* sub_002AA950(File* file, int a4, bool a3, int a5, int a6);     // the constructor
        char m_Data[0x1C];
    };

    // The lock part of a file (core::IMutable) as its own constructor sees it.
    struct MutablePart
    {
        void* m_Table;      // +0x0
    };

    // An open file on a drive (0x168 bytes), with its tables written as members: this is its constructor.
    class File
    {
    public:
        File* sub_002AB470(Drive* drive, const char* name, bool a3, int a4, int a5, int a6, int priority);

        void* m_Table00;        // +0x00
        void* m_Table04;        // +0x04
        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        FilePart12C m_Field12C; // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };
}

// core::IMutable's constructor. Returning the part keeps its store: written without, the compiler sees that
// the file's own table overwrites it and drops it.
inline core::MutablePart* ConstructMutable(core::MutablePart* part)
{
    part->m_Table = DAT_003DAA74;
    return part;
}

core::File* core::File::sub_002AB470(Drive* drive, const char* name, bool a3, int a4, int a5, int a6, int priority)
{
    ConstructMutable((MutablePart*)&m_Table04);
    m_Table00 = DAT_003DAA94;
    m_Table04 = DAT_003DAA88;
    m_RefCount = 1;
    m_Drive = drive;
    m_Priority = priority;
    m_LastError = 0;
    m_Outstanding = 0;
    m_Open = false;
    m_Field1D = a3;
    m_Field120 = 0;
    m_Field124 = 0;
    m_Field128 = 0;
    m_Field12C.sub_002BE6C0();
    m_Field160 = true;
    m_Field164 = 0x800;
    sub_00250EB0();
    m_Drive->AddRef();
    if (sub_00283A80(m_Name, name, 0x100) < 0)
    {
        sub_002FC450(m_Name, name, 0x100);
        m_Name[0x100] = 0;
    }
    m_Drive->GetCapabilities();
    SaveGameOpenRequest* memory = (SaveGameOpenRequest*)sub_002A9880(sizeof(SaveGameOpenRequest));
    SaveGameOpenRequest* request = memory ? memory->sub_002AA950(this, a4, a3, a5, a6) : 0;
    m_Drive->sub_002AC690((Request*)request, m_Priority, false);
    return this;
}
