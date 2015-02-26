#ifdef GNUCGE
#else
#define GNUCGE(x, y, z)    \
  ((__GNUC__)            >  (x) || \
  ((__GNUC__)            == (x) && \
  ((__GNUC_MINOR__)      >  (y) || \
  ((__GNUC_MINOR__)      == (y) && \
  ((__GNUC_PATCHLEVEL__) >= (z))))))
#endif

#ifdef GNUCEQ
#else
#define GNUCEQ(x, y, z)    \
  ((__GNUC__)            == (x) && \
  ((__GNUC_MINOR__)      == (y) && \
  ((__GNUC_PATCHLEVEL__) == (z))))
#endif

#ifndef GNUCLT
#define GNUCLT(x, y, z) (!GNUCGE(x, y, z))
#endif

#ifndef GNUCNE
#define GNUCNE(x, y, z) (!GNUCEQ(x, y, z))
#endif

#ifndef GNUCLE
#define GNUCLE(x, y, z) (GNUCLT(x, y, z) || (GNUCEQ(x, y, z)))
#endif

#ifndef GNUCGT
#define GNUCGT(x, y, z) (!GNUCLE(x, y, z))
#endif

/*
 * The authors of this file have waived all copyright and
 * related or neighboring rights to the extent permitted by
 * law as described by the CC0 1.0 Universal Public Domain
 * Dedication. You should have received a copy of the full
 * dedication along with this file, typically as a file
 * named <CC0-1.0.txt>. If not, it may be available at
 * <https://creativecommons.org/publicdomain/zero/1.0/>.
 */
