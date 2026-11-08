#pragma once
// ============================================================================
// SCARFACE: THE WORLD IS YOURS (1.00.2) — MASTER ENGINE TYPES & MACROS
// Target compiler: MSVC 7.1 (Visual C++ Toolkit 2003, cl.exe 13.10.3052)
// ============================================================================

#if defined(_MSC_VER) && _MSC_VER < 1600
    /* MSVC 7.1 has no <stdint.h> */
    typedef signed char        int8_t;
    typedef short              int16_t;
    typedef int                int32_t;
    typedef __int64            int64_t;
    typedef unsigned char      uint8_t;
    typedef unsigned short     uint16_t;
    typedef unsigned int       uint32_t;
    typedef unsigned __int64   uint64_t;
#else
    #include <stdint.h>
#endif

#pragma pack(push, 4)

namespace rad {
    struct IRefCount {
        virtual void AddRef() = 0;
        virtual void Release() = 0;
    };
}

namespace core {
    class BaseObject {
    public:
        virtual ~BaseObject();
    };
}

#pragma pack(pop)
