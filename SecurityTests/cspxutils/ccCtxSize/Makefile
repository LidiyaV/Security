# name of executable to build
EXECUTABLE=ccCtxSize
# C++ source (with .cpp extension)
CPSOURCE=
# C source (.c extension)
CSOURCE= ccCtxSize.c

#
# Note final load with cc, not ld
#
# project-specific libraries, e.g., -lstdc++
#
PROJ_LIBS= 
#
# Optional lib search paths
#
PROJ_LIBPATH=
#
# choose one for cc
#
VERBOSE=
#VERBOSE=-v

#
# Other files to remove at 'make clean' time
#
OTHER_TO_CLEAN=

#
# non-standard frameworks (e.g., -framework foo)
#
PROJ_FRAMEWORKS= 

#
# project-specific includes, with leading -I
#
PROJ_INCLUDES= -I$(LOCAL_BUILD)/include

#
# Optional C flags (warnings, optimizations, etc.)
#
PROJ_CFLAGS=

#
# Optional link flags (using cc, not ld)
#
# this is for linking against a custom libSystem...this is where it goes.
# You also need to do a setenv DYLD_LIBRARY_PATH /tmp/System/Debug to run.
#PROJ_LDFLAGS= -L/tmp/System/Debug
PROJ_LDFLAGS=

#
# Optional dependencies
#
PROJ_DEPENDS=

include ../Makefile.cdsa
