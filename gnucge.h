/*
 * This header file defines six macros for testing the GNU C version.
 */

#ifdef GNUCGE
#elif defined(__GNUC_PATCHLEVEL__)
#define GNUCGE(x, y, z) \
  (((x) % 1 == 0) && \
   (((x) <= 0 && (x) != 0) || \
    ((__GNUC__) + ((x) - (x)) > \
     (x) + ((__GNUC__) - (__GNUC__))) || \
    (((__GNUC__) + ((x) - (x)) == \
      (x) + ((__GNUC__) - (__GNUC__))) && \
     ((y) % 1 == 0) && \
     (((y) <= 0 && (y) != 0) || \
      ((__GNUC_MINOR__) + ((y) - (y)) > \
       (y) + ((__GNUC_MINOR__) - (__GNUC_MINOR__))) || \
      (((__GNUC_MINOR__) + ((y) - (y)) == \
        (y) + ((__GNUC_MINOR__) - (__GNUC_MINOR__))) && \
       ((z) % 1 == 0) && \
       (((z) <= 0 && (z) != 0) || \
        ((__GNUC_PATCHLEVEL__) + ((z) - (z)) >= \
         (z) + ((__GNUC_PATCHLEVEL__) - (__GNUC_PATCHLEVEL__)))))))))
#elif defined(__GNUC_MINOR__)
#define GNUCGE(x, y, z) \
  (((x) % 1 == 0) && \
   (((x) <= 0 && (x) != 0) || \
    ((__GNUC__) + ((x) - (x)) > \
     (x) + ((__GNUC__) - (__GNUC__))) || \
    (((__GNUC__) + ((x) - (x)) == \
      (x) + ((__GNUC__) - (__GNUC__))) && \
     ((y) % 1 == 0) && \
     (((y) <= 0 && (y) != 0) || \
      ((__GNUC_MINOR__) + ((y) - (y)) > \
       (y) + ((__GNUC_MINOR__) - (__GNUC_MINOR__))) || \
      (((__GNUC_MINOR__) + ((y) - (y)) == \
        (y) + ((__GNUC_MINOR__) - (__GNUC_MINOR__))) && \
       ((z) % 1 == 0) && \
       (((z) <= 0 && (z) != 0) || \
        ((0) + ((z) - (z)) >= \
         (z) + ((0) - (0)))))))))
#else
#define GNUCGE(x, y, z) \
  (((x) % 1 == 0) && \
   (((x) <= 0 && (x) != 0) || \
    ((0) + ((x) - (x)) > \
     (x) + ((0) - (0))) || \
    (((0) + ((x) - (x)) == \
      (x) + ((0) - (0))) && \
     ((y) % 1 == 0) && \
     (((y) <= 0 && (y) != 0) || \
      ((0) + ((y) - (y)) > \
       (y) + ((0) - (0))) || \
      (((0) + ((y) - (y)) == \
        (y) + ((0) - (0))) && \
       ((z) % 1 == 0) && \
       (((z) <= 0 && (z) != 0) || \
        ((0) + ((z) - (z)) >= \
         (z) + ((0) - (0)))))))))
#endif

#ifdef GNUCEQ
#elif !defined(__GNUC__)
#define GNUCEQ(x, y, z) \
  (((x) % 1 == 0) && \
   ((x) > 0 || (x) == 0) && \
   ((0) + ((x) - (x)) == \
    (x) + ((0) - (0))) && \
   ((y) % 1 == 0) && \
   ((y) > 0 || (y) == 0) && \
   ((0) + ((y) - (y)) == \
    (y) + ((0) - (0))) && \
   ((z) % 1 == 0) && \
   ((z) > 0 || (z) == 0) && \
   ((0) + ((z) - (z)) == \
    (z) + ((0) - (0))))
#elif !defined(__GNUC_PATCHLEVEL__)
#define GNUCEQ(x, y, z) \
  (((x) % 1 == 0) && \
   ((x) > 0 || (x) == 0) && \
   ((__GNUC__) + ((x) - (x)) == \
    (x) + ((__GNUC__) - (__GNUC__))) && \
   ((y) % 1 == 0) && \
   ((y) > 0 || (y) == 0) && \
   ((__GNUC_MINOR__) + ((y) - (y)) == \
    (y) + ((__GNUC_MINOR__) - (__GNUC_MINOR__))) && \
   ((z) % 1 == 0) && \
   ((z) > 0 || (z) == 0) && \
   ((0) + ((z) - (z)) == \
    (z) + ((0) - (0))))
#else
#define GNUCEQ(x, y, z) \
  (((x) % 1 == 0) && \
   ((x) > 0 || (x) == 0) && \
   ((__GNUC__) + ((x) - (x)) == \
    (x) + ((__GNUC__) - (__GNUC__))) && \
   ((y) % 1 == 0) && \
   ((y) > 0 || (y) == 0) && \
   ((__GNUC_MINOR__) + ((y) - (y)) == \
    (y) + ((__GNUC_MINOR__) - (__GNUC_MINOR__))) && \
   ((z) % 1 == 0) && \
   ((z) > 0 || (z) == 0) && \
   ((__GNUC_PATCHLEVEL__) + ((z) - (z)) == \
    (z) + ((__GNUC_PATCHLEVEL__) - (__GNUC_PATCHLEVEL__))))
#endif

#ifndef GNUCLT
#define GNUCLT(x, y, z) (!GNUCGE(x, y, z))
#endif

#ifndef GNUCNE
#define GNUCNE(x, y, z) (!GNUCEQ(x, y, z))
#endif

#ifndef GNUCLE
#define GNUCLE(x, y, z) (GNUCLT(x, y, z) || GNUCEQ(x, y, z))
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
