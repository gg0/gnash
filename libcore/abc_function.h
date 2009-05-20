// 
//   Copyright (C) 2005, 2006, 2007, 2008 Free Software Foundation, Inc.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef GNASH_ABC_FUNCTION_H
#define GNASH_ABC_FUNCTION_H

#ifdef HAVE_CONFIG_H
#include "gnashconfig.h" // GNASH_USE_GC
#endif

#include "as_function.h"
#include "as_value.h"
#include "CodeStream.h"
#include "asClass.h"
#include "SafeStack.h"
#include "as_object.h"
#include "as_environment.h"
#include "asMethod.h"

namespace gnash {

class Machine;

/// ABC-defined Function 
class abc_function : public as_function
{

public:
	abc_function(asMethod *methodInfo, Machine* mMachine);

	as_value operator()(const fn_call& fn);

	CodeStream* getCodeStream(){ return mMethodInfo->getBody();}

	boost::uint32_t getMaxRegisters(){ return mMethodInfo->getMaxRegisters(); }

    as_environment::ScopeStack* scopeStack() { return _scopeStack; }

    void setScopeStack(as_environment::ScopeStack* stack) {
        _scopeStack = stack;
    }

private:

    asMethod *mMethodInfo;

    Machine* mMachine;

	as_environment::ScopeStack* _scopeStack;

};


} // end of gnash namespace

// __GNASH_ABC_FUNCTION_H__
#endif