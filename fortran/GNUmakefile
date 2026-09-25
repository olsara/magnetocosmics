# Builds libFortranMagField.a from the C++ translations of the original
# Fortran magnetic-field models (Tsyganenko T89/T96/T01 and IGRF).
#
# The models were mechanically translated from Fortran-77 to C++ with f2c
# and verified numerically against the original code (T89 and IGRF are
# bit-/single-precision-exact; T96/T01 agree with the originals to well
# within the models' own finite-difference noise floor).  No external
# libf2c is required: the few runtime helpers used (d_sign, pow_dd, pow_di)
# are provided by f2c_intrinsics.cc.

CXX      = g++
CXXFLAGS = -O2 -I.

CPPSRC = igrf_to_cc.cpp Tsy89c_mod.cpp Tsy96_magcos.cpp \
         Tsyg_01_scaled_to_B0_magcos.cpp \
         bdip_com.cpp birkpar_com.cpp dphi_b_rho0__com.cpp dtheta_com.cpp \
         g_com.cpp igrfcc_com.cpp modenum_com.cpp rcpar_com.cpp tail_com.cpp \
         warp_com.cpp where_in_magnetopause2001__com.cpp \
         f2c_intrinsics.cc

OBJ = $(addsuffix .o,$(basename $(CPPSRC)))

lib/libFortranMagField.a : $(OBJ)
	@if [ ! -d lib ]; then mkdir lib; fi
	@echo "creating lib/libFortranMagField.a ..."
	ar -r lib/libFortranMagField.a $(OBJ)
	rm -f $(OBJ)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@if [ -d lib ]; then echo "cleaning ..."; rm -f *.o lib/libFortranMagField.a; \
	 else echo "Nothing to clean"; fi
