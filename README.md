# tiny library for calling functions before "main"

## Q: Why?
- Because when developing cross platform C applications, i don't want to rely on weird Macro Magic just because Microsoft can't ship a decent compiler
## Q: How do i use it?
- like this:
```c
#include "cdstruct.c"

/* not your real main function */
int main(int argc, char **argv) {
    CSTRUCT();
    
    int result = actualMain(argc, argv);

    DSTRUCT();

    return result;
}
```

## Q: How do i add functions
open cdstruct.c and do this:
```c

/* add the symbol */
CSTRUCT_DECL(yourConstructorFunction);

/* add it to the cstruct array */
CStructFunc cstructs[] = {
    CSTRUCT_ENTRY(yourConstructorFunction),
};

/* same for destructors */
DSTRUCT_DECL(yourDestructorFunction);

DStructFunc dstructs[] = {
    DSTRUCT_ENTRY(yourDestructorFunction),
};
```
