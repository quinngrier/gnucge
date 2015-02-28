/*
 * This header file defines six macros for testing the GNU C version.
 *
 * GNU C is the normal C language along with the extensions provided by
 * the GNU Compiler Collection (GCC). These extensions can be useful in
 * otherwise portable code. As a simple example, we can specify that a
 * function cannot return:
 *
 *   __attribute__((__noreturn__))
 *   static void panic(void) {
 *     abort();
 *   }
 *
 * See the GCC manual for more information on GNU C. In particular, see
 * the "Extensions to the C Language Family" section.
 *
 * The above example will of course not work with a compiler that does
 * not support GNU C. To maintain portability, we must somehow make the
 * special code optional. Fortunately, the preprocessor of any compiler
 * that supports GNU C will predefine a few macros that we can test.
 *
 * The macros are __GNUC__, __GNUC_MINOR__, and __GNUC_PATCHLEVEL__.
 * These are nonnegative integer constant expressions that are suitable
 * for preprocessor use and whose values are the major, minor, and patch
 * numbers of the latest version of GCC whose extensions are supported.
 * Note that the compiler is not necessarily GCC: version 3.5.0 of the
 * Clang compiler defines these macros to 4, 2, and 1 to indicate that
 * it supports the extensions of GCC 4.2.1.
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

#ifdef GNUCGT
#elif defined(__GNUC_PATCHLEVEL__)
#define GNUCGT(x, y, z) \
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
        ((__GNUC_PATCHLEVEL__) + ((z) - (z)) > \
         (z) + ((__GNUC_PATCHLEVEL__) - (__GNUC_PATCHLEVEL__)))))))))
#elif defined(__GNUC_MINOR__)
#define GNUCGT(x, y, z) \
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
        ((0) + ((z) - (z)) > \
         (z) + ((0) - (0)))))))))
#else
#define GNUCGT(x, y, z) \
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
        ((0) + ((z) - (z)) > \
         (z) + ((0) - (0)))))))))
#endif

#ifndef GNUCLE
#define GNUCLE(x, y, z) (!GNUCGT(x, y, z))
#endif

#ifndef GNUCLT
#define GNUCLT(x, y, z) (!GNUCGE(x, y, z))
#endif

#ifndef GNUCEQ
#define GNUCEQ(x, y, z) (GNUCGE(x, y, z) && GNUCLE(x, y, z))
#endif

#ifndef GNUCNE
#define GNUCNE(x, y, z) (!GNUCEQ(x, y, z))
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
