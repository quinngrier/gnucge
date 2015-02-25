#ifndef GNUCGE
#define GNUCGE(major, minor, patch)    \
  ((__GNUC__)            >  (major) || \
  ((__GNUC__)            == (major) && \
  ((__GNUC_MINOR__)      >  (minor) || \
  ((__GNUC_MINOR__)      == (minor) && \
  ((__GNUC_PATCHLEVEL__) >= (patch))))))
#endif

#ifndef GNUCLT
#define GNUCLT(major, minor, patch) \
  (!GNUCGE(major, minor, patch))
#endif

#ifndef GNUCEQ
#define GNUCEQ(major, minor, patch)    \
  ((__GNUC__)            == (major) && \
  ((__GNUC_MINOR__)      == (minor) && \
  ((__GNUC_PATCHLEVEL__) == (patch))))
#endif

#ifndef GNUCNE
#define GNUCNE(major, minor, patch) \
  (!GNUCEQ(major, minor, patch))
#endif

#ifndef GNUCLE
#define GNUCLE(major, minor, patch) \
  (GNUCLT(major, minor, patch) ||   \
  (GNUCEQ(major, minor, patch)))
#endif

#ifndef GNUCGT
#define GNUCGT(major, minor, patch) \
  (!GNUCLE(major, minor, patch))
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
