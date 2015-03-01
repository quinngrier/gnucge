/*
 * This header file defines six macros for testing the GNU C version.
 *
 * GNU C is the normal C language along with the extensions provided by
 * the GNU Compiler Collection (GCC). These extensions can be useful in
 * otherwise portable code. For example, we can specify that a function
 * cannot return a null pointer:
 *
 *   __attribute__((__returns_nonnull__))
 *   static int *foo(void) {
 *     static int bar;
 *     return &bar;
 *   }
 *
 * This is only a simple example. GCC has a wide variety of extensions
 * that we will not cover here. See the GCC manual for more information.
 * In particular, see the "Extensions to the C Language Family" section.
 *
 * The above example will of course not work with compilers that do not
 * support GNU C. To maintain portability, we must make the special code
 * optional. One way we can do this is by testing a few macros that are
 * only defined by compilers that support GNU C.
 *
 * The macros are __GNUC__, __GNUC_MINOR__, and __GNUC_PATCHLEVEL__.
 * Compilers that support GNU C define these macros as the major, minor,
 * and patch numbers of the latest version of GCC whose extensions are
 * supported. These macros only imply that the compiler supports GNU C,
 * not that the compiler is GCC itself. For example, version 3.4.0 of
 * the Clang compiler defines these macros as 4, 2, and 1 to indicate
 * that it supports the extensions of version 4.2.1 of GCC.
 *
 * One way to test these macros is simply to test for the existence of
 * __GNUC__. Continuing the same example:
 *
 *   #ifdef __GNUC__
 *   __attribute__((__returns_nonnull__))
 *   #endif
 *   static int *foo(void) {
 *     static int bar;
 *     return &bar;
 *   }
 *
 * However, this does not properly use the information provided by the
 * macros. The existence of __GNUC__ only implies that the compiler
 * supports some version of GNU C. If we look through old GCC manuals,
 * we discover that returns_nonnull is introduced in version 4.9.2. If
 * the compiler only advertises support for an older version of GNU C,
 * the example still might not work. This is indeed the case with the
 * aforementioned version of Clang.
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
