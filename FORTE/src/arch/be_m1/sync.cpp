/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "sync.h"

CVXWorksSyncObject::CVXWorksSyncObject(){
  m_oSemBinary = semMCreate(SEM_Q_PRIORITY);
}

CVXWorksSyncObject::~CVXWorksSyncObject(){
  semDelete (m_oSemBinary);
}
