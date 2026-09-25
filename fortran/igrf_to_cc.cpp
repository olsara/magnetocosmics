/* igrf_to_cc.f -- translated by f2c (version 20240504).
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

/* Common Block Declarations */

extern struct {
    real g[105], h__[105], rec[105];
    integer nm;
} igrfcc_;

#define igrfcc_1 igrfcc_


/* Subroutine */ int igrf_to_cc___(real *r__, real *t, real *f, real *br, 
	real *bt, real *bf)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static real a[14], b[14], c__, d__, e;
    static integer k, m, n;
    static real p, q, s, u, w, x, y, z__, d2, p2, cf, bi, an, hh, dp, sf;
    static integer mm, mn;
    static real pm, pp, qq, xk, bbf, bbr, bbt;


/*     CALCULATES COMPONENTS OF THE MAIN (INTERNAL) GEOMAGNETIC FIELD IN SPHERICAL */
/*     GEOGRAPHICAL COORDINATE SYSTEM, USING IAGA INTERNATIONAL GEOMAGNETIC REFERENCE */
/*     MODEL COEFFICIENTS (e.g., http://www.ngdc.noaa.gov/IAGA/wg8/igrf2000.html) */

/*     UPDATING THE COEFFICIENTS TO A GIVEN EPOCH IS MADE AUTOMATICALLY UPON THE FIRST */
/*     CALL AND AFTER EVERY CHANGE OF THE PARAMETER IY. */

/* -----INPUT PARAMETERS: */

/*     IY  -  YEAR NUMBER (FOUR-DIGIT; 1965 &LE IY &LE 2005) */
/*     NM  -  HIGHEST ORDER OF SPHERICAL HARMONICS IN THE SCALAR POTENTIAL (NM &LE 10) */
/*     R,T,F -  SPHERICAL COORDINATES (RADIUS R IN UNITS RE=6371.2 KM, GEOGRAPHIC */
/*                COLATITUDE  T  AND LONGITUDE  F  IN RADIANS) */

/* -----OUTPUT PARAMETERS: */

/*     BR,BT,BF - SPHERICAL COMPONENTS OF THE MAIN GEOMAGNETIC FIELD IN NANOTESLA */

/*     LAST MODIFICATION:  JANUARY 5, 2001. */
/*     THE CODE WAS MODIFIED TO ACCEPT DATES THROUGH 2005. */
/*     IT HAS ALSO BEEN SLIGHTLY SIMPLIFIED BY TAKING OUT SOME REDUNDANT STATEMENTS, */
/*     AND A "SAVE" STATEMENT WAS ADDED, TO AVOID POTENTIAL PROBLEMS WITH SOME */
/*     FORTRAN COMPILERS. */

/*     WRITTEN BY: N. A. TSYGANENKO */
/*    SAVE MA,IYR,IPR */


/* L130: */
    pp = (float)1. / *r__;
    p = pp;
    k = igrfcc_1.nm + 1;
    i__1 = k;
    for (n = 1; n <= i__1; ++n) {
	p *= pp;
	a[n - 1] = p;
/* L150: */
	b[n - 1] = p * n;
    }
    p = (float)1.;
    d__ = (float)0.;
    bbr = (float)0.;
    bbt = (float)0.;
    bbf = (float)0.;
    u = *t;
    cf = cos(*f);
    sf = sin(*f);
    c__ = cos(u);
    s = sin(u);
    i__1 = k;
    for (m = 1; m <= i__1; ++m) {
	if (m == 1) {
	    goto L160;
	}
	mm = m - 1;
	w = x;
	x = w * cf + y * sf;
	y = y * cf - w * sf;
	goto L170;
L160:
	x = (float)0.;
	y = (float)1.;
L170:
	q = p;
	z__ = d__;
	bi = (float)0.;
	p2 = (float)0.;
	d2 = (float)0.;
	i__2 = k;
	for (n = m; n <= i__2; ++n) {
	    an = a[n - 1];
	    mn = n * (n - 1) / 2 + m;
	    e = igrfcc_1.g[mn - 1];
	    hh = igrfcc_1.h__[mn - 1];
	    w = e * y + hh * x;
	    bbr += b[n - 1] * w * q;
	    bbt -= an * w * z__;
	    if (m == 1) {
		goto L180;
	    }
	    qq = q;
	    if (s < (float)1e-5) {
		qq = z__;
	    }
	    bi += an * (e * x - hh * y) * qq;
L180:
	    xk = igrfcc_1.rec[mn - 1];
	    dp = c__ * z__ - s * q - xk * d2;
	    pm = c__ * q - xk * p2;
	    d2 = z__;
	    p2 = q;
	    z__ = dp;
/* L190: */
	    q = pm;
	}
	d__ = s * d__ + c__ * p;
	p = s * p;
	if (m == 1) {
	    goto L200;
	}
	bi *= mm;
	bbf += bi;
L200:
	;
    }

    *br = bbr;
    *bt = bbt;
    if (s < (float)1e-5) {
	goto L210;
    }
    *bf = bbf / s;
    return 0;
L210:
    if (c__ < (float)0.) {
	bbf = -bbf;
    }
    *bf = bbf;
    return 0;

/* L999: */
} /* igrf_to_cc___ */

#ifdef __cplusplus
	}
#endif

