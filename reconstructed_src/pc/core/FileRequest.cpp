// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/FileRequest.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::FileRequest::vfunc_02 (0x006E3770, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E3770
// what: 
// tool: the portal's starter code (no AI)

// core::FileRequest::vfunc_02 (PC 0x006E3770, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int FileRequest::vfunc_02(int a1)
{
    return a1 == m_Field08;
}

}

// ============================================================================
// [VERIFIED] core::FileRequest::vfunc_04 (0x006E3780, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileRequest::vfunc_04 (0x002A9980), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E3780
// what: After an error: refreshes the drive's media information and records the drive's error on the file.
// tool: Claude (from SPEC-020)

unsigned int __cdecl sub_00250E80(unsigned int size, unsigned int unit);

namespace core
{
    class Request;
    class File;
    class Drive;

    // The file's read cache (0x2C bytes, SPEC-020 H4).
    class Cache
    {
    public:
        bool sub_002BE6F0();    // whether it holds the file
        void sub_002BE710();    // closes it
        int sub_002BEAC0(Drive* drive, void* handle, const char* name, int base, unsigned int position, void* buffer,
                         unsigned int length, unsigned int* done, int how);     // reads through the cache
        int m_Words[0xB];
    };

    // The media description a drive keeps (0x54 bytes); only its size matters here.
    struct MediaInfo
    {
        unsigned int m_Words[0x15];
    };

    // The real drive (SPEC-016, SPEC-017): the slots its requests call.
    class Drive
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
        virtual unsigned int vfunc_08();
        virtual int vfunc_09();                                             // refresh the media information
        virtual void vfunc_10();
        virtual int vfunc_11(const char* name, int mode, bool write, void* picture, unsigned int maxSize,
                             void** handle, unsigned int* size);                    // open a saved game
        virtual int vfunc_12(void* handle, const char* name);               // close a file
        virtual int vfunc_13(void* handle, const char* name);               // commit a file
        virtual int vfunc_14(void* handle, const char* name, int base, unsigned int position, void* buffer,
                             unsigned int length, unsigned int* done, int how);             // read
        virtual int vfunc_15(void* handle, const char* name, int base, unsigned int position, const void* buffer,
                             unsigned int length, unsigned int* done, unsigned int* size, int how);  // write
        virtual int vfunc_16();                                             // format
        virtual int vfunc_17(const char* name);                             // create a directory
        virtual int vfunc_18(const char* name);                             // destroy a directory
        virtual int vfunc_19(const char* name);                             // destroy a file
        virtual int vfunc_20(const char* name, int what, void** search, bool first);    // find first
        virtual int vfunc_21(void** search, int what);                      // find next
        virtual void vfunc_22(void** search);                               // find close
        int sub_006E60C0();                                                 // the drive's last error
        MediaInfo* sub_002AC430();                                          // its media information
        void sub_002AC6A0(void* owner, int priority);                       // cancel an owner's requests
        int sub_002AC6E0(int a, int b);
    };

    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // An open file (SPEC-019 section 3).
    class File : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18  requests not finished yet
        bool m_Open;            // +0x1C
        bool m_Write;           // +0x1D
        char m_Name[0x102];     // +0x1E
        int m_Base;             // +0x120
        unsigned int m_Position;    // +0x124
        unsigned int m_Size;        // +0x128
        Cache m_Cache;          // +0x12C
        int m_Field158;         // +0x158
        void* m_Handle;         // +0x15C  the drive's handle for the file
        bool m_SaveGame;        // +0x160
        int m_TransferSize;     // +0x164
    };

    // One user's handle on a drive (SPEC-019 section 2).
    class InstanceDrive : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        void* m_Search;         // +0x1C  the drive's handle for the open directory search
        bool m_FindOpen;        // +0x20
    };

    // Work queued on a drive's thread (SPEC-020).
    class Request
    {
    public:
        virtual ~Request();
        virtual int vfunc_01();                 // do the work: 0 error, 1 done, 2 more to do
        virtual bool vfunc_02(void* key);
        virtual Drive* vfunc_03();
        virtual int vfunc_04();                 // prepare again after an error
        virtual int vfunc_05();
        virtual int vfunc_06();
        Request* m_Next;        // +0x04
    };

    // A request on an open file.
    class FileRequest : public Request
    {
    public:
        File* m_File;           // +0x08
        virtual int vfunc_04();
        // Records the error on the file under its lock and hands the status back.
        int Finish(int status, int error)
        {
            m_File->Lock();
            m_File->m_LastError = error;
            m_File->Unlock();
            return status;
        }
    };

    // A request on a drive handle.
    class DriveRequest : public Request
    {
    public:
        InstanceDrive* m_Drive; // +0x08
        // Records the error on the drive handle under its lock and hands the status back.
        int Finish(int status, int error)
        {
            m_Drive->Lock();
            m_Drive->m_LastError = error;
            m_Drive->Unlock();
            return status;
        }
    };

}

int core::FileRequest::vfunc_04()
{
    Drive* drive = m_File->m_Drive;
    int status = drive->vfunc_09();
    return Finish(status, drive->sub_006E60C0());
}

// ============================================================================
// [VERIFIED] core::FileRequest::vfunc_05 (0x006E37C0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileRequest::vfunc_05 (Proto 0x0026C280), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileRequest::vfunc_05 (Proto 0x006E37C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
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
};

namespace core {

class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void FileRequest::vfunc_05()
{
    m_Field08->vfunc_26();
}

}

// ============================================================================
// [VERIFIED] core::FileRequest::vfunc_03 (0x006E3F10, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileRequest::vfunc_03 (Proto 0x0026C9A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileRequest::vfunc_03 (Proto 0x006E3F10, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int FileRequest::vfunc_03()
{
    return *(int*)(m_Field08 + 12);
}

}

