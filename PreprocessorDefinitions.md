# Introduction #

The following is the output of `uname -a` and `cpp -dM < /dev/null | sort`.

## Cygwin (XP, x86) ##
<pre>jeffrey@descartes ~<br>
$ uname -a<br>
CYGWIN_NT-5.1 descartes 1.7.7(0.230/5/3) 2010-08-31 09:58 i686 Cygwin</pre>
<pre>jeffrey@descartes ~<br>
$ cpp -dM < /dev/null | sort<br>
#define _X86_ 1<br>
#define __CHAR_BIT__ 8<br>
#define __CYGWIN32__ 1<br>
#define __CYGWIN__ 1<br>
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324<br>
#define __DBL_DIG__ 15<br>
#define __DBL_EPSILON__ 2.2204460492503131e-16<br>
#define __DBL_HAS_INFINITY__ 1<br>
#define __DBL_HAS_QUIET_NAN__ 1<br>
#define __DBL_MANT_DIG__ 53<br>
#define __DBL_MAX_10_EXP__ 308<br>
#define __DBL_MAX_EXP__ 1024<br>
#define __DBL_MAX__ 1.7976931348623157e+308<br>
#define __DBL_MIN_10_EXP__ (-307)<br>
#define __DBL_MIN_EXP__ (-1021)<br>
#define __DBL_MIN__ 2.2250738585072014e-308<br>
#define __DECIMAL_DIG__ 21<br>
#define __FINITE_MATH_ONLY__ 0<br>
#define __FLT_DENORM_MIN__ 1.40129846e-45F<br>
#define __FLT_DIG__ 6<br>
#define __FLT_EPSILON__ 1.19209290e-7F<br>
#define __FLT_EVAL_METHOD__ 2<br>
#define __FLT_HAS_INFINITY__ 1<br>
#define __FLT_HAS_QUIET_NAN__ 1<br>
#define __FLT_MANT_DIG__ 24<br>
#define __FLT_MAX_10_EXP__ 38<br>
#define __FLT_MAX_EXP__ 128<br>
#define __FLT_MAX__ 3.40282347e+38F<br>
#define __FLT_MIN_10_EXP__ (-37)<br>
#define __FLT_MIN_EXP__ (-125)<br>
#define __FLT_MIN__ 1.17549435e-38F<br>
#define __FLT_RADIX__ 2<br>
#define __GNUC_MINOR__ 4<br>
#define __GNUC_PATCHLEVEL__ 4<br>
#define __GNUC__ 3<br>
#define __GXX_ABI_VERSION 1002<br>
#define __INT_MAX__ 2147483647<br>
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L<br>
#define __LDBL_DIG__ 18<br>
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L<br>
#define __LDBL_HAS_INFINITY__ 1<br>
#define __LDBL_HAS_QUIET_NAN__ 1<br>
#define __LDBL_MANT_DIG__ 64<br>
#define __LDBL_MAX_10_EXP__ 4932<br>
#define __LDBL_MAX_EXP__ 16384<br>
#define __LDBL_MAX__ 1.18973149535723176502e+4932L<br>
#define __LDBL_MIN_10_EXP__ (-4931)<br>
#define __LDBL_MIN_EXP__ (-16381)<br>
#define __LDBL_MIN__ 3.36210314311209350626e-4932L<br>
#define __LONG_LONG_MAX__ 9223372036854775807LL<br>
#define __LONG_MAX__ 2147483647L<br>
#define __NO_INLINE__ 1<br>
#define __PTRDIFF_TYPE__ int<br>
#define __REGISTER_PREFIX__<br>
#define __SCHAR_MAX__ 127<br>
#define __SHRT_MAX__ 32767<br>
#define __SIZE_TYPE__ unsigned int<br>
#define __STDC_HOSTED__ 1<br>
#define __USER_LABEL_PREFIX__ _<br>
#define __USING_SJLJ_EXCEPTIONS__ 1<br>
#define __VERSION__ "3.4.4 (cygming special, gdc 0.12, using dmd 0.125)"<br>
#define __WCHAR_MAX__ 65535U<br>
#define __WCHAR_TYPE__ short unsigned int<br>
#define __WINT_TYPE__ unsigned int<br>
#define __cdecl __attribute__((__cdecl__))<br>
#define __declspec(x) __attribute__((x))<br>
#define __fastcall __attribute__((__fastcall__))<br>
#define __i386 1<br>
#define __i386__ 1<br>
#define __stdcall __attribute__((__stdcall__))<br>
#define __tune_i686__ 1<br>
#define __tune_pentiumpro__ 1<br>
#define __unix 1<br>
#define __unix__ 1<br>
#define _cdecl __attribute__((__cdecl__))<br>
#define _fastcall __attribute__((__fastcall__))<br>
#define _stdcall __attribute__((__stdcall__))<br>
#define i386 1<br>
#define unix 1</pre>

## MinGW (XP, x86) ##
<pre>jeffrey@descartes ~<br>
$ uname -a<br>
MINGW32_NT-5.1 DESCARTES 1.0.17(0.48/3/2) 2011-04-24 23:39 i686 Msys</pre>
<pre>jeffrey@descartes ~<br>
$ cpp -dM < /dev/null | sort<br>
#define WIN32 1<br>
#define WINNT 1<br>
#define _INTEGRAL_MAX_BITS 64<br>
#define _WIN32 1<br>
#define _X86_ 1<br>
#define __BIGGEST_ALIGNMENT__ 16<br>
#define __CHAR16_TYPE__ short unsigned int<br>
#define __CHAR32_TYPE__ unsigned int<br>
#define __CHAR_BIT__ 8<br>
#define __DBL_DENORM_MIN__ ((double)4.94065645841246544177e-324L)<br>
#define __DBL_DIG__ 15<br>
#define __DBL_EPSILON__ ((double)2.22044604925031308085e-16L)<br>
#define __DBL_HAS_DENORM__ 1<br>
#define __DBL_HAS_INFINITY__ 1<br>
#define __DBL_HAS_QUIET_NAN__ 1<br>
#define __DBL_MANT_DIG__ 53<br>
#define __DBL_MAX_10_EXP__ 308<br>
#define __DBL_MAX_EXP__ 1024<br>
#define __DBL_MAX__ ((double)1.79769313486231570815e+308L)<br>
#define __DBL_MIN_10_EXP__ (-307)<br>
#define __DBL_MIN_EXP__ (-1021)<br>
#define __DBL_MIN__ ((double)2.22507385850720138309e-308L)<br>
#define __DEC128_EPSILON__ 1E-33DL<br>
#define __DEC128_MANT_DIG__ 34<br>
#define __DEC128_MAX_EXP__ 6145<br>
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL<br>
#define __DEC128_MIN_EXP__ (-6142)<br>
#define __DEC128_MIN__ 1E-6143DL<br>
#define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL<br>
#define __DEC32_EPSILON__ 1E-6DF<br>
#define __DEC32_MANT_DIG__ 7<br>
#define __DEC32_MAX_EXP__ 97<br>
#define __DEC32_MAX__ 9.999999E96DF<br>
#define __DEC32_MIN_EXP__ (-94)<br>
#define __DEC32_MIN__ 1E-95DF<br>
#define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF<br>
#define __DEC64_EPSILON__ 1E-15DD<br>
#define __DEC64_MANT_DIG__ 16<br>
#define __DEC64_MAX_EXP__ 385<br>
#define __DEC64_MAX__ 9.999999999999999E384DD<br>
#define __DEC64_MIN_EXP__ (-382)<br>
#define __DEC64_MIN__ 1E-383DD<br>
#define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD<br>
#define __DECIMAL_DIG__ 21<br>
#define __DEC_EVAL_METHOD__ 2<br>
#define __FINITE_MATH_ONLY__ 0<br>
#define __FLT_DENORM_MIN__ 1.40129846432481707092e-45F<br>
#define __FLT_DIG__ 6<br>
#define __FLT_EPSILON__ 1.19209289550781250000e-7F<br>
#define __FLT_EVAL_METHOD__ 2<br>
#define __FLT_HAS_DENORM__ 1<br>
#define __FLT_HAS_INFINITY__ 1<br>
#define __FLT_HAS_QUIET_NAN__ 1<br>
#define __FLT_MANT_DIG__ 24<br>
#define __FLT_MAX_10_EXP__ 38<br>
#define __FLT_MAX_EXP__ 128<br>
#define __FLT_MAX__ 3.40282346638528859812e+38F<br>
#define __FLT_MIN_10_EXP__ (-37)<br>
#define __FLT_MIN_EXP__ (-125)<br>
#define __FLT_MIN__ 1.17549435082228750797e-38F<br>
#define __FLT_RADIX__ 2<br>
#define __GNUC_GNU_INLINE__ 1<br>
#define __GNUC_MINOR__ 5<br>
#define __GNUC_PATCHLEVEL__ 2<br>
#define __GNUC__ 4<br>
#define __GXX_ABI_VERSION 1002<br>
#define __GXX_MERGED_TYPEINFO_NAMES 0<br>
#define __GXX_TYPEINFO_EQUALITY_INLINE 0<br>
#define __INT16_C(c) c<br>
#define __INT16_MAX__ 32767<br>
#define __INT16_TYPE__ short int<br>
#define __INT32_C(c) c<br>
#define __INT32_MAX__ 2147483647<br>
#define __INT32_TYPE__ int<br>
#define __INT64_C(c) c ## LL<br>
#define __INT64_MAX__ 9223372036854775807LL<br>
#define __INT64_TYPE__ long long int<br>
#define __INT8_C(c) c<br>
#define __INT8_MAX__ 127<br>
#define __INT8_TYPE__ signed char<br>
#define __INTMAX_C(c) c ## LL<br>
#define __INTMAX_MAX__ 9223372036854775807LL<br>
#define __INTMAX_TYPE__ long long int<br>
#define __INTPTR_MAX__ 2147483647<br>
#define __INTPTR_TYPE__ int<br>
#define __INT_FAST16_MAX__ 32767<br>
#define __INT_FAST16_TYPE__ short int<br>
#define __INT_FAST32_MAX__ 2147483647<br>
#define __INT_FAST32_TYPE__ int<br>
#define __INT_FAST64_MAX__ 9223372036854775807LL<br>
#define __INT_FAST64_TYPE__ long long int<br>
#define __INT_FAST8_MAX__ 127<br>
#define __INT_FAST8_TYPE__ signed char<br>
#define __INT_LEAST16_MAX__ 32767<br>
#define __INT_LEAST16_TYPE__ short int<br>
#define __INT_LEAST32_MAX__ 2147483647<br>
#define __INT_LEAST32_TYPE__ int<br>
#define __INT_LEAST64_MAX__ 9223372036854775807LL<br>
#define __INT_LEAST64_TYPE__ long long int<br>
#define __INT_LEAST8_MAX__ 127<br>
#define __INT_LEAST8_TYPE__ signed char<br>
#define __INT_MAX__ 2147483647<br>
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L<br>
#define __LDBL_DIG__ 18<br>
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L<br>
#define __LDBL_HAS_DENORM__ 1<br>
#define __LDBL_HAS_INFINITY__ 1<br>
#define __LDBL_HAS_QUIET_NAN__ 1<br>
#define __LDBL_MANT_DIG__ 64<br>
#define __LDBL_MAX_10_EXP__ 4932<br>
#define __LDBL_MAX_EXP__ 16384<br>
#define __LDBL_MAX__ 1.18973149535723176502e+4932L<br>
#define __LDBL_MIN_10_EXP__ (-4931)<br>
#define __LDBL_MIN_EXP__ (-16381)<br>
#define __LDBL_MIN__ 3.36210314311209350626e-4932L<br>
#define __LONG_LONG_MAX__ 9223372036854775807LL<br>
#define __LONG_MAX__ 2147483647L<br>
#define __MINGW32__ 1<br>
#define __MSVCRT__ 1<br>
#define __NO_INLINE__ 1<br>
#define __PRAGMA_REDEFINE_EXTNAME 1<br>
#define __PTRDIFF_MAX__ 2147483647<br>
#define __PTRDIFF_TYPE__ int<br>
#define __REGISTER_PREFIX__<br>
#define __SCHAR_MAX__ 127<br>
#define __SHRT_MAX__ 32767<br>
#define __SIG_ATOMIC_MAX__ 2147483647<br>
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)<br>
#define __SIG_ATOMIC_TYPE__ int<br>
#define __SIZEOF_DOUBLE__ 8<br>
#define __SIZEOF_FLOAT__ 4<br>
#define __SIZEOF_INT__ 4<br>
#define __SIZEOF_LONG_DOUBLE__ 12<br>
#define __SIZEOF_LONG_LONG__ 8<br>
#define __SIZEOF_LONG__ 4<br>
#define __SIZEOF_POINTER__ 4<br>
#define __SIZEOF_PTRDIFF_T__ 4<br>
#define __SIZEOF_SHORT__ 2<br>
#define __SIZEOF_SIZE_T__ 4<br>
#define __SIZEOF_WCHAR_T__ 2<br>
#define __SIZEOF_WINT_T__ 2<br>
#define __SIZE_MAX__ 4294967295U<br>
#define __SIZE_TYPE__ unsigned int<br>
#define __STDC_HOSTED__ 1<br>
#define __STDC__ 1<br>
#define __UINT16_C(c) c<br>
#define __UINT16_MAX__ 65535<br>
#define __UINT16_TYPE__ short unsigned int<br>
#define __UINT32_C(c) c ## U<br>
#define __UINT32_MAX__ 4294967295U<br>
#define __UINT32_TYPE__ unsigned int<br>
#define __UINT64_C(c) c ## ULL<br>
#define __UINT64_MAX__ 18446744073709551615ULL<br>
#define __UINT64_TYPE__ long long unsigned int<br>
#define __UINT8_C(c) c<br>
#define __UINT8_MAX__ 255<br>
#define __UINT8_TYPE__ unsigned char<br>
#define __UINTMAX_C(c) c ## ULL<br>
#define __UINTMAX_MAX__ 18446744073709551615ULL<br>
#define __UINTMAX_TYPE__ long long unsigned int<br>
#define __UINTPTR_MAX__ 4294967295U<br>
#define __UINTPTR_TYPE__ unsigned int<br>
#define __UINT_FAST16_MAX__ 65535<br>
#define __UINT_FAST16_TYPE__ short unsigned int<br>
#define __UINT_FAST32_MAX__ 4294967295U<br>
#define __UINT_FAST32_TYPE__ unsigned int<br>
#define __UINT_FAST64_MAX__ 18446744073709551615ULL<br>
#define __UINT_FAST64_TYPE__ long long unsigned int<br>
#define __UINT_FAST8_MAX__ 255<br>
#define __UINT_FAST8_TYPE__ unsigned char<br>
#define __UINT_LEAST16_MAX__ 65535<br>
#define __UINT_LEAST16_TYPE__ short unsigned int<br>
#define __UINT_LEAST32_MAX__ 4294967295U<br>
#define __UINT_LEAST32_TYPE__ unsigned int<br>
#define __UINT_LEAST64_MAX__ 18446744073709551615ULL<br>
#define __UINT_LEAST64_TYPE__ long long unsigned int<br>
#define __UINT_LEAST8_MAX__ 255<br>
#define __UINT_LEAST8_TYPE__ unsigned char<br>
#define __USER_LABEL_PREFIX__ _<br>
#define __VERSION__ "4.5.2"<br>
#define __WCHAR_MAX__ 65535<br>
#define __WCHAR_MIN__ 0<br>
#define __WCHAR_TYPE__ short unsigned int<br>
#define __WIN32 1<br>
#define __WIN32__ 1<br>
#define __WINNT 1<br>
#define __WINNT__ 1<br>
#define __WINT_MAX__ 65535<br>
#define __WINT_MIN__ 0<br>
#define __WINT_TYPE__ short unsigned int<br>
#define __cdecl __attribute__((__cdecl__))<br>
#define __declspec(x) __attribute__((x))<br>
#define __fastcall __attribute__((__fastcall__))<br>
#define __i386 1<br>
#define __i386__ 1<br>
#define __stdcall __attribute__((__stdcall__))<br>
#define __tune_i386__ 1<br>
#define _cdecl __attribute__((__cdecl__))<br>
#define _fastcall __attribute__((__fastcall__))<br>
#define _stdcall __attribute__((__stdcall__))<br>
#define i386 1</pre>
## FreeBSD (x86) ##
<pre>[jeffrey@germain /usr/home/jeffrey/Desktop/owasp-esapi-c++]$ cpp -dM </dev/null  | sort<br>
#define _LONGLONG 1<br>
#define __CHAR_BIT__ 8<br>
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324<br>
#define __DBL_DIG__ 15<br>
#define __DBL_EPSILON__ 2.2204460492503131e-16<br>
#define __DBL_HAS_DENORM__ 1<br>
#define __DBL_HAS_INFINITY__ 1<br>
#define __DBL_HAS_QUIET_NAN__ 1<br>
#define __DBL_MANT_DIG__ 53<br>
#define __DBL_MAX_10_EXP__ 308<br>
#define __DBL_MAX_EXP__ 1024<br>
#define __DBL_MAX__ 1.7976931348623157e+308<br>
#define __DBL_MIN_10_EXP__ (-307)<br>
#define __DBL_MIN_EXP__ (-1021)<br>
#define __DBL_MIN__ 2.2250738585072014e-308<br>
#define __DEC128_DEN__ 0.000000000000000000000000000000001E-6143DL<br>
#define __DEC128_EPSILON__ 1E-33DL<br>
#define __DEC128_MANT_DIG__ 34<br>
#define __DEC128_MAX_EXP__ 6144<br>
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL<br>
#define __DEC128_MIN_EXP__ (-6143)<br>
#define __DEC128_MIN__ 1E-6143DL<br>
#define __DEC32_DEN__ 0.000001E-95DF<br>
#define __DEC32_EPSILON__ 1E-6DF<br>
#define __DEC32_MANT_DIG__ 7<br>
#define __DEC32_MAX_EXP__ 96<br>
#define __DEC32_MAX__ 9.999999E96DF<br>
#define __DEC32_MIN_EXP__ (-95)<br>
#define __DEC32_MIN__ 1E-95DF<br>
#define __DEC64_DEN__ 0.000000000000001E-383DD<br>
#define __DEC64_EPSILON__ 1E-15DD<br>
#define __DEC64_MANT_DIG__ 16<br>
#define __DEC64_MAX_EXP__ 384<br>
#define __DEC64_MAX__ 9.999999999999999E384DD<br>
#define __DEC64_MIN_EXP__ (-383)<br>
#define __DEC64_MIN__ 1E-383DD<br>
#define __DECIMAL_DIG__ 17<br>
#define __DEC_EVAL_METHOD__ 2<br>
#define __ELF__ 1<br>
#define __FINITE_MATH_ONLY__ 0<br>
#define __FLT_DENORM_MIN__ 1.40129846e-45F<br>
#define __FLT_DIG__ 6<br>
#define __FLT_EPSILON__ 1.19209290e-7F<br>
#define __FLT_EVAL_METHOD__ 2<br>
#define __FLT_HAS_DENORM__ 1<br>
#define __FLT_HAS_INFINITY__ 1<br>
#define __FLT_HAS_QUIET_NAN__ 1<br>
#define __FLT_MANT_DIG__ 24<br>
#define __FLT_MAX_10_EXP__ 38<br>
#define __FLT_MAX_EXP__ 128<br>
#define __FLT_MAX__ 3.40282347e+38F<br>
#define __FLT_MIN_10_EXP__ (-37)<br>
#define __FLT_MIN_EXP__ (-125)<br>
#define __FLT_MIN__ 1.17549435e-38F<br>
#define __FLT_RADIX__ 2<br>
#define __FreeBSD__ 8<br>
#define __FreeBSD_cc_version 800001<br>
#define __GNUC_GNU_INLINE__ 1<br>
#define __GNUC_MINOR__ 2<br>
#define __GNUC_PATCHLEVEL__ 1<br>
#define __GNUC__ 4<br>
#define __GXX_ABI_VERSION 1002<br>
#define __INTMAX_MAX__ 9223372036854775807LL<br>
#define __INTMAX_TYPE__ long long int<br>
#define __INT_MAX__ 2147483647<br>
#define __KPRINTF_ATTRIBUTE__ 1<br>
#define __LDBL_DENORM_MIN__ 7.4653686412953080e-4948L<br>
#define __LDBL_DIG__ 15<br>
#define __LDBL_EPSILON__ 2.2204460492503131e-16L<br>
#define __LDBL_HAS_DENORM__ 1<br>
#define __LDBL_HAS_INFINITY__ 1<br>
#define __LDBL_HAS_QUIET_NAN__ 1<br>
#define __LDBL_MANT_DIG__ 53<br>
#define __LDBL_MAX_10_EXP__ 4932<br>
#define __LDBL_MAX_EXP__ 16384<br>
#define __LDBL_MAX__ 1.1897314953572316e+4932L<br>
#define __LDBL_MIN_10_EXP__ (-4931)<br>
#define __LDBL_MIN_EXP__ (-16381)<br>
#define __LDBL_MIN__ 3.3621031431120935e-4932L<br>
#define __LONG_LONG_MAX__ 9223372036854775807LL<br>
#define __LONG_MAX__ 2147483647L<br>
#define __NO_INLINE__ 1<br>
#define __PTRDIFF_TYPE__ int<br>
#define __REGISTER_PREFIX__<br>
#define __SCHAR_MAX__ 127<br>
#define __SHRT_MAX__ 32767<br>
#define __SIZE_TYPE__ unsigned int<br>
#define __STDC_HOSTED__ 1<br>
#define __STDC__ 1<br>
#define __UINTMAX_TYPE__ long long unsigned int<br>
#define __USER_LABEL_PREFIX__<br>
#define __VERSION__ "4.2.1 20070719  [FreeBSD]"<br>
#define __WCHAR_MAX__ 2147483647<br>
#define __WCHAR_TYPE__ int<br>
#define __WINT_TYPE__ int<br>
#define __i386 1<br>
#define __i386__ 1<br>
#define __i486 1<br>
#define __i486__ 1<br>
#define __unix 1<br>
#define __unix__ 1<br>
#define i386 1<br>
#define unix 1</pre>

## OpenBSD 4.8 (x86) ##
<pre>$ cpp -dM < /dev/null | sort<br>
#define __ANSI_COMPAT 1<br>
#define __CHAR_BIT__ 8<br>
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324<br>
#define __DBL_DIG__ 15<br>
#define __DBL_EPSILON__ 2.2204460492503131e-16<br>
#define __DBL_HAS_DENORM__ 1<br>
#define __DBL_HAS_INFINITY__ 1<br>
#define __DBL_HAS_QUIET_NAN__ 1<br>
#define __DBL_MANT_DIG__ 53<br>
#define __DBL_MAX_10_EXP__ 308<br>
#define __DBL_MAX_EXP__ 1024<br>
#define __DBL_MAX__ 1.7976931348623157e+308<br>
#define __DBL_MIN_10_EXP__ (-307)<br>
#define __DBL_MIN_EXP__ (-1021)<br>
#define __DBL_MIN__ 2.2250738585072014e-308<br>
#define __DEC128_DEN__ 0.000000000000000000000000000000001E-6143DL<br>
#define __DEC128_EPSILON__ 1E-33DL<br>
#define __DEC128_MANT_DIG__ 34<br>
#define __DEC128_MAX_EXP__ 6144<br>
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL<br>
#define __DEC128_MIN_EXP__ (-6143)<br>
#define __DEC128_MIN__ 1E-6143DL<br>
#define __DEC32_DEN__ 0.000001E-95DF<br>
#define __DEC32_EPSILON__ 1E-6DF<br>
#define __DEC32_MANT_DIG__ 7<br>
#define __DEC32_MAX_EXP__ 96<br>
#define __DEC32_MAX__ 9.999999E96DF<br>
#define __DEC32_MIN_EXP__ (-95)<br>
#define __DEC32_MIN__ 1E-95DF<br>
#define __DEC64_DEN__ 0.000000000000001E-383DD<br>
#define __DEC64_EPSILON__ 1E-15DD<br>
#define __DEC64_MANT_DIG__ 16<br>
#define __DEC64_MAX_EXP__ 384<br>
#define __DEC64_MAX__ 9.999999999999999E384DD<br>
#define __DEC64_MIN_EXP__ (-383)<br>
#define __DEC64_MIN__ 1E-383DD<br>
#define __DECIMAL_DIG__ 21<br>
#define __DEC_EVAL_METHOD__ 2<br>
#define __ELF__ 1<br>
#define __FINITE_MATH_ONLY__ 0<br>
#define __FLT_DENORM_MIN__ 1.40129846e-45F<br>
#define __FLT_DIG__ 6<br>
#define __FLT_EPSILON__ 1.19209290e-7F<br>
#define __FLT_EVAL_METHOD__ 2<br>
#define __FLT_HAS_DENORM__ 1<br>
#define __FLT_HAS_INFINITY__ 1<br>
#define __FLT_HAS_QUIET_NAN__ 1<br>
#define __FLT_MANT_DIG__ 24<br>
#define __FLT_MAX_10_EXP__ 38<br>
#define __FLT_MAX_EXP__ 128<br>
#define __FLT_MAX__ 3.40282347e+38F<br>
#define __FLT_MIN_10_EXP__ (-37)<br>
#define __FLT_MIN_EXP__ (-125)<br>
#define __FLT_MIN__ 1.17549435e-38F<br>
#define __FLT_RADIX__ 2<br>
#define __GNUC_GNU_INLINE__ 1<br>
#define __GNUC_MINOR__ 2<br>
#define __GNUC_PATCHLEVEL__ 1<br>
#define __GNUC__ 4<br>
#define __GXX_ABI_VERSION 1002<br>
#define __INTMAX_MAX__ 9223372036854775807LL<br>
#define __INTMAX_TYPE__ long long int<br>
#define __INT_MAX__ 2147483647<br>
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L<br>
#define __LDBL_DIG__ 18<br>
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L<br>
#define __LDBL_HAS_DENORM__ 1<br>
#define __LDBL_HAS_INFINITY__ 1<br>
#define __LDBL_HAS_QUIET_NAN__ 1<br>
#define __LDBL_MANT_DIG__ 64<br>
#define __LDBL_MAX_10_EXP__ 4932<br>
#define __LDBL_MAX_EXP__ 16384<br>
#define __LDBL_MAX__ 1.18973149535723176502e+4932L<br>
#define __LDBL_MIN_10_EXP__ (-4931)<br>
#define __LDBL_MIN_EXP__ (-16381)<br>
#define __LDBL_MIN__ 3.36210314311209350626e-4932L<br>
#define __LONG_LONG_MAX__ 9223372036854775807LL<br>
#define __LONG_MAX__ 2147483647L<br>
#define __NO_INLINE__ 1<br>
#define __OpenBSD__ 1<br>
#define __PTRDIFF_TYPE__ long int<br>
#define __REGISTER_PREFIX__<br>
#define __SCHAR_MAX__ 127<br>
#define __SHRT_MAX__ 32767<br>
#define __SIZE_TYPE__ long unsigned int<br>
#define __SSP__ 1<br>
#define __STDC_HOSTED__ 1<br>
#define __UINTMAX_TYPE__ long long unsigned int<br>
#define __USER_LABEL_PREFIX__<br>
#define __VERSION__ "4.2.1 20070719 "<br>
#define __WCHAR_MAX__ 2147483647<br>
#define __WCHAR_TYPE__ int<br>
#define __WINT_TYPE__ unsigned int<br>
#define __i386 1<br>
#define __i386__ 1<br>
#define __i486 1<br>
#define __i486__ 1<br>
#define __unix__ 1<br>
#define i386 1</pre>