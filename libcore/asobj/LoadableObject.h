// LoadableObject.h: abstraction of network-loadable AS object functions.
// 
//   Copyright (C) 2005, 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
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
//

#ifndef GNASH_LOADABLE_OBJECT_H
#define GNASH_LOADABLE_OBJECT_H

#include "movie_root.h"

namespace gnash {
    class as_object;
}

namespace gnash {

/// Register methods as native for use by XML_as and LoadVars_as
void registerLoadableNative(as_object& global);

/// Attach some common AS code for Loadable objects.
//
/// This implements built-in functions.
void attachLoadableInterface(as_object& where, int flags);

bool processLoad(movie_root::LoadCallbacks::value_type& v);

}

#endif
