// verify: python portal/verify.py reports/to_submit/xb_0029E8E0.cpp --va 0x0029E8E0 --bin xb --match '?PopState@pddiBaseContext'
// bin: xb
// va: 0x0029E8E0
// what: Pops the saved render, view, lighting, fog and stencil states the mask names, and applies each one that is now current.
// tool: Claude Fable 5.2 (from SPEC-014 section 2)
// The backend library keeps a frame pointer in every function, the compiler-written ones included.
#pragma optimize("y", off)

namespace pure3d {

class pddiBaseContext;

// One saved set of render settings. Slot 0 applies the state to the context.
class pddiState
{
public:
    virtual void Apply(pddiBaseContext* context);
};

struct pddiViewPart { int v[4]; };

class pddiViewState : public pddiState
{
public:
    int m_field04, m_field08, m_field0C, m_field10;
    pddiViewPart m_part14;
    pddiViewPart m_part24;
};

class pddiRenderState : public pddiState
{
public:
    int m_field04; bool m_flag08; int m_field0C; bool m_flag10; int m_field14;
    bool m_flag18, m_flag19, m_flag1A, m_flag1B;
};

struct pddiLight { int v[31]; };

class pddiLightingState : public pddiState
{
public:
    pddiLight m_lights[8];
    int m_field3E4, m_field3E8;
};

class pddiFogState : public pddiState
{
public:
    bool m_enabled; int m_field08, m_field0C, m_field10;
};

class pddiStencilState : public pddiState
{
public:
    bool m_enabled; int m_field08, m_field0C, m_field10, m_field14, m_field18, m_field1C, m_field20;
};

template <class T> class pddiStack
{
public:
    virtual ~pddiStack();
    T* Top() { return &m_data[m_top]; }
    void Push() { ++m_top; m_data[m_top] = m_data[m_top - 1]; }
    void Pop() { --m_top; }
    int m_capacity;
    int m_top;
    T* m_data;
};

class pddiBaseContext
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
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void vfunc_86();
    virtual void vfunc_87();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_90();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void vfunc_93();
    virtual void vfunc_94();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_97();
    virtual void vfunc_98();
    virtual void PushState(unsigned char mask);
    virtual void PopState(unsigned char mask);
    char m_pad04[0x134];
    pddiStack<pddiViewState>* m_viewStack;          // +0x138
    pddiStack<pddiRenderState>* m_renderStack;      // +0x13C
    pddiStack<pddiLightingState>* m_lightingStack;  // +0x140
    pddiStack<pddiFogState>* m_fogStack;            // +0x144
    pddiStack<pddiStencilState>* m_stencilStack;    // +0x148
    pddiViewState* m_viewState;                     // +0x14C
    pddiRenderState* m_renderState;                 // +0x150
    pddiLightingState* m_lightingState;             // +0x154
    pddiFogState* m_fogState;                       // +0x158
    pddiStencilState* m_stencilState;               // +0x15C
};

void pddiBaseContext::PopState(unsigned char mask)
{
    if (mask & 1)
    {
        m_renderStack->Pop();
        m_renderState = m_renderStack->Top();
        m_renderState->Apply(this);
    }
    if (mask & 2)
    {
        m_viewStack->Pop();
        m_viewState = m_viewStack->Top();
        m_viewState->Apply(this);
    }
    if (mask & 4)
    {
        m_lightingStack->Pop();
        m_lightingState = m_lightingStack->Top();
        m_lightingState->Apply(this);
    }
    if (mask & 8)
    {
        m_fogStack->Pop();
        m_fogState = m_fogStack->Top();
        m_fogState->Apply(this);
    }
    if (mask & 16)
    {
        m_stencilStack->Pop();
        m_stencilState = m_stencilStack->Top();
        m_stencilState->Apply(this);
    }
}

}
