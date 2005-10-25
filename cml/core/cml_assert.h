/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 *
 * Macros and template metaprogramming to implement compile- and run-time
 * assertions.
 */

#ifndef cml_assert_h
#define cml_assert_h

#include <stdexcept>

/** Type of a true statement. */
struct true_type {};

/** Type of a false statement. */
struct false_type {};

/** Default, undefined compile-time assertion struct. */
template<bool T> struct STATIC_ASSERTION_FAILURE;

/** Struct instantiated when a false assertion is made at compile-time. */
template<> struct STATIC_ASSERTION_FAILURE<false> {
    typedef true_type result;
    enum { value = false };
};

#define CML_JOIN(X,Y) CML_DO_JOIN(X,Y)
#define CML_DO_JOIN(X,Y) CML_DO_JOIN2(X,Y)
#define CML_DO_JOIN2(X,Y) X##Y

/** Create a compile-time assertion.
 *
 * Compile-time assertions must be expressions that can be evaluated at
 * comile time.  This means that the expression must only rely on
 * constants, enums, and/or template parameters, not variables having
 * run-time storage requirements.
 */
#define CML_STATIC_REQUIRE(_E_) \
    typedef typename STATIC_ASSERTION_FAILURE<!(_E_)>::result \
        CML_JOIN(__cml_assert_test_typedef_, __LINE__)

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
