/*
	Copyright (C) 2013 - 2016 CurlyMo

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "../../core/pilight.h"
#include "../operator.h"
#include "../../core/dso.h"
#include "eq.h"

static void operatorEqCallback(double a, double b, char **ret) {
	if(fabs(a-b) < EPSILON) {
		strcpy(*ret, "1");
	} else {
		strcpy(*ret, "0");
	}
}

#if !defined(MODULE) && !defined(_WIN32)
__attribute__((weak))
#endif
void operatorEqInit(void) {
	event_operator_register(&operator_eq, "==");
	operator_eq->callback_number = &operatorEqCallback;
}

#if defined(MODULE) && !defined(_WIN32)
void compatibility(struct module_t *module) {
	module->name = "==";
	module->version = "1.0";
	module->reqversion = "5.0";
	module->reqcommit = "87";
}

void init(void) {
	operatorEqInit();
}
#endif
