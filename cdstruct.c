
/* symbols for Grep */
#define CDSTRUCT_ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define CSTRUCT_DECL(p) void p ()
#define DSTRUCT_DECL(p) void p ()
#define CSTRUCT_ENTRY(e)   e
#define DSTRUCT_ENTRY(e)   e
#define CSTRUCT()           \
    do {                    \
        for (int i = 0; i < CDSTRUCT_ARRAY_SIZE(cstruct); ++i) \
            cstruct[i]();   \
    } while (0)
#define DSTRUCT()           \
    do {                    \
        for (int i = 0; i < CDSTRUCT_ARRAY_SIZE(cstruct); ++i) \
            dstruct[i]();   \
    } while (0)


typedef void (*CStructFunc)(void);
typedef void (*DStructFunc)(void);



/* add your constructor function symbols here */
CSTRUCT_DECL(DummyConstructor);
/* add your destructor function symbols here */
DSTRUCT_DECL(DummyDestructor);

/* add your constructors to the list */
CStructFunc cstruct[] = {
    CSTRUCT_ENTRY(DummyConstructor),
};

/* add your destructors to the list */
DStructFunc dstruct[] = {
    DSTRUCT_ENTRY(DummyDestructor),
};

void DummyConstructor(void) { return; }
void DummyDestructor(void) { return; }
