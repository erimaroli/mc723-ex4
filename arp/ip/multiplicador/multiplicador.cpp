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

#include "multiplicador.h"

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::multiplicador;

/// Constructor
multiplicador::multiplicador( sc_module_name module_name) :
  sc_module( module_name ),
  target_export("iport")
{
    /// Binds target_export to the memory
    target_export( *this );
    
    *((uint32_t *)&l) = (uint32_t)0;

}

/// Destructor
multiplicador::~multiplicador() {

}

/** Internal Write lock
  * @param d id the data being write
  * @returns A TLM response packet with SUCCESS
*/
ac_tlm_rsp_status multiplicador::writel(const uint32_t &d, const uint32_t &a )
{
  
  if(*((uint32_t *) &a) == 0){
    *((uint32_t *)&l) = *((uint32_t *) &d);
    return SUCCESS;
  } else {
    return ERROR;
  }
}

/** Internal Read Lock
  * @param d id the data that will be read
  * @returns A TLM response packet with SUCCESS and a modified d
*/
ac_tlm_rsp_status multiplicador::readl(uint32_t &d, const uint32_t &a )
{
  if(*((uint32_t *) &a) == 0){
    *((uint32_t *) &d) = *((uint32_t *)&l);
    *((uint32_t *)&l) = (uint32_t)1;
      return SUCCESS;
  } else {
    return ERROR;
  }
}




