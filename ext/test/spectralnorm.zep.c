
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_fixedarray.h"


/**
 * SpectralNorm
 *
 * @see http://mathworld.wolfram.com/SpectralNorm.html
 */
ZEPHIR_INIT_CLASS(Test_SpectralNorm) {

	ZEPHIR_REGISTER_CLASS(Test, SpectralNorm, test, spectralnorm, test_spectralnorm_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_SpectralNorm, Ax) {

	zval *i, *j, *_0, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &i, &j);



	ZEPHIR_INIT_VAR(_0);
	zephir_add_function_ex(_0, i, j TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	zephir_add_function_ex(&_1, i, j TSRMLS_CC);
	RETURN_MM_DOUBLE(zephir_safe_div_long_double((double) 1, ((zephir_safe_div_long_long((zephir_get_numberval(_0) * (zephir_get_numberval(&_1) + 1)), 2 TSRMLS_CC) + zephir_get_numberval(i)) + (double) (1)) TSRMLS_CC));

}

PHP_METHOD(Test_SpectralNorm, Au) {

	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	zend_bool _0, _3;
	zval *n_param = NULL, *u, *v, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL;
	int n, t, i, j, _1, _2, _4, _5, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &n_param, &u, &v);

	n = zephir_get_intval(n_param);


	_2 = (n - 1);
	_1 = 0;
	_0 = 0;
	if (_1 <= _2) {
		while (1) {
			if (_0) {
				_1++;
				if (!(_1 <= _2)) {
					break;
				}
			} else {
				_0 = 1;
			}
			i = _1;
			t = 0;
			_5 = (n - 1);
			_4 = 0;
			_3 = 0;
			if (_4 <= _5) {
				while (1) {
					if (_3) {
						_4++;
						if (!(_4 <= _5)) {
							break;
						}
					} else {
						_3 = 1;
					}
					j = _4;
					ZEPHIR_INIT_NVAR(_7);
					ZVAL_LONG(_7, i);
					ZEPHIR_INIT_NVAR(_8);
					ZVAL_LONG(_8, j);
					ZEPHIR_CALL_METHOD(&_6, this_ptr, "ax", &_9, _7, _8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_7);
					ZVAL_LONG(_7, j);
					ZEPHIR_CALL_METHOD(&_10, u, "offsetget", &_11, _7);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_12);
					mul_function(_12, _6, _10 TSRMLS_CC);
					t += zephir_get_numberval(_12);
				}
			}
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, i);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, t);
			ZEPHIR_CALL_METHOD(NULL, v, "offsetset", &_13, _7, _8);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_SpectralNorm, Atu) {

	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	zend_bool _0, _3;
	zval *n_param = NULL, *u, *v, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL;
	int n, t, i, j, _1, _2, _4, _5, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &n_param, &u, &v);

	n = zephir_get_intval(n_param);


	_2 = (n - 1);
	_1 = 0;
	_0 = 0;
	if (_1 <= _2) {
		while (1) {
			if (_0) {
				_1++;
				if (!(_1 <= _2)) {
					break;
				}
			} else {
				_0 = 1;
			}
			i = _1;
			t = 0;
			_5 = (n - 1);
			_4 = 0;
			_3 = 0;
			if (_4 <= _5) {
				while (1) {
					if (_3) {
						_4++;
						if (!(_4 <= _5)) {
							break;
						}
					} else {
						_3 = 1;
					}
					j = _4;
					ZEPHIR_INIT_NVAR(_7);
					ZVAL_LONG(_7, j);
					ZEPHIR_INIT_NVAR(_8);
					ZVAL_LONG(_8, i);
					ZEPHIR_CALL_METHOD(&_6, this_ptr, "ax", &_9, _7, _8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_7);
					ZVAL_LONG(_7, j);
					ZEPHIR_CALL_METHOD(&_10, u, "offsetget", &_11, _7);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_12);
					mul_function(_12, _6, _10 TSRMLS_CC);
					t += zephir_get_numberval(_12);
				}
			}
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, i);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, t);
			ZEPHIR_CALL_METHOD(NULL, v, "offsetset", &_13, _7, _8);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_SpectralNorm, AtAu) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *n, *u, *v, *w;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &n, &u, &v, &w);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "au", &_0, n, u, w);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "atu", &_1, n, w, v);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_SpectralNorm, process) {

	zephir_fcall_cache_entry *_6 = NULL, *_15 = NULL;
	zend_bool _2, _7, _11;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_20 = NULL;
	zval *n_param = NULL, *u, *v, *w, *_0 = NULL, *_5 = NULL, *_14 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, _19;
	int n, i, vv = 0, vBv = 0, ZEPHIR_LAST_CALL_STATUS, _3, _4, _8, _9, _12, _13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &n_param);

	n = zephir_get_intval(n_param);


	ZEPHIR_INIT_VAR(u);
	object_init_ex(u, spl_ce_SplFixedArray);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, n);
	ZEPHIR_CALL_METHOD(NULL, u, "__construct", &_1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(v);
	object_init_ex(v, spl_ce_SplFixedArray);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, n);
	ZEPHIR_CALL_METHOD(NULL, v, "__construct", &_1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(w);
	object_init_ex(w, spl_ce_SplFixedArray);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, n);
	ZEPHIR_CALL_METHOD(NULL, w, "__construct", &_1, _0);
	zephir_check_call_status();
	_4 = (n - 1);
	_3 = 0;
	_2 = 0;
	if (_3 <= _4) {
		while (1) {
			if (_2) {
				_3++;
				if (!(_3 <= _4)) {
					break;
				}
			} else {
				_2 = 1;
			}
			i = _3;
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, i);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_LONG(_5, 1);
			ZEPHIR_CALL_METHOD(NULL, u, "offsetset", &_6, _0, _5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, i);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_LONG(_5, 1);
			ZEPHIR_CALL_METHOD(NULL, v, "offsetset", &_6, _0, _5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, i);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_LONG(_5, 1);
			ZEPHIR_CALL_METHOD(NULL, w, "offsetset", &_6, _0, _5);
			zephir_check_call_status();
		}
	}
	_9 = 9;
	_8 = 0;
	_7 = 0;
	if (_8 <= _9) {
		while (1) {
			if (_7) {
				_8++;
				if (!(_8 <= _9)) {
					break;
				}
			} else {
				_7 = 1;
			}
			i = _8;
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, n);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "atau", &_10, _0, u, v, w);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, n);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "atau", &_10, _0, v, u, w);
			zephir_check_call_status();
		}
	}
	_13 = (n - 1);
	_12 = 0;
	_11 = 0;
	if (_12 <= _13) {
		while (1) {
			if (_11) {
				_12++;
				if (!(_12 <= _13)) {
					break;
				}
			} else {
				_11 = 1;
			}
			i = _12;
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, i);
			ZEPHIR_CALL_METHOD(&_14, u, "offsetget", &_15, _0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, i);
			ZEPHIR_CALL_METHOD(&_16, v, "offsetget", &_15, _0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_17);
			mul_function(_17, _14, _16 TSRMLS_CC);
			vBv += zephir_get_numberval(_17);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, i);
			ZEPHIR_CALL_METHOD(&_14, v, "offsetget", &_15, _0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, i);
			ZEPHIR_CALL_METHOD(&_16, v, "offsetget", &_15, _0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_18);
			mul_function(_18, _14, _16 TSRMLS_CC);
			vv += zephir_get_numberval(_18);
		}
	}
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_DOUBLE(&_19, zephir_safe_div_long_long(vBv, vv TSRMLS_CC));
	ZEPHIR_RETURN_CALL_FUNCTION("sqrt", &_20, &_19);
	zephir_check_call_status();
	RETURN_MM();

}

