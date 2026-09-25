/* Tsy89c_mod.f -- translated by f2c (version 20240504).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"
#include "f2c_symmap.h"

/*  ------------------------------------------------------------------------ */

/*  The small main program below is an example of how to compute field */
/*   components with T89C. */
/*    See GEOPACK.DOC for an example of field line tracing. */

/*      PROGRAM test_tsy89 */
/*      dimension parmod(10) */
/*  1    print *, '  enter x,y,z,ps,iopt' */
/*      read*, x,y,z,ps,iopt */
/*      call t89c(iopt,parmod,ps,x,y,z,bx,by,bz) */
/*     print *, bx,by,bz */
/*      goto 1 */
/*      end */
/*  ------------------------------------------------------------------------ */

/* Subroutine */ int t89c___(integer *iopt, real *parmod, real *ps, real *x, 
	real *y, real *z__, real *bx, real *by, real *bz)
{
    /* Initialized data */

    static real param[210]	/* was [30][7] */ = { (float)-116.53,(float)
	    -10719.,(float)42.375,(float)59.753,(float)-11363.,(float)1.7844,(
	    float)30.268,(float)-.035372,(float)-.066832,(float).016456,(
	    float)-1.3024,(float).0016529,(float).0020293,(float)20.289,(
	    float)-.025203,(float)224.91,(float)-9234.8,(float)22.788,(float)
	    7.8813,(float)1.8362,(float)-.27228,(float)8.8184,(float)2.8714,(
	    float)14.468,(float)32.177,(float).01,(float)0.,(float)7.0459,(
	    float)4.,(float)20.,(float)-55.553,(float)-13198.,(float)60.647,(
	    float)61.072,(float)-16064.,(float)2.2534,(float)34.407,(float)
	    -.038887,(float)-.094571,(float).027154,(float)-1.3901,(float)
	    .001346,(float).0013238,(float)23.005,(float)-.030565,(float)
	    55.047,(float)-3875.7,(float)20.178,(float)7.9693,(float)1.4575,(
	    float).89471,(float)9.4039,(float)3.5215,(float)14.474,(float)
	    36.555,(float).01,(float)0.,(float)7.0787,(float)4.,(float)20.,(
	    float)-101.34,(float)-13480.,(float)111.35,(float)12.386,(float)
	    -24699.,(float)2.6459,(float)38.948,(float)-.03408,(float)-.12404,
	    (float).029702,(float)-1.4052,(float).0012103,(float).0016381,(
	    float)24.49,(float)-.037705,(float)-298.32,(float)4400.9,(float)
	    18.692,(float)7.9064,(float)1.3047,(float)2.4541,(float)9.7012,(
	    float)7.1624,(float)14.288,(float)33.822,(float).01,(float)0.,(
	    float)6.7442,(float)4.,(float)20.,(float)-181.69,(float)-12320.,(
	    float)173.79,(float)-96.664,(float)-39051.,(float)3.2633,(float)
	    44.968,(float)-.046377,(float)-.16686,(float).048298,(float)
	    -1.5473,(float).0010277,(float).0031632,(float)27.341,(float)
	    -.050655,(float)-514.1,(float)12482.,(float)16.257,(float)8.5834,(
	    float)1.0194,(float)3.6148,(float)8.6042,(float)5.5057,(float)
	    13.778,(float)32.373,(float).01,(float)0.,(float)7.3195,(float)4.,
	    (float)20.,(float)-436.54,(float)-9001.,(float)323.66,(float)
	    -410.08,(float)-50340.,(float)3.9932,(float)58.524,(float)
	    -.038519,(float)-.26822,(float).074528,(float)-1.4268,(float)
	    -.0010985,(float).0096613,(float)27.557,(float)-.056522,(float)
	    -867.03,(float)20652.,(float)14.101,(float)8.3501,(float).72996,(
	    float)3.8149,(float)9.2908,(float)6.4674,(float)13.729,(float)
	    28.353,(float).01,(float)0.,(float)7.4237,(float)4.,(float)20.,(
	    float)-707.77,(float)-4471.9,(float)432.81,(float)-435.51,(float)
	    -60400.,(float)4.6229,(float)68.178,(float)-.088245,(float)
	    -.21002,(float).11846,(float)-2.6711,(float).0022305,(float)
	    .01091,(float)27.547,(float)-.05408,(float)-424.23,(float)1100.2,(
	    float)13.954,(float)7.5337,(float).89714,(float)3.7813,(float)
	    8.2945,(float)5.174,(float)14.213,(float)25.237,(float).01,(float)
	    0.,(float)7.0037,(float)4.,(float)20.,(float)-1190.4,(float)
	    2749.9,(float)742.56,(float)-1110.3,(float)-77193.,(float)7.6727,(
	    float)102.05,(float)-.096015,(float)-.74507,(float).11214,(float)
	    -1.3614,(float).0015157,(float).022283,(float)23.164,(float)
	    -.074146,(float)-2219.1,(float)48253.,(float)12.714,(float)7.6777,
	    (float).57138,(float)2.9633,(float)9.3909,(float)9.7263,(float)
	    11.123,(float)21.558,(float).01,(float)0.,(float)4.4518,(float)4.,
	    (float)20. };
    static integer iop = 10;

    static real a[30];
    static doublereal f[3];
    static integer i__, id;
    static real xi[4];
    static doublereal der[90]	/* was [3][30] */;
    extern /* Subroutine */ int t89___(integer *, real *, real *, doublereal *
	    , doublereal *);



/*   COMPUTES GSM COMPONENTS OF THE MAGNETIC FIELD PRODUCED BY EXTRA- */
/*   TERRESTRIAL CURRENT SYSTEMS IN THE GEOMAGNETOSPHERE. THE MODEL IS */
/*   VALID UP TO GEOCENTRIC DISTANCES OF 70 RE AND IS BASED ON THE MER- */
/*   GED IMP-A,C,D,E,F,G,H,I,J (1966-1974), HEOS-1 AND -2 (1969-1974), */
/*   AND ISEE-1 AND -2  SPACECRAFT DATA SET. */

/*   THIS IS A MODIFIED VERSION (T89c), WHICH REPLACED THE ORIGINAL ONE */
/*     IN 1992 AND DIFFERS FROM IT IN THE FOLLOWING: */

/*   (1)  ISEE-1,2 DATA WERE ADDED TO THE ORIGINAL IMP-HEOS DATASET */
/*   (2)  TWO TERMS WERE ADDED TO THE ORIGINAL TAIL FIELD MODES, ALLOWING */
/*          A MODULATION OF THE CURRENT BY THE GEODIPOLE TILT ANGLE */


/*  REFERENCE FOR THE ORIGINAL MODEL: N.A. TSYGANENKO, A MAGNETOSPHERIC MAGNETIC */
/*       FIELD MODEL WITH A WARPED TAIL CURRENT SHEET: PLANET.SPACE SCI., V.37, */
/*         PP.5-20, 1989. */

/* ----INPUT PARAMETERS: IOPT - SPECIFIES THE GROUND DISTURBANCE LEVEL: */

/*   IOPT= 1       2        3        4        5        6      7 */
/*                  CORRESPOND TO: */
/*    KP= 0,0+  1-,1,1+  2-,2,2+  3-,3,3+  4-,4,4+  5-,5,5+  > =6- */

/*    PS - GEODIPOLE TILT ANGLE IN RADIANS */
/*    X, Y, Z  - GSM COORDINATES OF THE POINT IN EARTH RADII */

/* ----OUTPUT PARAMETERS: BX,BY,BZ - GSM COMPONENTS OF THE MODEL MAGNETIC */
/*                        FIELD IN NANOTESLAS */

/*   THE PARAMETER PARMOD(10) IS A DUMMY ARRAY.  IT IS NOT USED IN THIS */
/*        SUBROUTINE AND IS PROVIDED JUST FOR MAKING IT COMPATIBLE WITH THE */
/*           NEW VERSION (4/16/96) OF THE GEOPACK SOFTWARE. */

/*   THIS RELEASE OF T89C IS DATED  FEB 12, 1996; */
/* -------------------------------------------------------------------------- */


/*              AUTHOR:     NIKOLAI A. TSYGANENKO */
/*                          HSTX CORP./NASA GSFC */

    /* Parameter adjustments */
    --parmod;

    /* Function Body */

    if (iop != *iopt) {

	id = 1;
	iop = *iopt;
	for (i__ = 1; i__ <= 30; ++i__) {
/* L1: */
	    a[i__ - 1] = param[i__ + *iopt * 30 - 31];
	}

    }

    xi[0] = *x;
    xi[1] = *y;
    xi[2] = *z__;
    xi[3] = *ps;
    t89___(&id, a, xi, f, der);
/*          IF (ID.EQ.1) ID=2 */
    *bx = f[0];
    *by = f[1];
    *bz = f[2];
    return 0;
} /* t89c___ */

/* ------------------------------------------------------------------- */
/*  ------------------------------------------------------------------------ */

/* Subroutine */ int t89c_boberg___(integer *iopt, real *parmod, real *ps, 
	real *x, real *y, real *z__, real *bx, real *by, real *bz)
{
    /* Initialized data */

    static integer iop = 10;
    static real param[210]	/* was [30][7] */ = { (float)-116.53,(float)
	    -10719.,(float)42.375,(float)59.753,(float)-11363.,(float)1.7844,(
	    float)30.268,(float)-.035372,(float)-.066832,(float).016456,(
	    float)-1.3024,(float).0016529,(float).0020293,(float)20.289,(
	    float)-.025203,(float)224.91,(float)-9234.8,(float)22.788,(float)
	    7.8813,(float)1.8362,(float)-.27228,(float)8.8184,(float)2.8714,(
	    float)14.468,(float)32.177,(float).01,(float)0.,(float)7.0459,(
	    float)4.,(float)20.,(float)-55.553,(float)-13198.,(float)60.647,(
	    float)61.072,(float)-16064.,(float)2.2534,(float)34.407,(float)
	    -.038887,(float)-.094571,(float).027154,(float)-1.3901,(float)
	    .001346,(float).0013238,(float)23.005,(float)-.030565,(float)
	    55.047,(float)-3875.7,(float)20.178,(float)7.9693,(float)1.4575,(
	    float).89471,(float)9.4039,(float)3.5215,(float)14.474,(float)
	    36.555,(float).01,(float)0.,(float)7.0787,(float)4.,(float)20.,(
	    float)-101.34,(float)-13480.,(float)111.35,(float)12.386,(float)
	    -24699.,(float)2.6459,(float)38.948,(float)-.03408,(float)-.12404,
	    (float).029702,(float)-1.4052,(float).0012103,(float).0016381,(
	    float)24.49,(float)-.037705,(float)-298.32,(float)4400.9,(float)
	    18.692,(float)7.9064,(float)1.3047,(float)2.4541,(float)9.7012,(
	    float)7.1624,(float)14.288,(float)33.822,(float).01,(float)0.,(
	    float)6.7442,(float)4.,(float)20.,(float)-181.69,(float)-12320.,(
	    float)173.79,(float)-96.664,(float)-39051.,(float)3.2633,(float)
	    44.968,(float)-.046377,(float)-.16686,(float).048298,(float)
	    -1.5473,(float).0010277,(float).0031632,(float)27.341,(float)
	    -.050655,(float)-514.1,(float)12482.,(float)16.257,(float)8.5834,(
	    float)1.0194,(float)3.6148,(float)8.6042,(float)5.5057,(float)
	    13.778,(float)32.373,(float).01,(float)0.,(float)7.3195,(float)4.,
	    (float)20.,(float)-436.54,(float)-9001.,(float)323.66,(float)
	    -410.08,(float)-50340.,(float)3.9932,(float)58.524,(float)
	    -.038519,(float)-.26822,(float).074528,(float)-1.4268,(float)
	    -.0010985,(float).0096613,(float)27.557,(float)-.056522,(float)
	    -867.03,(float)20652.,(float)14.101,(float)8.3501,(float).72996,(
	    float)3.8149,(float)9.2908,(float)6.4674,(float)13.729,(float)
	    28.353,(float).01,(float)0.,(float)7.4237,(float)4.,(float)20.,(
	    float)-707.77,(float)-4471.9,(float)432.81,(float)-435.51,(float)
	    -60400.,(float)4.6229,(float)68.178,(float)-.088245,(float)
	    -.21002,(float).11846,(float)-2.6711,(float).0022305,(float)
	    .01091,(float)27.547,(float)-.05408,(float)-424.23,(float)1100.2,(
	    float)13.954,(float)7.5337,(float).89714,(float)3.7813,(float)
	    8.2945,(float)5.174,(float)14.213,(float)25.237,(float).01,(float)
	    0.,(float)7.0037,(float)4.,(float)20.,(float)-1190.4,(float)
	    2749.9,(float)742.56,(float)-1110.3,(float)-77193.,(float)7.6727,(
	    float)102.05,(float)-.096015,(float)-.74507,(float).11214,(float)
	    -1.3614,(float).0015157,(float).022283,(float)23.164,(float)
	    -.074146,(float)-2219.1,(float)48253.,(float)12.714,(float)7.6777,
	    (float).57138,(float)2.9633,(float)9.3909,(float)9.7263,(float)
	    11.123,(float)21.558,(float).01,(float)0.,(float)4.4518,(float)4.,
	    (float)20. };

    static real a[30];
    static doublereal f[3];
    static integer i__, id;
    static real xi[4];
    static doublereal der[90]	/* was [3][30] */;
    extern /* Subroutine */ int t89___(integer *, real *, real *, doublereal *
	    , doublereal *);



/*   COMPUTES GSM COMPONENTS OF THE MAGNETIC FIELD PRODUCED BY EXTRA- */
/*   TERRESTRIAL CURRENT SYSTEMS IN THE GEOMAGNETOSPHERE. THE MODEL IS */
/*   VALID UP TO GEOCENTRIC DISTANCES OF 70 RE AND IS BASED ON THE MER- */
/*   GED IMP-A,C,D,E,F,G,H,I,J (1966-1974), HEOS-1 AND -2 (1969-1974), */
/*   AND ISEE-1 AND -2  SPACECRAFT DATA SET. */

/*   THIS IS A MODIFIED VERSION (T89c), WHICH REPLACED THE ORIGINAL ONE */
/*     IN 1992 AND DIFFERS FROM IT IN THE FOLLOWING: */

/*   (1)  ISEE-1,2 DATA WERE ADDED TO THE ORIGINAL IMP-HEOS DATASET */
/*   (2)  TWO TERMS WERE ADDED TO THE ORIGINAL TAIL FIELD MODES, ALLOWING */
/*          A MODULATION OF THE CURRENT BY THE GEODIPOLE TILT ANGLE */


/*  REFERENCE FOR THE ORIGINAL MODEL: N.A. TSYGANENKO, A MAGNETOSPHERIC MAGNETIC */
/*       FIELD MODEL WITH A WARPED TAIL CURRENT SHEET: PLANET.SPACE SCI., V.37, */
/*         PP.5-20, 1989. */

/* ----INPUT PARAMETERS: IOPT - SPECIFIES THE GROUND DISTURBANCE LEVEL: */

/*   IOPT= 1       2        3        4        5        6      7 */
/*                  CORRESPOND TO: */
/*    KP= 0,0+  1-,1,1+  2-,2,2+  3-,3,3+  4-,4,4+  5-,5,5+  > =6- */

/*    PS - GEODIPOLE TILT ANGLE IN RADIANS */
/*    X, Y, Z  - GSM COORDINATES OF THE POINT IN EARTH RADII */

/* ----OUTPUT PARAMETERS: BX,BY,BZ - GSM COMPONENTS OF THE MODEL MAGNETIC */
/*                        FIELD IN NANOTESLAS */

/*   THE PARAMETER PARMOD(10) IS A DUMMY ARRAY.  IT IS NOT USED IN THIS */
/*        SUBROUTINE AND IS PROVIDED JUST FOR MAKING IT COMPATIBLE WITH THE */
/*           NEW VERSION (4/16/96) OF THE GEOPACK SOFTWARE. */

/*   THIS RELEASE OF T89C IS DATED  FEB 12, 1996; */
/* -------------------------------------------------------------------------- */


/*              AUTHOR:     NIKOLAI A. TSYGANENKO */
/*                          HSTX CORP./NASA GSFC */

    /* Parameter adjustments */
    --parmod;

    /* Function Body */

    if (iop != *iopt) {

	id = 1;
	iop = *iopt;
	for (i__ = 1; i__ <= 30; ++i__) {
/* L1: */
	    a[i__ - 1] = param[i__ + *iopt * 30 - 31];
	}

    }
/*       BOBERG et al formula */
    a[4] = parmod[2] * (float)408.5 - (float)10220.;

    xi[0] = *x;
    xi[1] = *y;
    xi[2] = *z__;
    xi[3] = *ps;
    t89___(&id, a, xi, f, der);
/*          IF (ID.EQ.1) ID=2 */
    *bx = f[0];
    *by = f[1];
    *bz = f[2];
    return 0;
} /* t89c_boberg___ */

/* ------------------------------------------------------------------- */

/* Subroutine */ int t89___(integer *id, real *a, real *xi, doublereal *f, 
	doublereal *der)
{
    /* Initialized data */

    static doublereal a02 = 25.;
    static doublereal xlw2 = 170.;
    static doublereal yn = 30.;
    static doublereal rpi = .31830989;
    static doublereal rt = 30.;
    static doublereal xd = 0.;
    static doublereal xld2 = 40.;
    static doublereal sxc = 4.;
    static doublereal xlwc2 = 50.;
    static doublereal dxl = 20.;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal d__, g, h__;
    static integer i__, l;
    static doublereal p, q, t, v, w, x, y, z__, d0, d2, f1, f3, f5, f7, f9, 
	    s1, w1, w2, w3, w4, w5, w6, x2, y2, z2, y4, dd, fc, ec, fk, rc, 
	    at, dt, fs, wc, hs, dx, om, fy, ex, es, tr, sx, zr, zs, wt, fa0, 
	    ak1, ak2, ak3, ak4, ak5, ak6, ak7, ak8, ak9, a6h, a9t, y410, ro2, 
	    sx1, sy1, zs1, sz1, sy4, ha02, ak10, ak11, ak12, ak13, ak14, ak15,
	     ak16, ak17, del, gam, adr, faq, ddr, dyc, ddy, fyc, ecz, cps, 
	    rqd, att, gsp, sxa, sya, sza, ynd, htp, xrc, dvx, xxd, oms, sps, 
	    ynp, tps, xsm, zsm, dfa0, rtr, rdy, dwx, rtt, zpl, zmn, spl, 
	    ak610, xzr, ak711, yzr, ak812, smn, ak913, rqc, esz, esy, bxt, 
	    byt, bzt, dyc2, ecz2, rqc2, rdx2, rdy2, tlt2, gsy4, yfy1, xsm2, 
	    gamh, dsfc, adsl, bxcl, bycl, adrt, bzcl, xrc16, dwcx, dwcy, fxmn,
	     xghs, rdxl, dsqt, tilt, rqds, rdsq, sxrc, fypr, fydy, wcsp, wtfs,
	     omsv, xsxc, wcsm, fxyp, dzsx, dzsy, xdwx, szrm, ydwy, xywc, szrp,
	     xsmx, fxym, dbxc1, dbxc2, dbzc1, dbzc2, fxpl, fypl, fymn, fzpl, 
	    fzmn, adrt2, dely2, rdyc2, xzyz, rdsq2, rdx2m, brrz1, brrz2, 
	    eszy2, eszz2, dbxdp, dbzdp, facxy, hrdxl, drdyc2, drdyc3, hlwc2m, 
	    hxld2m, rogsm2, hxlw2m, d2zsgy, dbldel;


/*        ***  N.A. Tsyganenko ***  8-10.12.1991  *** */

/*      Calculates dependent model variables and their deriva- */
/*  tives for given independent variables and model parame- */
/*  ters.  Specifies model functions with free parameters which */
/*  must be determined by means of least squares fits (RMS */
/*  minimization procedure). */

/*      Description of parameters: */

/*  ID  - number of the data point in a set (initial assignments are performed */
/*        only for ID=1, saving thus CPU time) */
/*  A   - input vector containing model parameters; */
/*  XI  - input vector containing independent variables; */
/*  F   - output double precision vector containing */
/*        calculated values of dependent variables; */
/*  DER   - output double precision vector containing */
/*        calculated values for derivatives of dependent */
/*        variables with respect to model parameters; */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*      T89 represents external magnetospheric magnetic field */
/*  in Cartesian SOLAR MAGNETOSPHERIC coordinates (Tsyganenko N.A., */
/*  Planet. Space Sci., 1989, v.37, p.5-20; the "T89 model" with the warped */
/*  tail current sheet) + A MODIFICATION ADDED IN APRIL 1992 (SEE BELOW) */

/*      Model formulas for the magnetic field components contain in total */
/*  30 free parameters (17 linear and 13 nonlinear parameters). */
/*      First 2 independent linear parameters A(1)-A(2) correspond to contribu- */
/*  tion from the tail current system, then follow A(3) and A(4) which are the */
/*  amplitudes of symmetric and antisymmetric terms in the contribution from */
/*  the closure currents; A(5) is the ring current amplitude. Then follow the */
/* coefficients A(6)-A(15) which define Chapman-Ferraro+Birkeland current field. */
/*    The coefficients c16-c19  (see Formula 20 in the original paper), */
/*   due to DivB=0 condition, are expressed through A(6)-A(15) and hence are not */
/*    independent ones. */
/*  A(16) AND A(17) CORRESPOND TO THE TERMS WHICH YIELD THE TILT ANGLE DEPEN- */
/*    DENCE OF THE TAIL CURRENT INTENSITY (ADDED ON APRIL 9, 1992) */

/*      Nonlinear parameters: */

/*    A(18) : DX - Characteristic scale of the Chapman-Ferraro field along the */
/*        X-axis */
/*    A(19) : ADR (aRC) - Characteristic radius of the ring current */
/*    A(20) : D0 - Basic half-thickness of the tail current sheet */
/*    A(21) : DD (GamRC)- defines rate of thickening of the ring current, as */
/*             we go from night- to dayside */
/*    A(22) : Rc - an analog of "hinging distance" entering formula (11) */
/*    A(23) : G - amplitude of tail current warping in the Y-direction */
/*    A(24) : aT - Characteristic radius of the tail current */
/*    A(25) : Dy - characteristic scale distance in the Y direction entering */
/*                 in W(x,y) in (13) */
/*    A(26) : Delta - defines the rate of thickening of the tail current sheet */
/*                 in the Y-direction (in T89 it was fixed at 0.01) */
/*    A(27) : Q - this parameter was fixed at 0 in the final version of T89; */
/*              initially it was introduced for making Dy to depend on X */
/*    A(28) : Sx (Xo) - enters in W(x,y) ; see (13) */
/*    A(29) : Gam (GamT) - enters in DT in (13) and defines rate of tail sheet */
/*              thickening on going from night to dayside; in T89 fixed at 4.0 */
/*    A(30) : Dyc - the Dy parameter for closure current system; in T89 fixed */
/*               at 20.0 */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */




    /* Parameter adjustments */
    der -= 4;
    --f;
    --xi;
    --a;

    /* Function Body */

/*   The last four quantities define variation of tail sheet thickness along X */


/*   The two quantities belong to the function WC which confines tail closure */
/*    current in X- and Y- direction */



    if (*id != 1) {
	goto L3;
    }
    for (i__ = 1; i__ <= 30; ++i__) {
	for (l = 1; l <= 3; ++l) {
/* L1: */
	    der[l + i__ * 3] = 0.;
	}
/* L2: */
    }

    dyc = a[30];
/* Computing 2nd power */
    d__1 = dyc;
    dyc2 = d__1 * d__1;
    dx = a[18];
    ha02 = a02 * .5;
/* Computing 2nd power */
    d__1 = dx;
    rdx2m = -1. / (d__1 * d__1);
    rdx2 = -rdx2m;
    rdyc2 = 1. / dyc2;
    hlwc2m = xlwc2 * -.5;
    drdyc2 = rdyc2 * -2.;
    drdyc3 = rdyc2 * 2. * sqrt(rdyc2);
    hxlw2m = xlw2 * -.5;
    adr = a[19];
    d0 = a[20];
    dd = a[21];
    rc = a[22];
    g = a[23];
    at = a[24];
    dt = d0;
    del = a[26];
    p = a[25];
    q = a[27];
    sx = a[28];
    gam = a[29];
    hxld2m = xld2 * -.5;
    adsl = 0.;
    xghs = 0.;
    h__ = 0.;
    hs = 0.;
    gamh = 0.;
    w1 = -.5 / dx;
    dbldel = del * 2.;
    w2 = w1 * 2.;
    w4 = -.33333333333333331;
    w3 = w4 / dx;
    w5 = -.5;
    w6 = -3.;
    ak1 = a[1];
    ak2 = a[2];
    ak3 = a[3];
    ak4 = a[4];
    ak5 = a[5];
    ak6 = a[6];
    ak7 = a[7];
    ak8 = a[8];
    ak9 = a[9];
    ak10 = a[10];
    ak11 = a[11];
    ak12 = a[12];
    ak13 = a[13];
    ak14 = a[14];
    ak15 = a[15];
    ak16 = a[16];
    ak17 = a[17];
    sxa = 0.;
    sya = 0.;
    sza = 0.;
    ak610 = ak6 * w1 + ak10 * w5;
    ak711 = ak7 * w2 - ak11;
    ak812 = ak8 * w2 + ak12 * w6;
    ak913 = ak9 * w3 + ak13 * w4;
    rdxl = 1. / dxl;
    hrdxl = rdxl * .5;
    a6h = ak6 * .5;
    a9t = ak9 / 3.;
    ynp = rpi / yn * .5;
    ynd = yn * 2.;

L3:

    x = xi[1];
    y = xi[2];
    z__ = xi[3];
    tilt = xi[4];
/* Computing 2nd power */
    d__1 = tilt;
    tlt2 = d__1 * d__1;
    sps = sin(tilt);
/* Computing 2nd power */
    d__1 = sps;
    cps = sqrt(1. - d__1 * d__1);

    x2 = x * x;
    y2 = y * y;
    z2 = z__ * z__;
    tps = sps / cps;
    htp = tps * .5;
    gsp = g * sps;
    xsm = x * cps - z__ * sps;
    zsm = x * sps + z__ * cps;

/*   CALCULATE THE FUNCTION ZS DEFINING THE SHAPE OF THE TAIL CURRENT SHEET */
/*    AND ITS SPATIAL DERIVATIVES: */

    xrc = xsm + rc;
/* Computing 2nd power */
    d__1 = xrc;
    xrc16 = d__1 * d__1 + 16.;
    sxrc = sqrt(xrc16);
    y4 = y2 * y2;
    y410 = y4 + 1e4;
    sy4 = sps / y410;
    gsy4 = g * sy4;
    zs1 = htp * (xrc - sxrc);
    dzsx = -zs1 / sxrc;
    zs = zs1 - gsy4 * y4;
    d2zsgy = -sy4 / y410 * 4e4 * y2 * y;
    dzsy = g * d2zsgy;

/*   CALCULATE THE COMPONENTS OF THE RING CURRENT CONTRIBUTION: */

/* Computing 2nd power */
    d__1 = xsm;
    xsm2 = d__1 * d__1;
    dsqt = sqrt(xsm2 + a02);
    fa0 = (xsm / dsqt + 1.) * .5;
    ddr = d0 + dd * fa0;
/* Computing 3rd power */
    d__1 = dsqt;
    dfa0 = ha02 / (d__1 * (d__1 * d__1));
    zr = zsm - zs;
/* Computing 2nd power */
    d__1 = zr;
/* Computing 2nd power */
    d__2 = ddr;
    tr = sqrt(d__1 * d__1 + d__2 * d__2);
    rtr = 1. / tr;
    ro2 = xsm2 + y2;
    adrt = adr + tr;
/* Computing 2nd power */
    d__1 = adrt;
    adrt2 = d__1 * d__1;
    fk = 1. / (adrt2 + ro2);
    dsfc = sqrt(fk);
/* Computing 2nd power */
    d__1 = fk;
    fc = d__1 * d__1 * dsfc;
    facxy = adrt * 3. * fc * rtr;
    xzr = xsm * zr;
    yzr = y * zr;
    dbxdp = facxy * xzr;
    der[17] = facxy * yzr;
    xzyz = xsm * dzsx + y * dzsy;
    faq = zr * xzyz - ddr * dd * dfa0 * xsm;
    dbzdp = fc * (adrt2 * 2. - ro2) + facxy * faq;
    der[16] = dbxdp * cps + dbzdp * sps;
    der[18] = dbzdp * cps - dbxdp * sps;

/*  CALCULATE THE TAIL CURRENT SHEET CONTRIBUTION: */

    dely2 = del * y2;
    d__ = dt + dely2;
    if (abs(gam) < 1e-6) {
	goto L8;
    }
    xxd = xsm - xd;
/* Computing 2nd power */
    d__1 = xxd;
    rqd = 1. / (d__1 * d__1 + xld2);
    rqds = sqrt(rqd);
    h__ = (xxd * rqds + 1.) * .5;
    hs = -hxld2m * rqd * rqds;
    gamh = gam * h__;
    d__ += gamh;
    xghs = xsm * gam * hs;
    adsl = -d__ * xghs;
L8:
/* Computing 2nd power */
    d__1 = d__;
    d2 = d__1 * d__1;
/* Computing 2nd power */
    d__1 = zr;
    t = sqrt(d__1 * d__1 + d2);
    xsmx = xsm - sx;
/* Computing 2nd power */
    d__1 = xsmx;
    rdsq2 = 1. / (d__1 * d__1 + xlw2);
    rdsq = sqrt(rdsq2);
    v = (1. - xsmx * rdsq) * .5;
    dvx = hxlw2m * rdsq * rdsq2;
    om = sqrt(sqrt(xsm2 + 16.) - xsm);
    oms = -om / (om * om + xsm) * .5;
    rdy = 1. / (p + q * om);
    omsv = oms * v;
/* Computing 2nd power */
    d__1 = rdy;
    rdy2 = d__1 * d__1;
    fy = 1. / (y2 * rdy2 + 1.);
    w = v * fy;
    yfy1 = fy * 2. * y2 * rdy2;
    fypr = yfy1 * rdy;
    fydy = fypr * fy;
    dwx = dvx * fy + fydy * q * omsv;
    ydwy = -v * yfy1 * fy;
    ddy = dbldel * y;
    att = at + t;
/* Computing 2nd power */
    d__1 = att;
    s1 = sqrt(d__1 * d__1 + ro2);
    f5 = 1. / s1;
    f7 = 1. / (s1 + att);
    f1 = f5 * f7;
/* Computing 3rd power */
    d__1 = f5;
    f3 = d__1 * (d__1 * d__1);
    f9 = att * f3;
    fs = zr * xzyz - d__ * y * ddy + adsl;
    xdwx = xsm * dwx + ydwy;
    rtt = 1. / t;
    wt = w * rtt;
    brrz1 = wt * f1;
    brrz2 = wt * f3;
    dbxc1 = brrz1 * xzr;
    dbxc2 = brrz2 * xzr;
    der[5] = brrz1 * yzr;
    der[8] = brrz2 * yzr;
    der[50] = der[5] * tlt2;
    der[53] = der[8] * tlt2;
    wtfs = wt * fs;
    dbzc1 = w * f5 + xdwx * f7 + wtfs * f1;
    dbzc2 = w * f9 + xdwx * f1 + wtfs * f3;
    der[4] = dbxc1 * cps + dbzc1 * sps;
    der[7] = dbxc2 * cps + dbzc2 * sps;
    der[6] = dbzc1 * cps - dbxc1 * sps;
    der[9] = dbzc2 * cps - dbxc2 * sps;
    der[49] = der[4] * tlt2;
    der[52] = der[7] * tlt2;
    der[51] = der[6] * tlt2;
    der[54] = der[9] * tlt2;

/*  CALCULATE CONTRIBUTION FROM THE CLOSURE CURRENTS */

    zpl = z__ + rt;
    zmn = z__ - rt;
    rogsm2 = x2 + y2;
/* Computing 2nd power */
    d__1 = zpl;
    spl = sqrt(d__1 * d__1 + rogsm2);
/* Computing 2nd power */
    d__1 = zmn;
    smn = sqrt(d__1 * d__1 + rogsm2);
    xsxc = x - sxc;
/* Computing 2nd power */
    d__1 = xsxc;
    rqc2 = 1. / (d__1 * d__1 + xlwc2);
    rqc = sqrt(rqc2);
    fyc = 1. / (y2 * rdyc2 + 1.);
    wc = (1. - xsxc * rqc) * .5 * fyc;
    dwcx = hlwc2m * rqc2 * rqc * fyc;
    dwcy = drdyc2 * wc * fyc * y;
    szrp = 1. / (spl + zpl);
    szrm = 1. / (smn - zmn);
    xywc = x * dwcx + y * dwcy;
    wcsp = wc / spl;
    wcsm = wc / smn;
    fxyp = wcsp * szrp;
    fxym = wcsm * szrm;
    fxpl = x * fxyp;
    fxmn = -x * fxym;
    fypl = y * fxyp;
    fymn = -y * fxym;
    fzpl = wcsp + xywc * szrp;
    fzmn = wcsm + xywc * szrm;
    der[10] = fxpl + fxmn;
    der[13] = (fxpl - fxmn) * sps;
    der[11] = fypl + fymn;
    der[14] = (fypl - fymn) * sps;
    der[12] = fzpl + fzmn;
    der[15] = (fzpl - fzmn) * sps;

/*   NOW CALCULATE CONTRIBUTION FROM CHAPMAN-FERRARO SOURCES + ALL OTHER */

    ex = exp(x / dx);
    ec = ex * cps;
    es = ex * sps;
    ecz = ec * z__;
    esz = es * z__;
    eszy2 = esz * y2;
    eszz2 = esz * z2;
    ecz2 = ecz * z__;
    esy = es * y;

    der[19] = ecz;
    der[22] = es;
    der[25] = esy * y;
    der[28] = esz * z__;
    der[32] = ecz * y;
    der[35] = esy;
    der[38] = esy * y2;
    der[41] = esy * z2;
    der[45] = ec;
    der[48] = ec * y2;
    der[21] = ecz2 * w1;
    der[33] = ecz2 * w5;
    der[24] = esz * w2;
    der[36] = -esz;
    der[27] = eszy2 * w2;
    der[39] = eszy2 * w6;
    der[30] = eszz2 * w3;
    der[42] = eszz2 * w4;

/*  FINALLY, CALCULATE NET EXTERNAL MAGNETIC FIELD COMPONENTS, */
/*    BUT FIRST OF ALL THOSE FOR C.-F. FIELD: */

    sx1 = ak6 * der[19] + ak7 * der[22] + ak8 * der[25] + ak9 * der[28];
    sy1 = ak10 * der[32] + ak11 * der[35] + ak12 * der[38] + ak13 * der[41];
    sz1 = ak14 * der[45] + ak15 * der[48] + ak610 * ecz2 + ak711 * esz + 
	    ak812 * eszy2 + ak913 * eszz2;
    bxcl = ak3 * der[10] + ak4 * der[13];
    bycl = ak3 * der[11] + ak4 * der[14];
    bzcl = ak3 * der[12] + ak4 * der[15];
    bxt = ak1 * der[4] + ak2 * der[7] + bxcl + ak16 * der[49] + ak17 * der[52]
	    ;
    byt = ak1 * der[5] + ak2 * der[8] + bycl + ak16 * der[50] + ak17 * der[53]
	    ;
    bzt = ak1 * der[6] + ak2 * der[9] + bzcl + ak16 * der[51] + ak17 * der[54]
	    ;
    f[1] = bxt + ak5 * der[16] + sx1 + sxa;
    f[2] = byt + ak5 * der[17] + sy1 + sya;
    f[3] = bzt + ak5 * der[18] + sz1 + sza;

    return 0;
} /* t89___ */

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
/* ------------------------------------------------------------------- */


/* Subroutine */ int t89_boberg___(integer *id, real *a, real *xi, doublereal 
	*f, doublereal *der)
{
    /* Initialized data */

    static doublereal a02 = 25.;
    static doublereal xlw2 = 170.;
    static doublereal yn = 30.;
    static doublereal rpi = .31830989;
    static doublereal rt = 30.;
    static doublereal xd = 0.;
    static doublereal xld2 = 40.;
    static doublereal sxc = 4.;
    static doublereal xlwc2 = 50.;
    static doublereal dxl = 20.;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal d__, g, h__;
    static integer i__, l;
    static doublereal p, q, t, v, w, x, y, z__, d0, d2, f1, f3, f5, f7, f9, 
	    s1, w1, w2, w3, w4, w5, w6, x2, y2, z2, y4, dd, fc, ec, fk, rc, 
	    at, dt, fs, wc, hs, dx, om, fy, ex, es, tr, sx, zr, zs, wt, fa0, 
	    ak1, ak2, ak3, ak4, ak5, ak6, ak7, ak8, ak9, a6h, a9t, y410, ro2, 
	    sx1, sy1, zs1, sz1, sy4, ha02, ak10, ak11, ak12, ak13, ak14, ak15,
	     ak16, ak17, del, gam, adr, faq, ddr, dyc, ddy, fyc, ecz, cps, 
	    rqd, att, gsp, sxa, sya, sza, ynd, htp, xrc, dvx, xxd, oms, sps, 
	    ynp, tps, xsm, zsm, dfa0, rtr, rdy, dwx, rtt, zpl, zmn, spl, 
	    ak610, xzr, ak711, yzr, ak812, smn, ak913, rqc, esz, esy, bxt, 
	    byt, bzt, dyc2, ecz2, rqc2, rdx2, rdy2, tlt2, gsy4, yfy1, xsm2, 
	    gamh, dsfc, adsl, bxcl, bycl, adrt, bzcl, xrc16, dwcx, dwcy, fxmn,
	     xghs, rdxl, dsqt, tilt, rqds, rdsq, sxrc, fypr, fydy, wcsp, wtfs,
	     omsv, xsxc, wcsm, fxyp, dzsx, dzsy, xdwx, szrm, ydwy, xywc, szrp,
	     xsmx, fxym, dbxc1, dbxc2, dbzc1, dbzc2, fxpl, fypl, fymn, fzpl, 
	    fzmn, adrt2, dely2, rdyc2, xzyz, rdsq2, rdx2m, brrz1, brrz2, 
	    eszy2, eszz2, dbxdp, dbzdp, facxy, hrdxl, drdyc2, drdyc3, hlwc2m, 
	    hxld2m, rogsm2, hxlw2m, d2zsgy, dbldel;


/*        ***  N.A. Tsyganenko ***  8-10.12.1991  *** */

/*      Calculates dependent model variables and their deriva- */
/*  tives for given independent variables and model parame- */
/*  ters.  Specifies model functions with free parameters which */
/*  must be determined by means of least squares fits (RMS */
/*  minimization procedure). */

/*      Description of parameters: */

/*  ID  - number of the data point in a set (initial assignments are performed */
/*        only for ID=1, saving thus CPU time) */
/*  A   - input vector containing model parameters; */
/*  XI  - input vector containing independent variables; */
/*  F   - output double precision vector containing */
/*        calculated values of dependent variables; */
/*  DER   - output double precision vector containing */
/*        calculated values for derivatives of dependent */
/*        variables with respect to model parameters; */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*      T89 represents external magnetospheric magnetic field */
/*  in Cartesian SOLAR MAGNETOSPHERIC coordinates (Tsyganenko N.A., */
/*  Planet. Space Sci., 1989, v.37, p.5-20; the "T89 model" with the warped */
/*  tail current sheet) + A MODIFICATION ADDED IN APRIL 1992 (SEE BELOW) */

/*      Model formulas for the magnetic field components contain in total */
/*  30 free parameters (17 linear and 13 nonlinear parameters). */
/*      First 2 independent linear parameters A(1)-A(2) correspond to contribu- */
/*  tion from the tail current system, then follow A(3) and A(4) which are the */
/*  amplitudes of symmetric and antisymmetric terms in the contribution from */
/*  the closure currents; A(5) is the ring current amplitude. Then follow the */
/* coefficients A(6)-A(15) which define Chapman-Ferraro+Birkeland current field. */
/*    The coefficients c16-c19  (see Formula 20 in the original paper), */
/*   due to DivB=0 condition, are expressed through A(6)-A(15) and hence are not */
/*    independent ones. */
/*  A(16) AND A(17) CORRESPOND TO THE TERMS WHICH YIELD THE TILT ANGLE DEPEN- */
/*    DENCE OF THE TAIL CURRENT INTENSITY (ADDED ON APRIL 9, 1992) */

/*      Nonlinear parameters: */

/*    A(18) : DX - Characteristic scale of the Chapman-Ferraro field along the */
/*        X-axis */
/*    A(19) : ADR (aRC) - Characteristic radius of the ring current */
/*    A(20) : D0 - Basic half-thickness of the tail current sheet */
/*    A(21) : DD (GamRC)- defines rate of thickening of the ring current, as */
/*             we go from night- to dayside */
/*    A(22) : Rc - an analog of "hinging distance" entering formula (11) */
/*    A(23) : G - amplitude of tail current warping in the Y-direction */
/*    A(24) : aT - Characteristic radius of the tail current */
/*    A(25) : Dy - characteristic scale distance in the Y direction entering */
/*                 in W(x,y) in (13) */
/*    A(26) : Delta - defines the rate of thickening of the tail current sheet */
/*                 in the Y-direction (in T89 it was fixed at 0.01) */
/*    A(27) : Q - this parameter was fixed at 0 in the final version of T89; */
/*              initially it was introduced for making Dy to depend on X */
/*    A(28) : Sx (Xo) - enters in W(x,y) ; see (13) */
/*    A(29) : Gam (GamT) - enters in DT in (13) and defines rate of tail sheet */
/*              thickening on going from night to dayside; in T89 fixed at 4.0 */
/*    A(30) : Dyc - the Dy parameter for closure current system; in T89 fixed */
/*               at 20.0 */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */




    /* Parameter adjustments */
    der -= 4;
    --f;
    --xi;
    --a;

    /* Function Body */

/*   The last four quantities define variation of tail sheet thickness along X */


/*   The two quantities belong to the function WC which confines tail closure */
/*    current in X- and Y- direction */



    if (*id != 1) {
	goto L3;
    }
    for (i__ = 1; i__ <= 30; ++i__) {
	for (l = 1; l <= 3; ++l) {
/* L1: */
	    der[l + i__ * 3] = 0.;
	}
/* L2: */
    }

    dyc = a[30];
/* Computing 2nd power */
    d__1 = dyc;
    dyc2 = d__1 * d__1;
    dx = a[18];
    ha02 = a02 * .5;
/* Computing 2nd power */
    d__1 = dx;
    rdx2m = -1. / (d__1 * d__1);
    rdx2 = -rdx2m;
    rdyc2 = 1. / dyc2;
    hlwc2m = xlwc2 * -.5;
    drdyc2 = rdyc2 * -2.;
    drdyc3 = rdyc2 * 2. * sqrt(rdyc2);
    hxlw2m = xlw2 * -.5;
    adr = a[19];
    d0 = a[20];
    dd = a[21];
    rc = a[22];
    g = a[23];
    at = a[24];
    dt = d0;
    del = a[26];
    p = a[25];
    q = a[27];
    sx = a[28];
    gam = a[29];
    hxld2m = xld2 * -.5;
    adsl = 0.;
    xghs = 0.;
    h__ = 0.;
    hs = 0.;
    gamh = 0.;
    w1 = -.5 / dx;
    dbldel = del * 2.;
    w2 = w1 * 2.;
    w4 = -.33333333333333331;
    w3 = w4 / dx;
    w5 = -.5;
    w6 = -3.;
    ak1 = a[1];
    ak2 = a[2];
    ak3 = a[3];
    ak4 = a[4];
    ak5 = a[5];
    ak6 = a[6];
    ak7 = a[7];
    ak8 = a[8];
    ak9 = a[9];
    ak10 = a[10];
    ak11 = a[11];
    ak12 = a[12];
    ak13 = a[13];
    ak14 = a[14];
    ak15 = a[15];
    ak16 = a[16];
    ak17 = a[17];
    sxa = 0.;
    sya = 0.;
    sza = 0.;
    ak610 = ak6 * w1 + ak10 * w5;
    ak711 = ak7 * w2 - ak11;
    ak812 = ak8 * w2 + ak12 * w6;
    ak913 = ak9 * w3 + ak13 * w4;
    rdxl = 1. / dxl;
    hrdxl = rdxl * .5;
    a6h = ak6 * .5;
    a9t = ak9 / 3.;
    ynp = rpi / yn * .5;
    ynd = yn * 2.;

L3:

    x = xi[1];
    y = xi[2];
    z__ = xi[3];
    tilt = xi[4];
/* Computing 2nd power */
    d__1 = tilt;
    tlt2 = d__1 * d__1;
    sps = sin(tilt);
/* Computing 2nd power */
    d__1 = sps;
    cps = sqrt(1. - d__1 * d__1);

    x2 = x * x;
    y2 = y * y;
    z2 = z__ * z__;
    tps = sps / cps;
    htp = tps * .5;
    gsp = g * sps;
    xsm = x * cps - z__ * sps;
    zsm = x * sps + z__ * cps;

/*   CALCULATE THE FUNCTION ZS DEFINING THE SHAPE OF THE TAIL CURRENT SHEET */
/*    AND ITS SPATIAL DERIVATIVES: */

    xrc = xsm + rc;
/* Computing 2nd power */
    d__1 = xrc;
    xrc16 = d__1 * d__1 + 16.;
    sxrc = sqrt(xrc16);
    y4 = y2 * y2;
    y410 = y4 + 1e4;
    sy4 = sps / y410;
    gsy4 = g * sy4;
    zs1 = htp * (xrc - sxrc);
    dzsx = -zs1 / sxrc;
    zs = zs1 - gsy4 * y4;
    d2zsgy = -sy4 / y410 * 4e4 * y2 * y;
    dzsy = g * d2zsgy;

/*   CALCULATE THE COMPONENTS OF THE RING CURRENT CONTRIBUTION: */

/* Computing 2nd power */
    d__1 = xsm;
    xsm2 = d__1 * d__1;
    dsqt = sqrt(xsm2 + a02);
    fa0 = (xsm / dsqt + 1.) * .5;
    ddr = d0 + dd * fa0;
/* Computing 3rd power */
    d__1 = dsqt;
    dfa0 = ha02 / (d__1 * (d__1 * d__1));
    zr = zsm - zs;
/* Computing 2nd power */
    d__1 = zr;
/* Computing 2nd power */
    d__2 = ddr;
    tr = sqrt(d__1 * d__1 + d__2 * d__2);
    rtr = 1. / tr;
    ro2 = xsm2 + y2;
    adrt = adr + tr;
/* Computing 2nd power */
    d__1 = adrt;
    adrt2 = d__1 * d__1;
    fk = 1. / (adrt2 + ro2);
    dsfc = sqrt(fk);
/* Computing 2nd power */
    d__1 = fk;
    fc = d__1 * d__1 * dsfc;
    facxy = adrt * 3. * fc * rtr;
    xzr = xsm * zr;
    yzr = y * zr;
    dbxdp = facxy * xzr;
    der[17] = facxy * yzr;
    xzyz = xsm * dzsx + y * dzsy;
    faq = zr * xzyz - ddr * dd * dfa0 * xsm;
    dbzdp = fc * (adrt2 * 2. - ro2) + facxy * faq;
    der[16] = dbxdp * cps + dbzdp * sps;
    der[18] = dbzdp * cps - dbxdp * sps;

/*  CALCULATE THE TAIL CURRENT SHEET CONTRIBUTION: */

    dely2 = del * y2;
    d__ = dt + dely2;
    if (abs(gam) < 1e-6) {
	goto L8;
    }
    xxd = xsm - xd;
/* Computing 2nd power */
    d__1 = xxd;
    rqd = 1. / (d__1 * d__1 + xld2);
    rqds = sqrt(rqd);
    h__ = (xxd * rqds + 1.) * .5;
    hs = -hxld2m * rqd * rqds;
    gamh = gam * h__;
    d__ += gamh;
    xghs = xsm * gam * hs;
    adsl = -d__ * xghs;
L8:
/* Computing 2nd power */
    d__1 = d__;
    d2 = d__1 * d__1;
/* Computing 2nd power */
    d__1 = zr;
    t = sqrt(d__1 * d__1 + d2);
    xsmx = xsm - sx;
/* Computing 2nd power */
    d__1 = xsmx;
    rdsq2 = 1. / (d__1 * d__1 + xlw2);
    rdsq = sqrt(rdsq2);
    v = (1. - xsmx * rdsq) * .5;
    dvx = hxlw2m * rdsq * rdsq2;
    om = sqrt(sqrt(xsm2 + 16.) - xsm);
    oms = -om / (om * om + xsm) * .5;
    rdy = 1. / (p + q * om);
    omsv = oms * v;
/* Computing 2nd power */
    d__1 = rdy;
    rdy2 = d__1 * d__1;
    fy = 1. / (y2 * rdy2 + 1.);
    w = v * fy;
    yfy1 = fy * 2. * y2 * rdy2;
    fypr = yfy1 * rdy;
    fydy = fypr * fy;
    dwx = dvx * fy + fydy * q * omsv;
    ydwy = -v * yfy1 * fy;
    ddy = dbldel * y;
    att = at + t;
/* Computing 2nd power */
    d__1 = att;
    s1 = sqrt(d__1 * d__1 + ro2);
    f5 = 1. / s1;
    f7 = 1. / (s1 + att);
    f1 = f5 * f7;
/* Computing 3rd power */
    d__1 = f5;
    f3 = d__1 * (d__1 * d__1);
    f9 = att * f3;
    fs = zr * xzyz - d__ * y * ddy + adsl;
    xdwx = xsm * dwx + ydwy;
    rtt = 1. / t;
    wt = w * rtt;
    brrz1 = wt * f1;
    brrz2 = wt * f3;
    dbxc1 = brrz1 * xzr;
    dbxc2 = brrz2 * xzr;
    der[5] = brrz1 * yzr;
    der[8] = brrz2 * yzr;
    der[50] = der[5] * tlt2;
    der[53] = der[8] * tlt2;
    wtfs = wt * fs;
    dbzc1 = w * f5 + xdwx * f7 + wtfs * f1;
    dbzc2 = w * f9 + xdwx * f1 + wtfs * f3;
    der[4] = dbxc1 * cps + dbzc1 * sps;
    der[7] = dbxc2 * cps + dbzc2 * sps;
    der[6] = dbzc1 * cps - dbxc1 * sps;
    der[9] = dbzc2 * cps - dbxc2 * sps;
    der[49] = der[4] * tlt2;
    der[52] = der[7] * tlt2;
    der[51] = der[6] * tlt2;
    der[54] = der[9] * tlt2;

/*  CALCULATE CONTRIBUTION FROM THE CLOSURE CURRENTS */

    zpl = z__ + rt;
    zmn = z__ - rt;
    rogsm2 = x2 + y2;
/* Computing 2nd power */
    d__1 = zpl;
    spl = sqrt(d__1 * d__1 + rogsm2);
/* Computing 2nd power */
    d__1 = zmn;
    smn = sqrt(d__1 * d__1 + rogsm2);
    xsxc = x - sxc;
/* Computing 2nd power */
    d__1 = xsxc;
    rqc2 = 1. / (d__1 * d__1 + xlwc2);
    rqc = sqrt(rqc2);
    fyc = 1. / (y2 * rdyc2 + 1.);
    wc = (1. - xsxc * rqc) * .5 * fyc;
    dwcx = hlwc2m * rqc2 * rqc * fyc;
    dwcy = drdyc2 * wc * fyc * y;
    szrp = 1. / (spl + zpl);
    szrm = 1. / (smn - zmn);
    xywc = x * dwcx + y * dwcy;
    wcsp = wc / spl;
    wcsm = wc / smn;
    fxyp = wcsp * szrp;
    fxym = wcsm * szrm;
    fxpl = x * fxyp;
    fxmn = -x * fxym;
    fypl = y * fxyp;
    fymn = -y * fxym;
    fzpl = wcsp + xywc * szrp;
    fzmn = wcsm + xywc * szrm;
    der[10] = fxpl + fxmn;
    der[13] = (fxpl - fxmn) * sps;
    der[11] = fypl + fymn;
    der[14] = (fypl - fymn) * sps;
    der[12] = fzpl + fzmn;
    der[15] = (fzpl - fzmn) * sps;

/*   NOW CALCULATE CONTRIBUTION FROM CHAPMAN-FERRARO SOURCES + ALL OTHER */

    ex = exp(x / dx);
    ec = ex * cps;
    es = ex * sps;
    ecz = ec * z__;
    esz = es * z__;
    eszy2 = esz * y2;
    eszz2 = esz * z2;
    ecz2 = ecz * z__;
    esy = es * y;

    der[19] = ecz;
    der[22] = es;
    der[25] = esy * y;
    der[28] = esz * z__;
    der[32] = ecz * y;
    der[35] = esy;
    der[38] = esy * y2;
    der[41] = esy * z2;
    der[45] = ec;
    der[48] = ec * y2;
    der[21] = ecz2 * w1;
    der[33] = ecz2 * w5;
    der[24] = esz * w2;
    der[36] = -esz;
    der[27] = eszy2 * w2;
    der[39] = eszy2 * w6;
    der[30] = eszz2 * w3;
    der[42] = eszz2 * w4;

/*  FINALLY, CALCULATE NET EXTERNAL MAGNETIC FIELD COMPONENTS, */
/*    BUT FIRST OF ALL THOSE FOR C.-F. FIELD: */

    sx1 = ak6 * der[19] + ak7 * der[22] + ak8 * der[25] + ak9 * der[28];
    sy1 = ak10 * der[32] + ak11 * der[35] + ak12 * der[38] + ak13 * der[41];
    sz1 = ak14 * der[45] + ak15 * der[48] + ak610 * ecz2 + ak711 * esz + 
	    ak812 * eszy2 + ak913 * eszz2;
    bxcl = ak3 * der[10] + ak4 * der[13];
    bycl = ak3 * der[11] + ak4 * der[14];
    bzcl = ak3 * der[12] + ak4 * der[15];
    bxt = ak1 * der[4] + ak2 * der[7] + bxcl + ak16 * der[49] + ak17 * der[52]
	    ;
    byt = ak1 * der[5] + ak2 * der[8] + bycl + ak16 * der[50] + ak17 * der[53]
	    ;
    bzt = ak1 * der[6] + ak2 * der[9] + bzcl + ak16 * der[51] + ak17 * der[54]
	    ;
    f[1] = bxt + ak5 * der[16] + sx1 + sxa;
    f[2] = byt + ak5 * der[17] + sy1 + sya;
    f[3] = bzt + ak5 * der[18] + sz1 + sza;

    return 0;
} /* t89_boberg___ */

#ifdef __cplusplus
	}
#endif

