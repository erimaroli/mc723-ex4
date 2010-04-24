/**
 * @file      roteador.cpp
 * @author    Erivelton Oliveira
 *
 * @version   0.1
 * @date      26/02/10
 *
 * @brief     Implementa roteador.
 *
 * @attention Copyright (C) 2002-2005 --- The ArchC Team
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *
 */

//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "roteador.h"

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::roteador;

/// Constructor
roteador::roteador( sc_module_name module_name) :
  sc_module( module_name ),
  target_export("iport"),
  porta_mestre("porta_mestre", 5242880U) 
{
    /// Binds target_export to the memory
    target_export( *this );

}

/// Destructor
roteador::~roteador() {

}




