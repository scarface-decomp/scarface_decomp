// bin: xb
// va: 0x002BFB50
// what: core::XboxSaveDrive's constructor: sets up the shared worker thread and memory-unit state on first use, and the drive's name and empty handle lists.
// tool: Claude (from SPEC-016 section 14.2)

extern "C" int __cdecl strcmp(const char* a, const char* b);
extern "C" int __cdecl memcmp(const void* a, const void* b, unsigned int count);
#pragma intrinsic(strcmp, memcmp)
extern "C" char* __cdecl strncpy(char* to, const char* from, unsigned int count);

extern "C" char DAT_003DB52C[];     // core::SignedReader's table
extern "C" char DAT_003DB53C[];     // core::SignedWriter's table
extern "C" char DAT_003DB54C[];     // core::XboxSaveDrive's table for the writer part at +0xDC
extern "C" char DAT_003DB55C[];     // core::XboxSaveDrive's table for the reader part at +0xD8
extern "C" char DAT_003DB56C[];     // core::XboxSaveDrive's table for the part at +0xC
extern "C" char DAT_003DB57C[];     // core::XboxSaveDrive's table for the part at +0x4
extern "C" char DAT_003DB584[];     // core::XboxSaveDrive's main table
extern "C" char DAT_00395660[];     // the memory-unit device type
extern "C" void* DAT_0045894C;      // the allocator in use
extern "C" char DAT_004BDDF8[];     // room for the transfer buffer
extern "C" char DAT_004BFE18[];     // the mutex the drives share with the worker thread
extern "C" char* DAT_004BFE38;      // the transfer buffer
extern "C" bool DAT_004BFE48;       // tested before the one-time set-up; nothing sets it

extern "C" unsigned int __stdcall XGetDevices(void* type);
char* __cdecl sub_00250E80(char* value, unsigned int step);         // rounds up to a multiple
void __cdecl sub_00250EB0();
void __cdecl sub_00283B60(void* mutex);                             // sets the mutex up
void* __cdecl AllocateFromHeap(void* allocator, unsigned int size);

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
    void Init()
    {
        unsigned int present = XGetDevices(DAT_00395660);
        m_Present = (unsigned char)((present & 0xF) | ((present >> 12) & 0xF0));
        m_Changed = 0;
    }
    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

extern "C" MemoryUnits DAT_004BDDF0;

namespace core
{
    // The worker thread all drives share (0xCC bytes).
    class DriveThread
    {
    public:
        virtual void AddRef();
        DriveThread* sub_002C1B00(void* mutex, void* allocator);    // its constructor
        char m_pad04[0xC8];
    };
}

extern "C" core::DriveThread* DAT_004BFE34;     // the one shared worker thread

// The two interface parts (core::SignedReader at +0xD8, core::SignedWriter at +0xDC), whose constructors
// the compiler expands before the class's own tables go in.
struct InterfaceParts
{
    void* m_ReaderTable;    // +0x0
    void* m_WriterTable;    // +0x4
};

inline void ConstructInterfaces(InterfaceParts* parts)
{
    parts->m_ReaderTable = DAT_003DB52C;
    parts->m_WriterTable = DAT_003DB53C;
}

// One running search: the text the saves' names must start with, and the system's search handle.
struct SearchEntry
{
    unsigned short m_Text[0x102];   // +0x000
    void* m_Handle;                 // +0x204, 0xFFFFFFFF when unused
};

namespace core
{
    class XboxSaveDrive
    {
    public:
        XboxSaveDrive* sub_002AC7E0();      // core::Drive's constructor
        XboxSaveDrive* sub_002BFB50(const char* name, void* allocator);

        void* m_Table00;            // +0x00
        void* m_Table04;            // +0x04
        void* m_Allocator;          // +0x08
        void* m_Table0C;            // +0x0C
        char m_pad10[0x7C];
        char m_VolumeName[0x41];    // +0x8C
        char m_padCD[0x7];
        DriveThread* m_Thread;      // +0xD4
        void* m_TableD8;            // +0xD8
        void* m_TableDC;            // +0xDC
        unsigned int m_Capabilities;    // +0xE0
        unsigned int m_OpenFiles;   // +0xE4
        char m_Name[0x11];          // +0xE8
        bool m_Mounted;             // +0xF9
        char m_DriveLetter;         // +0xFA
        void* m_Unsized[4];         // +0xFC  files whose first block still needs its size
        SearchEntry m_Pool[4];      // +0x10C
    };
}

core::XboxSaveDrive* core::XboxSaveDrive::sub_002BFB50(const char* name, void* allocator)
{
    sub_002AC7E0();
    ConstructInterfaces((InterfaceParts*)&m_TableD8);
    m_Table00 = DAT_003DB584;
    m_Table04 = DAT_003DB57C;
    m_Table0C = DAT_003DB56C;
    m_TableD8 = DAT_003DB55C;
    m_TableDC = DAT_003DB54C;
    m_OpenFiles = 0;
    m_Mounted = false;
    m_DriveLetter = 0;
    sub_00250EB0();
    if (!DAT_004BFE48)
    {
        DAT_004BDDF0.Init();
        DAT_004BFE38 = sub_00250E80(DAT_004BDDF8, 0x20);
    }
    if (DAT_004BFE34 == 0)
    {
        sub_00283B60(DAT_004BFE18);
        DAT_0045894C = allocator;
        DriveThread* memory = (DriveThread*)AllocateFromHeap(allocator, sizeof(DriveThread));
        DAT_004BFE34 = memory ? memory->sub_002C1B00(DAT_004BFE18, allocator) : 0;
        m_Thread = DAT_004BFE34;
    }
    else
    {
        m_Thread = DAT_004BFE34;
        m_Thread->AddRef();
    }
    if (strcmp(name, "U:") == 0)
    {
        m_Capabilities = 0xC3;
        m_Mounted = true;
        m_DriveLetter = 'U';
        m_VolumeName[0] = 0;
    }
    else
    {
        m_Capabilities = 0xC7;
    }
    strncpy(m_Name, name, 0x10);
    m_Name[0x10] = 0;
    for (int i = 0; i < 4; i++)
    {
        m_Unsized[i] = (void*)0xFFFFFFFF;
    }
    for (int j = 0; j < 4; j++)
    {
        m_Pool[j].m_Handle = (void*)0xFFFFFFFF;
    }
    return this;
}
