// 
//   Copyright (C) 2005, 2006 Free Software Foundation, Inc.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

// Linking Gnash statically or dynamically with other modules is making a
// combined work based on Gnash. Thus, the terms and conditions of the GNU
// General Public License cover the whole combination.
//
// As a special exception, the copyright holders of Gnash give you
// permission to combine Gnash with free software programs or libraries
// that are released under the GNU LGPL and with code included in any
// release of Talkback distributed by the Mozilla Foundation. You may
// copy and distribute such a system following the terms of the GNU GPL
// for all but the LGPL-covered parts and Talkback, and following the
// LGPL for the LGPL-covered parts.
//
// Note that people who make modified versions of Gnash are not obligated
// to grant this special exception for their modified versions; it is their
// choice whether to do so. The GNU General Public License gives permission
// to release a modified version without this exception; this exception
// also makes it possible to release a modified version which carries
// forward this exception.
// 
//

/* $Id: rect.h,v 1.2 2006/10/18 14:02:09 strk Exp $ */

#ifndef GNASH_RECT_H
#define GNASH_RECT_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "tu_config.h"

// Forward decl
namespace gnash {
	class matrix;
	class stream;
	class point; // is a forward declaration enough for a return type ?
}

namespace gnash {

/// Rectangle class
//
/// used by render handler (?)
///
class DSOLOCAL rect
{
public:

	// TODO: make private 
	float	m_x_min, m_x_max, m_y_min, m_y_max;

public:

	/// construct a NULL rectangle
	rect();

	/// returns true if this is the NULL rectangle
	bool is_null() const;

	/// set the rectangle to the NULL value
	void set_null();

	void	read(stream* in);
	void	print() const;
	bool	point_test(float x, float y) const;

	/// Expand this rectangle to enclose the given point.
	void	expand_to_point(float x, float y);

	/// Set ourself to bound the given point
	void	enclose_point(float x, float y);

	float	width() const
	{
		if ( is_null() ) return 0;
		return m_x_max-m_x_min;
	}

	float	height() const
	{
		if ( is_null() ) return 0;
		return m_y_max-m_y_min;
	}

	/// Get min X ordinate.
	//
	/// Don't call this against a null rectangle
	///
	float	get_x_min() const
	{
		assert( ! is_null() );
		return m_x_min;
	}

	/// Get max X ordinate.
	//
	/// Don't call this against a null rectangle
	///
	float	get_x_max() const
	{
		assert( ! is_null() );
		return m_x_max;
	}

	/// Get min Y ordinate.
	//
	/// Don't call this against a null rectangle
	///
	float	get_y_min() const
	{
		assert( ! is_null() );
		return m_y_min;
	}

	/// Get max Y ordinate.
	//
	/// Don't call this against a null rectangle
	///
	float	get_y_max() const
	{
		assert( ! is_null() );
		return m_y_max;
	}

	/// TODO: deprecate this ?
	point	get_corner(int i) const;

	/// Set ourself to bound a rectangle that has been transformed
	/// by m.  This is an axial bound of an oriented (and/or
	/// sheared, scaled, etc) box.
	void	enclose_transformed_rect(const matrix& m, const rect& r);
	
	/// Same as enclose_transformed_rect but expanding the current rect instead
	/// of replacing it.
	void	expand_to_transformed_rect(const matrix& m, const rect& r);
	
	/// Makes union of the given and the current rect
	DSOEXPORT void  expand_to_rect(const rect& r);

	void	set_lerp(const rect& a, const rect& b, float t);
};


}	// namespace gnash

#endif // GNASH_RECT_H


// Local Variables:
// mode: C++
// indent-tabs-mode: t
// End:
